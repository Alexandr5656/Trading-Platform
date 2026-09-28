# Week 2 Notes — RAII, Rule of Five/Zero, exception safety

## Remedial retention check (from memory, before looking anything up)

(a) What does `const int*` promise vs. `int* const`?
`int* const` is a constant of the pointer to a int
`const int*` is a int pointer where the value its pointing to is const

(b) Why is `delete` only valid on a pointer that came from `new`?
`new` and `delete` are a matched pair with the heap allocator, which tracks
bookkeeping like the allocated block's size (and, for `new[]`, the element
count) keyed by the address it handed back. A stack (or global, or
already-freed) address was never registered with that allocator, so
`delete`-ing it isn't "cleaning up the wrong thing" — the allocator has no
record of that address at all, which is undefined behavior, not a no-op.

## Resource-owning class

What resource does `ResourceOwner` own, and where are the acquire/release points?
TODO:
It owned a raw int buffer being just an int array. On acquire it creates the buffer on release it delete the buffer through it pointer

## Rule of Five vs. Rule of Zero

Which one does this class need, and why? (Not "a function shouldn't do more
than five things" — that's unrelated. The actual rule: if you write any one
of the five special member functions, you generally need all five; if you
don't manage a resource directly, prefer Rule of Zero and let RAII-wrapping
members do the work.)
TODO:
This class needs the Rule of Five, not Rule of Zero, because it directly
owns a raw resource (`rawBuff`, a heap-allocated `int*`) instead of
delegating ownership to an RAII-wrapping member. I hit this concretely
before fixing it: with only a destructor written, the compiler-generated
copy constructor does a shallow (member-wise) copy — two `ResourceOwner`s
would end up pointing at the same `rawBuff`, and when both went out of
scope, both destructors would call `delete[]` on the same pointer, a
double-free. Writing the destructor is what triggers the need for the
other four: copy constructor and copy assignment do a deep copy (allocate
a new buffer, copy the contents) so each object owns its own memory; move
constructor and move assignment steal the pointer and null out the
source, so ownership transfers without copying or double-freeing.

## Exception safety

Which guarantee does this class provide — basic, strong, or nothrow — and
why is that true of the code as written?
TODO:
Not a single guarantee for the whole class — it differs by operation:

- **Constructor and copy constructor:** `new int[...]` can throw
  `std::bad_alloc`. If it does, no `ResourceOwner` was ever fully
  constructed and no resource was leaked, but these aren't `noexcept`.
- **Move constructor and move assignment:** marked `noexcept` in the
  header, and correctly so — they only swap pointers/ints, no allocation,
  so they can't throw. This is the **nothrow** guarantee.
- **Copy assignment (`operator=`):** allocates the new buffer and copies
  into it *before* touching `this`'s existing state (`rawBuff`,
  `buffLength` aren't modified until after the new buffer is ready). If
  `new`/`std::copy` throws partway through, `*this` is left completely
  unchanged — still valid, still holding its original data. That's the
  **strong** guarantee.
- **Destructor:** `delete[]` doesn't throw, so it's implicitly nothrow —
  required for RAII to work safely during stack unwinding anyway.
