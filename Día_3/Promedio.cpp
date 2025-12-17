#include <iostream>

int main() {
    int numeros [5] = {0};
    float promedio = 0;
    int cont_menor = 0;
    int cont_mayor = 0;
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
        promedio += numeros[i];
    }
    
    promedio /= 5;

    for(int i = 0; i < 5; i++){
        if(promedio > numeros[i]) cont_menor++;
        if(promedio < numeros[i]) cont_mayor++;
    }
    
    std::cout <<"El promedio es: " << promedio << '\n'
              << "Hay: " << cont_mayor <<" mayores o iguales que el promedio\n"
              << "Hay: " << cont_menor <<" menores que el promedio\n";
    return 0;
}