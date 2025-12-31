#include <iostream>
#include <vector>

void multiplicar_3(std::vector<int> &arreglo);


int main(){
    std::vector<int> arreglo = {4, 6 , 87, 2, 6};
    multiplicar_3(arreglo);
    for(int x : arreglo){
        std::cout << x << " ";
    }
}

void multiplicar_3(std::vector<int> &arreglo){
    for( auto iter = arreglo.begin(); iter != arreglo.end(); iter++){
        *iter *= 3;
    }
}