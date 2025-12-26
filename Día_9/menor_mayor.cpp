#include <iostream>
#include <vector>

void ingreso_valores(std::vector<int> &arreglo, int tam);
float promedio(const std::vector<int>& arreglo);
void contador_mayores_menores(const std::vector<int> arreglo, float promedio, int &menor, int &mayor);
void errores();

int main() {
    std::vector <int> arreglo;
    int tam = 0;
    int mayor = 0;
    int menor = 0;
    do{
        std::cout << "Cual es el tamaño del arreglo:\n";
        std::cin >> tam;
        if(std::cin.fail()) {errores(); continue;}
        if(tam <= 0) std::cout << "Tamaño no valido...\n";
    } while(tam <= 0);

    ingreso_valores(arreglo, tam);
    float promedio_var = promedio(arreglo);

    std::cout << "El promedio de los numeros es: " << promedio_var << std::endl;

    contador_mayores_menores(arreglo, promedio_var, menor, mayor);

    std::cout <<"Hay " << menor <<" numeros menores que el promedio\n"
              <<"Hay " << mayor <<" numeros mayores que el promedio\n";

    return 0;
}

void ingreso_valores(std::vector<int> &arreglo, int tam){
    int num;

    for (int i = 0; i < tam; i++){
        std::cout << "Dame el numero " << i + 1 << ":\n";
        std::cin >> num;
        if(std::cin.fail()){
            errores();
            i--;
            continue;
        }
        arreglo.push_back(num);    
    }
}

float promedio(const std::vector<int>& arreglo){
    int suma = 0;
    for(int i = 0; i < (int)arreglo.size(); i++){
        suma += arreglo.at(i);
    }
    return float(suma) / arreglo.size();
}

void contador_mayores_menores(const std::vector<int> arreglo, float promedio, int &menor, int &mayor){
    for (int i = 0; i < (int)arreglo.size(); i++){
        if(promedio < arreglo.at(i)) mayor++;
        else if(promedio > arreglo.at(i)) menor++;
    }   
}

void errores(){
    std::cout << "Entrada invalida...\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}