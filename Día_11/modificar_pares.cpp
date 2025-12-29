#include <iostream>
#include <vector>

void datos(std::vector<int> &arreglo);
void imprimir(const std::vector<int> &arreglo);
void error();
void triplicar(int* p, int tam, int &contador);

int main(){
    std::vector<int> arreglo;

    datos(arreglo);
    std::cout << "Datos antes: \n";
    imprimir(arreglo);
    int contador = 0;
    triplicar(arreglo.data(), arreglo.size(), contador);
    imprimir(arreglo);
    std::cout << "Hubo " << contador << " numeros modificados...\n";
}

void datos(std::vector<int> &arreglo){
    int tam;
    do{

        std::cout << "Cuantos datos quieres?\n";
        std::cin >> tam;
        if(std::cin.fail()) error();
        else if(tam <= 0) std::cout << "Entrada menor o igual a 0...\n";

    }while(tam <= 0 || std::cin.fail());
    
    for(int i = 0; i < tam; i++){
        std::cout << "Dame el numero " << i + 1 << " del arreglo:\n";
        int numero;
        
        std::cin >> numero;
        
        if(std::cin.fail()){error(); i--; continue;}

        arreglo.push_back(numero);
    }
}

void triplicar(int* p, int tam, int &contador){
    for(int i = 0; i < tam; i++){
        if(*(p + i) % 2 == 0){
            *(p + i) *= 3;
            contador++;
        }
    }
}

void imprimir(const std::vector<int> &arreglo){
    for(int x : arreglo) std::cout << x << " ";
    std::cout << "\n";
}

void error(){
    std::cout << "Entrada invalida...\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}