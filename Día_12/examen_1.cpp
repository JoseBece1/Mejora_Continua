#include <iostream>
#include <vector>

void imprimir(const std::vector<int> &arreglo);
void duplicar(int *p, int tam);
int main(){
    std::vector<int> arreglo = {4, 7, 4, 8, 2, 3};
    imprimir(arreglo);
    duplicar(arreglo.data(), arreglo.size());
    imprimir(arreglo);
}

void imprimir(const std::vector<int> &arreglo){
    for(int x : arreglo){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void duplicar(int *p, int tam){
    for(int i = 0; i < tam; i++){
        *(p + i) *= 2;
    }
}