# Week 1 Notes — stack vs. heap, const-correctness

## Exercise A — stack vs. heap

TODO: what did you observe about the two addresses? What happens to the
stack object vs. the heap object when the function returns? What would
happen if the `delete` were forgotten?


Only b gets cleaned up cause its on stack a has to manually be cleaned up

## Exercise B — const-correctness

TODO: for each of the four signatures, explain in your own words what it
promises the caller (what it can/can't do to the argument, and whether the
pointer itself vs. what it points to is fixed).
const int&: the int wont change
int*, the ints pointer is passed and can change
const int*, the int cant be changed
const int* const the int or address cant change