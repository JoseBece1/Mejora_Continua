#include <iostream>
#include <vector>

void duplicar(int *p, int tam);
void imprimir(const std::vector<int> &arreglo);

int main(){
    std::vector<int> arreglo = {5, 2, 6, 8, 2};

    imprimir(arreglo);
    duplicar(&arreglo[0], arreglo.size());
    imprimir(arreglo);

}

void duplicar(int *p, int tam){
    for(int i = 0; i < tam ; i ++){
        *(p + i) *= 2;
    }
}

void imprimir(const std::vector<int> &arreglo){
    for(int x : arreglo){
        std::cout << x << " ";
    }
    std::cout << "\n";
}