#include <iostream>
#include <fstream>
#include <vector>
#include <string>

bool cargar_archivo(std::vector<int> &numeros, const std::string &url);
void imprimir(const std::vector<int> &numeros);
void agregar(std::vector<int> &numeros);
bool guardar(const std::vector<int> &numeros, const std::string &url);
void editar(std::vector<int> &numeros);
void eliminar(const std::vector<int> &numeros, std::vector<int> &numeros_nuevos);
void limpiar_error();

int main(){
    std::vector<int> nums;
    std::vector<int> nums_nuevos;
    std::string url = "C:\\Users\\pepit\\Downloads\\PRACTICA DE MEJORA\\Dia_15\\archivo54.txt";

    if(!cargar_archivo(nums, url))return 1;
    for(int x : nums)
        std::cout << x << " ";
    
    while(true){
        int opc;
        std::cout << "----------- Menu -----------\n"
                  << "1) Imprimir archivo\n"
                  << "2) Agregar\n"
                  << "3) Editar\n"
                  << "4) Eliminar\n"
                  << "0) Salir\n";

        if(!(std::cin >> opc)){
            limpiar_error();
            continue;
        }

        else if(opc == 0) break;

        switch (opc){
        case 1:
            imprimir(nums);
            break;
        case 2:
            agregar(nums);
            guardar(nums, url);
            break;
        case 3:
            editar(nums);
            guardar(nums, url);
            break;
        case 4:
            eliminar(nums, nums_nuevos);
            guardar(nums_nuevos, url);
            nums = nums_nuevos;
            break;

        default:
            break;
        }
    }
}

void agregar(std::vector<int> &numeros){
    while(true){
        int numero;
        std::cout << "(-1 para salir) Numero que quieres agregar: \n";
        if(!(std::cin >> numero)){
            limpiar_error();
            continue;
        }
        if(numero == -1) break;
        numeros.push_back(numero);
    }
}


void imprimir(const std::vector<int> &numeros){
    for(int x : numeros)
        std::cout << x << " ";
    std::cout << std::endl;
}

bool cargar_archivo(std::vector<int> &numeros, const std::string &url){
    std::ifstream archivo(url);
    if(!archivo)
        return false;
    
    int i;
    while(archivo >> i)
        numeros.push_back(i);

    archivo.close();
    return true;
}

bool guardar(const std::vector<int> &numeros, const std::string &url){
    std::ofstream archivo(url);
    if(!archivo){
        std::cout << "Error al abrir el archivo...\n";
        return false;
    }

    for(size_t i = 0; i < numeros.size(); i++){
        archivo << numeros.at(i);
        if(i + 1 < numeros.size()) archivo << " ";
    }
    archivo.close();
    return true;
}

void editar(std::vector<int> &numeros){
    int viejo;
    int nuevo;
    while(true){
        std::cout << "Dime que numero quieres editar (-1 para salir):\n";
        if(!(std::cin >> viejo)){
            limpiar_error();
            continue;
        }

        if(viejo == -1) break;

        std::cout << "Dime que numero quieres poner:\n";
        if(!(std::cin >> nuevo)){
            std::cout << "Error\n";
            continue;
        }

        for(int &x : numeros){
            if(x == viejo) x = nuevo;
        }
    }
}

void eliminar(const std::vector<int> &numeros, std::vector<int> &numeros_nuevos){
    while(true){
        int eliminar;
        std::cout << "Numero a eliminar (-1 salir): ";
        
        if(!(std::cin >> eliminar)){
            limpiar_error();
            continue;
        }

        if(eliminar == -1) break;
        
        for(int x : numeros){
            if(x != eliminar){
                numeros_nuevos.push_back(x);
            }
        }
    }

}

void limpiar_error(){
    std::cout << "Error de ingreso de datos\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}