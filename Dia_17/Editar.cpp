#include <iostream>
#include <vector>
#include <fstream>
#include <string>

bool cargar_archivo(std::vector<int> &nums, const std::string &url);
void remplazar(const std::vector<int> &nums, std::vector<int> &nuevos, int &cont);
bool guardar(const std::vector<int> &nuevos, std::string url);
void error();

int main(){
    std::vector<int> numeros;
    std::string url = "C:\\Users\\pepit\\Downloads\\PRACTICA DE MEJORA\\Dia_15\\archivo54.txt";

    if(!cargar_archivo(numeros, url)) return 0;
    
    std::vector<int> nuevos;
    int cont = 0;
    remplazar(numeros, nuevos, cont);

    std::cout << "Tu nuevo archivo de numeros es:\n";
    for(int x : nuevos){
        std::cout << x << " ";
    }
    std::cout << "\nY se modificaron: " << cont << " numeros\n"; 

    if(!guardar(nuevos, url)) return 0;
    return 0;
}

bool cargar_archivo(std::vector<int> &nums, const std::string &url){
    std::ifstream archivo(url);
    if(!archivo){
        std::cout << "Error al cargar el archivo...\n";
        return false;
    }
    int x;
    while(archivo >> x){
        nums.push_back(x);
    }
    archivo.close();
    return true;
}

void remplazar(const std::vector<int> &nums, std::vector<int> &nuevos, int &cont){
    int viejo_num, nuevo_num;

    while(true){
        std::cout << "Que numero quieres remplazar?\n";

        for(int x : nums)
            std::cout << x << " ";

        std::cout << std::endl;

        if(!(std::cin >> viejo_num) ){
            error();
            continue;
        }

        std::cout << "Nuevo numero: ";
        if(!(std::cin >> nuevo_num) ){
            error();
            continue;
        }
        break;
    }

    for(int x : nums){
        if(x == viejo_num){
            nuevos.push_back(nuevo_num);
            cont++;
            continue;
        }
        nuevos.push_back(x);
    }
}

void error(){
    std::cout << "Entrada no valida\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

bool guardar(const std::vector<int> &nuevos, std::string url){
    std::ofstream archivo(url);
    if(!archivo){
        std::cout << "Error en el archivo\n";
        return false;
    }

    size_t i = 0;
    for(int x : nuevos){
        archivo << x;
        i++;
        if(i < nuevos.size()) archivo << " ";
    }

    archivo.close();
    return true;
}