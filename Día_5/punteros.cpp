
#include <iostream>

void duplicar(int *p);

int main() {
    int x = 10;
    
    duplicar(&x);
    std::cout << "Valor de x duplicado: " << x;


    return 0;
}

void duplicar(int *p) {
    *p *= 2;
}