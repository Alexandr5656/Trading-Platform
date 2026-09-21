#include <iostream>

void runExerciseA();
void runExerciseB();

int main() {
    std::cout << "=== Exercise A: stack vs heap ===\n";
    runExerciseA();

    std::cout << "\n=== Exercise B: const-correctness ===\n";
    runExerciseB();

    return 0;
}
