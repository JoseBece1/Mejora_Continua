#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void cargar_archivo(std::vector<int> &nums,  const std::string &url);
void eliminar_archivo(std::vector<int> &nums, std::vector<int> &nuevos, int &cont);
void guardar(const std::vector<int> &nuevos, const std::string &url);

void main(){
    std::string url = "C:\\Users\\pepit\\Downloads\\PRACTICA DE MEJORA\\Dia_15\\archivo54.txt";
    std::vector<int> numeros;

    cargar_archivo(numeros, url);
    std::vector<int> nuevos;
    int cont = 0;

    eliminar_archivo(numeros, nuevos, cont);

    std::cout << "Se modificaron " << cont << " numeros en el archivo\n";
    guardar(nuevos, url);
}

void cargar_archivo(std::vector<int> &nums, const std::string &url){
    std::ifstream archivo(url);
    if(!archivo){
        std::cout << "Error al abrir el archivo...\n";
        return;
    }

    int x;
    while(archivo >> x){
        nums.push_back(x);
    }
    archivo.close();
}

void eliminar_archivo(std::vector<int> &nums, std::vector<int> &nuevos, int &cont){
    int numero;
    while(true){
        std::cout << "Dame el numero a eliminar:\n";
        if(std::cin >> numero) break;
        else{
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada invalida\n";
        }
    }
    for(int x : nums){
        if(x != numero){
            nuevos.push_back(x);
        }
        else cont++;
    }
}

void guardar(const std::vector<int> &nuevos,  const std::string &url){
    std::ofstream archivo(url);
    if(!archivo){
        std::cout << "Error al abrir el archivo...\n";
        return;
    }
    size_t i = 0;
    for(int x : nuevos){
        archivo << x;
        i++;
        if(i < nuevos.size()) archivo << " ";
    }
    archivo.close();
}