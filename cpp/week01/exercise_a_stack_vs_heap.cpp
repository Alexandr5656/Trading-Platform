#include <iostream>

// Exercise A — stack vs. heap, lifetime.
// Goal: create one object on the stack and one on the heap, print both
// addresses, and observe what happens to each at end of scope / if you
// forget to delete. Explain what you observe in NOTES.md, not here.

void runExerciseA() {
    // TODO: declare a local object on the stack (e.g. an int or small struct)
    //       and print its address.

    int b =2;
    // TODO: allocate an equivalent object on the heap with `new`, print its
    //       address, and `delete` it before the function returns.
    int* a = new int(1);
    std::cout << a;
    std::cout<< '\n';
    std::cout << &b;
    // TODO (optional but recommended): comment out the `delete` once you've
    //       seen the correct behavior, and note in NOTES.md what changes
    //       (hint: nothing changes here — that's the point; explain why).
    delete a;

}
