#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void carga_archivo(std::vector<int> &nums, std::string ref);
void guardar(const std::vector<int> &nums, std::string ref);
void imprimir(const std::vector<int> &nums);
void pedir_nums(std::vector<int> &nums);
void error();

int main(){

    std::string ref = "C:\\Users\\pepit\\Downloads\\PRACTICA DE MEJORA\\Dia_15\\archivo54.txt";
    std::vector<int> nums;
    
    carga_archivo(nums, ref);
    imprimir(nums);
    pedir_nums(nums);
    guardar(nums, ref);

    return 0;
}

void carga_archivo(std::vector<int> &nums, std::string ref){
    std::ifstream numeros(ref);
    if(!numeros){
        std::cout << "Error en el archivo...\n";
        return;
    }

    int x;
    while( numeros >> x){
        nums.push_back(x);
    }
}

void guardar(const std::vector<int> &nums, std::string ref){
    std::ofstream archivo(ref);
    if(!archivo){
        std::cout << "Error al guardar los numeros\n";
    }
    for(size_t i = 0; i < nums.size(); i++){
        archivo << nums.at(i);
        if(i + 1 < nums.size()) archivo << " ";
    }
}

void imprimir(const std::vector<int> &nums){
    for (int x : nums){
        std::cout << x << " ";
    }

    std::cout << std::endl;
}

void pedir_nums(std::vector<int> &nums){
    int cant = 0;
    while(true){
        std::cout << "Cuantos numeros quieres agregar?\n";
        if(std::cin >> cant)break;
        else error();
    }
    for(int i = 0; i < cant; i ++){
        int num = 0;
        if(std::cin >> num){
            nums.push_back(num);
        }
        else{
            error();
            i--;
        }
    }
}

void error(){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Entrada invalida";
}