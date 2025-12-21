#include <iostream>

void imprimir(int* punt, int tam);
void duplicar(int* punt, int tam);

int main() {
    int arr[5] = {5, 6, 6, 2, 7};
    int tam = sizeof(arr)/ sizeof(arr[0]);

    std::cout << "Arreglo:\n";
    imprimir(arr, tam); 
    duplicar(arr, tam);

    std::cout << "\n\nArreglo duplicado:\n";
    imprimir(arr, tam);
    return 0;
}

void imprimir(int* punt, int tam){
    for (int i = 0; i < tam; i++){
        std::cout << *(punt + i) << " ";
    }
    
}

void duplicar(int* punt, int tam){
    for (int i = 0; i < tam; i++){
        *(punt + i) *= 2;
    }
}