#include <iostream>

void leerDatos(int num[], int tam);
float calcularPromedio(int num[], int tam);
void contarMayoresMenores(int num[], int tam, float promedio);

int main() {
    int arreglo[5] = {0};
    int tam = sizeof(arreglo) / sizeof(arreglo[0]);
    leerDatos(arreglo, tam);
    float promedio = calcularPromedio(arreglo, tam);
    contarMayoresMenores(arreglo, tam, promedio);

    return 0;
}

void leerDatos(int num[], int tam){
    std::cout << "Hola, agrega tus numeros:\n";

    for(int i = 0; i < tam; i++){
        std::cout << "Dame el numero " << i + 1 <<": \n";
        std::cin >> num[i];
        
        if(std::cin.fail()){
            std::cout << "Entrada no valida \n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            i--;
        }   
    }
}

float calcularPromedio(int num[], int tam){
    int suma = 0;
    float promedio = 0.0;

    for(int i = 0; i < tam; i++){
        suma += num[i]; 
    }
    promedio = suma/tam;

    std::cout << "Promedio:" << promedio << '\n';
    return promedio;
}

void contarMayoresMenores(int num[], int tam, float promedio){
    int menor = 0;
    int mayor = 0;

    for(int i = 0; i < tam; i++){
        if(promedio > num[i]) menor++;
        else if(promedio < num[i]) mayor++;
    }

    std::cout << "Tu numero mayor es: " << mayor << '\n'
              << "Tu numero menor es: " << menor << '\n';
}