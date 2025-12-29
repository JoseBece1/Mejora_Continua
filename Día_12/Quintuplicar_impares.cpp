#include <iostream>
#include <vector>

void ing_datos(std::vector<int> &arreglo);
void errores();
void quintuplicar(int *p, int tam, int &cont);
void imprimir(const std::vector<int> &arreglo);

int main(){
    std::vector<int> arreglo;
    ing_datos(arreglo);
    imprimir(arreglo);
    int cont = 0;
    quintuplicar(arreglo.data(), arreglo.size(), cont);
    imprimir(arreglo);
    std::cout << "Se modificó " << cont << " numeros...\n"; 
}

void ing_datos(std::vector<int> &arreglo){
    int tam;
    do{
        std::cout << "Que tamaño quieres que sea el arreglo: \n";
        std::cin >> tam;

        if(std::cin.fail()){errores();}
    }while(tam <= 0);

    for(int i = 0; i < tam; i++){
        std::cout << "Dame el numero " << i + 1 << " del arreglo: \n";
        int num;

        std::cin >> num;
        if(std::cin.fail()){errores(); continue; i--;}
        arreglo.push_back(num);
    }
}

void errores(){
    std::cout << "Entrada invalida...\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

void imprimir(const std::vector<int> &arreglo){
    for(int x : arreglo){
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void quintuplicar(int *p, int tam, int &cont){
    for(int i = 0; i < tam; i++){
        if(*(p + i) % 2 == 1) {
            *(p + i) *= 5;
            cont++;
        }
    }
}