#include "error.h"

void error(){
    std::cout << "Error de entrada\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}