#include <iostream>
#include <vector>
#include <algorithm>

void datos(std::vector<int> &array, int tam);
void errores();
float promedio(const std::vector<int> &array);
void encontrar_menores_mayores(const std::vector<int> &array , int &menores, int &mayores);
void imprimir_array(const std::vector<int> &array);

int main() {
    std::vector<int> array;
    int tam = 0;
    do{
        std::cout << "Dame el tamaño del array:\n";
        std::cin >> tam;
        if(std::cin.fail()){errores(); continue;}
        
        else if(tam <= 0) std::cout << "Tamano invalido...\n";       
    }while(tam <= 0);

    datos(array, tam);
    float promedio_var = promedio(array);

    std::sort(array.begin(), array.end());

    if(tam % 2 == 0){
        std::cout << "El promedio de los dos numeros del medio es: " << promedio_var << std::endl;
    }
    else{
        std::cout << "El promedio es de: " << promedio_var << std::endl;
    }
    int menores = 0;
    int mayores = 0;

    encontrar_menores_mayores(array, menores, mayores);

    std::cout << "El numero menor es " << menores << '\n'
              << "El numero mayor es " << mayores << '\n';
    imprimir_array(array);
    return 0;

}

void datos(std::vector<int> &array, int tam){
    for(int i = 0; i < tam; i++){
        int num = 0;
        std::cout << "Dame los datos del numero " << i + 1
                  <<": \n";  
        std::cin >> num;
        if(std::cin.fail()){
            errores();
            i--;
            continue;
        }
        array.push_back(num);
    }
}

float promedio(const std::vector<int> &array){
    int suma = 0;

    if(array.size() % 2 == 0){
        int medio = (array.size() / 2) - 1;
        return (float)(array.at(medio) + array.at(medio + 1)) / 2;
    }

    for(int x : array){
        suma += x;
    }
    
    return (float)suma / (float)array.size();

}

void encontrar_menores_mayores(const std::vector<int> &array , int &menores, int &mayores){
    mayores = array.at(0);
    menores = array.at(0);

    for(int x : array){
        if(x > mayores) mayores = x;
        if(x < menores) menores = x;
    }
}

void errores(){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Datos invalidos...\n";
}

void imprimir_array(const std::vector<int> &array){
    std::cout << "Array:\n";
    for(int x : array){
        std::cout << x << " ";
    }
    std::cout << '\n';
}