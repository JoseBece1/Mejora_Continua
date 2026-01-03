#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void cargar_archivo(std::vector<int> &numeros, std::string url);
void busqueda(const std::vector<int> &numeros);

int main(){
    std::vector<int> numeros;
    std::string url = "C:\\Users\\pepit\\Downloads\\PRACTICA DE MEJORA\\Dia_15\\archivo54.txt";
    cargar_archivo(numeros, url);
    busqueda(numeros);
}

void cargar_archivo(std::vector<int> &numeros, std::string url){
    std::ifstream archivo(url);
    if(!archivo){
        std::cout << "No se pudo abrir el archivo...\n";
        return;
    }
    int x;

    while(archivo >> x){
        numeros.push_back(x);
    }
    archivo.close();
}

void busqueda(const std::vector<int> &numeros){
    while(true){
        int num;
        std::cout << "Dime que numero quieres buscar:\n";
        if(std::cin >> num) {
            int contador = 0;
            bool en_archivo = false;
            for(int x : numeros){
                if(x == num){
                    contador++;
                    en_archivo = true;
                }
            }

            if(en_archivo) 
                std::cout << "Si existe el numero en el archivo\n" 
                          << "El numero se repite " << contador << '\n';      
            else std::cout << "No se encontro el numero \n";                    
            return;
        }
        else{
            std::cout << "Entrada no valida... Intentalo otra vez\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

    }
}