#include <iostream>
#include <vector>

void promedio_funcion(const std::vector<int> &arreglo, float &promedio);
void cantidad_menores_mayores(const std::vector<int> &arreglo, int &menores, int &mayores, const float &promedio);
int main(){
    std::vector<int> arreglo = {4, 8, 5, 1, 8, 9};
    float promedio = 0;
    promedio_funcion(arreglo, promedio);
    std::cout << "Tu promedio es de: " << promedio << '\n';
    int menores = 0;
    int mayores = 0;
    cantidad_menores_mayores(arreglo, menores, mayores, promedio);
    std::cout << "Hay " << menores << " numeros menores que el promedio\n"
              << "Hay " << mayores << " numeros mayores que el promedio\n";
}

void cantidad_menores_mayores(const std::vector<int> &arreglo, int &menores, int &mayores, const float &promedio){
    for(int i = 0; i < (int)arreglo.size(); i++){
        if(promedio > arreglo.at(i)) menores++;
        else if(promedio < arreglo.at(i)) mayores++;
    }
}

void promedio_funcion(const std::vector<int> &arreglo, float &promedio){
    int suma = 0;
    for(int i = 0; i < (int)arreglo.size(); i++){
        suma += arreglo.at(i);
    }
    promedio = (float)suma / arreglo.size();
}