#include <iostream>

float promedio_fun(int *arr, int tam);
void datos_arreglo(int *arr, int tam);
void mayor_menor(int *arr, int tam, float promedio, int &mayor, int &menor);
void errores();

int main() {
    int tam;
    int mayor = 0;
    int menor = 0;
    do{
        std::cout << "Dime el tamaño del arreglo:\n";
        std::cin >> tam;

        if(std::cin.fail()) errores();
        else break;   

    }while(true);

    int* arr = new int[tam];

    datos_arreglo(arr, tam);
    float promedio = promedio_fun(arr, tam);

    std::cout << "Su promedio de los numeros es:\n"
              << promedio ;

    mayor_menor(arr, tam, promedio, mayor, menor);

    std::cout << "\nHay: " << menor << " numeros menores que el promedio\n"
              << "\nHay: " << mayor << " numeros mayores que el promedio\n";

    delete[] arr;
    return 0;
}

void datos_arreglo(int *arr, int tam){
    std::cout << "Escribe los " << tam << "datos:";
    for(int i = 0; i < tam; i++){
        std::cout << "\nDato " << i + 1 << ":";
        std::cin >> arr[i];

        if(std::cin.fail()){
            errores();
            i--;
        }
    }
}

float promedio_fun(int *arr, int tam){
    int suma = 0;
    for(int i = 0; i < tam; i ++){
        suma += arr[i];
    }
    return (float)suma / tam;
}

void mayor_menor(int *arr, int tam, float promedio, int &mayor, int &menor){
    for(int i = 0; i < tam; i ++){
        if(promedio < arr[i]) mayor++;
        else if(promedio > arr[i]) menor++;
    }
}

void errores(){
    std::cout << "Entrada invalida...\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}