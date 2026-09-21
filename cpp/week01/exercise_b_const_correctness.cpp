#include <iostream>

// Exercise B — const-correctness and pointer vs. reference.
// Write one function per signature below. Each should do something small
// but observable (e.g. print the value it received). In NOTES.md, explain
// in your own words what each signature promises the caller.

void takesConstRef(const int& value){
    
    std::cout<<value<< std::endl; 
}
void takesPointer(int* value){
    *value = *value + 2;
    std::cout<<*value<< std::endl; 
}


void takesConstPointer(const int* value){
    std::cout<<*value<< std::endl; 
}
void takesConstPointerConst(const int* const value){
    std::cout<<*value<< std::endl; 
}

void runExerciseB() {
    int x = 42;
    const int a = x;
    takesConstRef(x);
    takesPointer(&x);
    takesConstPointer(&x);
    takesConstPointerConst(&a);
    // TODO: call each of the four functions above with `x`, using whatever
    //       combination of value/address-of is correct for each signature.
}
