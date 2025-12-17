#include <iostream>

int main(){
    int numeros[5] = {0};
    int mayor = -999999;
    int menor = 999999;
    
    std::cout << "Dame los 5 numeros:\n";

    for(int i = 0; i < 5; i++){
        std::cout << "Dame el numero " << i + 1 << ":\n";
        std::cin >> numeros[i];

        if(std::cin.fail()){
            std::cout << "Entrada invalida\n";
            i--;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        if(mayor < numeros[i]) mayor = numeros[i];
        if(menor > numeros[i]) menor = numeros[i];
    }

    std::cout << "Tu numero mayor es: " << mayor << '\n'
              << "Tu numero menor es: " << menor << '\n';

    return 0;
}