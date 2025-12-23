#include <iostream>

void datos_arreglo(int *arr, int tam);
float promedio_fun(int *arr, int tam);

int main() {
    int tam;

    do{
        std::cout << "Dime el tamaño del arreglo:\n";
        std::cin >> tam;

        if(std::cin.fail()){
            std::cout << "Entrada invalida...\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        else break;   

    }while(true);

    int* arr = new int[tam];

    datos_arreglo(arr, tam);
    float promedio = promedio_fun(arr, tam);

    std::cout << "Su promedio de los numeros es:\n"
              << promedio ;

    delete[] arr;
    return 0;
}

void datos_arreglo(int *arr, int tam){
    std::cout << "Escribe los " << tam << "datos:";
    for(int i = 0; i < tam; i++){
        std::cout << "\nDato " << i + 1 << ":";
        std::cin >> arr[i];
    }
}

float promedio_fun(int *arr, int tam){
    int suma = 0;
    for(int i = 0; i < tam; i ++){
        suma += arr[i];
    }
    return (float)suma / tam;
}