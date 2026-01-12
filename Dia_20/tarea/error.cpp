#include "error.h"
#include <iostream>
#include <limits>

void error(){
    
    std::cout << "Entrada invalida\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}