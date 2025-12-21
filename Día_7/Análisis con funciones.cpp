#include <iostream>

float promedio_f(int* punt, int tam);
void menores_mayores(int* punt, int &mayores, int &menores, int tam, float promedio);
void imprimir(int* punt, int &mayores, int &menores, int tam, float promedio);

int main() {
    int arr[5] = {5, 3, 7, 8, 10};
    int tam = sizeof(arr) / sizeof(arr[0]);
    int menores = 0, mayores = 0;

    float promedio = promedio_f(arr, tam);
    menores_mayores(arr, mayores, menores, tam, promedio);
    imprimir(arr, mayores, menores, tam, promedio);
    return 0;
}

float promedio_f(int* punt, int tam){
    int suma = 0;
    
    for (int i = 0; i < tam; i++){
        suma += *(punt + i);
    }
    return (float)suma / tam;
}

void menores_mayores(int* punt, int &mayores, int &menores, int tam, float promedio){
    for (int i = 0; i < tam; i++){
        if(promedio < *(punt + i)) mayores++;
        else if(promedio > *(punt + i)) menores++;
    }
}

void imprimir(int *arr, int &mayores, int &menores, int tam, float promedio){
    std::cout <<"Arreglo:\n";
    for (int i = 0; i < tam; i++){
        std::cout << *(arr + i) << " ";
    }
    std::cout << "\nPromedio de esos numeros:\n";
    std::cout << promedio;
    std::cout << "\nNumeros mayores que el promedio:\n";
    std::cout << mayores;
    std::cout <<"\nNumeros menores que el promedio:\n";
    std::cout << menores;
}