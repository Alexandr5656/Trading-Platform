# Week 2 Notes — RAII, Rule of Five/Zero, exception safety

## Remedial retention check (from memory, before looking anything up)

(a) What does `const int*` promise vs. `int* const`?
`int* const` is a constant of the pointer to a int
`const int*` is a int pointer where the value its pointing to is const

(b) Why is `delete` only valid on a pointer that came from `new`?
cause the stuff that isnt created from new isnt on the heap and gets auto cleaned while heap stuff needs an explicit cleaning

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
I enabled the rule of five as its creating something on the heap so i need to clean up and handle all copies as well

## Exception safety

Which guarantee does this class provide — basic, strong, or nothrow — and
why is that true of the code as written?
TODO:
provides a no throw
