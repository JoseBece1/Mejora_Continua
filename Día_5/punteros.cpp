
#include <iostream>

int main() {
    int x = 10;
    int *p = &x;

    std::cout << "Valor de x: " << x << std::endl;
    std::cout << "Direccion de x: " << &x << std::endl;
    std::cout << "Valor en el puntero: " << p << std::endl; 
    std::cout << "Valor a que apunta el puntero: " << *p <<std::endl;
    
    return 0;
}