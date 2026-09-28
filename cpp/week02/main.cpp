#include "resource_owner.h"
#include <iostream>
#include <utility> // For std::move

int main() {
    std::cout << "--- [Scenario 1: Heap Allocation] ---\n";
    // Manual pointer lifetime allocation
    ResourceOwner* RO = new ResourceOwner(10);
    delete RO; // Triggers manual destruction output

    std::cout << "\n--- [Scenario 2: Automatic RAII Stack Scopes] ---\n";
    {
        std::cout << " Entering Local Scope...\n";
        ResourceOwner stackObj(5); 
        std::cout << " Exiting Local Scope...\n";
    } // <-- stackObj goes out of scope here. Destructor triggers AUTOMATICALLY!

    std::cout << "\n--- [Scenario 3: Rule of Five Copy Semantics] ---\n";
    {
        ResourceOwner original(8);
        std::cout << " Deep-copying original into copyObj...\n";
        ResourceOwner copyObj = original; // Triggers Copy Constructor
    } // Both exit scope safely without crashing (No double-free!)

    std::cout << "\n--- [Scenario 4: Rule of Five Move Semantics] ---\n";
    {
        ResourceOwner source(12);
        std::cout << " Moving source into target...\n";
        ResourceOwner target = std::move(source); // Triggers Move Constructor
    } // Exits scope cleanly

    return 0;
}
