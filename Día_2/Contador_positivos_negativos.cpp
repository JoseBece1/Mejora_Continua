#include <iostream>

int main (){
    int cont_posi = 0;
    int cont_nega = 0;
    int numeros[5] = {0};

    std::cout << "Dame los 5 numeros a evaluar...\n";

    for(int i = 0; i < 5; i++){
        std::cout << "Dame el numero " << i + 1 << '\n';
        std::cin >> numeros[i];

        if(std::cin.fail()){
            std::cout << "Entrada no valida\n";
            i--;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        
        if(numeros[i] > 0) cont_posi ++;
        else cont_nega ++;
    }

    std::cout << "Numeros positivos: " << cont_posi << '\n';
    std::cout << "Numeros negativos: " << cont_nega << '\n';

    return 0;
}