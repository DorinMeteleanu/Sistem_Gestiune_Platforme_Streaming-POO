#include <iostream>
#include "meniu.h"

int main() {
    std::cout << "Se incarca sistemul...\n";

    Meniu::afisareStatusPlatforma();

    Meniu platforma;

    platforma.rulareMeniu();

  
    std::cout << "\nProgram incheiat cu succes.\n";
    return 0;
}