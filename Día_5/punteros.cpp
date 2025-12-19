
#include <iostream>

int main() {
    int x = 10;
    int *p = &x;

    std::cout << "Valor de x: " << x << std::endl;

    *p = 50;

    std::cout << "Nuevo valor de x mediante puntero: " << x <<std::endl;

    return 0;
}