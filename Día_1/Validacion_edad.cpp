#include <iostream>

int main(){
    int edad = 0;

    std::cout << "Dime tu edad:\n";
    std::cin >> edad;

    if(std::cin.fail()) std::cout << "Entrada invalida";

    if(edad < 0) std::cout << "Edad invalida\n";
    else if (edad < 18) std::cout << "Menor de edad\n";
    else std::cout << "Mayor de edad\n";    

    return 0;
}