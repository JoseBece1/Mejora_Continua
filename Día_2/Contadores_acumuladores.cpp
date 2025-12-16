#include <iostream>

int main(){
    int numero = 0;
    int suma = 0;

    std::cout << "Dime hasta que numero quieres sumar:\n";
    std::cin >> numero;

    if(std::cin.fail() || numero < 0){
        std::cout << "Entrada invalida\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    
    for(int i = 0; i <= numero; i++){
        suma += i;
    }

    std::cout << "La suma del 1 hasta el numero " 
              << numero <<" es: " << suma << "\n";

    return 0;
}