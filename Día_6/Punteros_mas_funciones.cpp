#include <iostream>

void mostararr(int *punt, int tam);
void duplicar(int *punt, int tam);

int main() {
    int arr[5] = {5,2,7,4,8};
    int tam = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array original: \n";
    mostararr(arr, tam);
    std::cout << "\nArray duplicado: \n";
    duplicar(arr, tam);
    mostararr(arr, tam);

    return 0;
}

void mostararr(int *punt, int tam){
    for(int i = 0; i < tam ; i ++){
        std::cout << *(punt + i) <<" ";
    }
}

void duplicar(int *punt, int tam){
    for(int i = 0; i < tam; i++){
        *(punt + i) *= 2;
    }
}