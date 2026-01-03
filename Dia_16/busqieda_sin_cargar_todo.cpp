#include <fstream>
#include <iostream>
#include <string>

void busqueda(const std::string &url);

int main(){
    std::string url = "C:\\Users\\pepit\\Downloads\\PRACTICA DE MEJORA\\Dia_15\\archivo54.txt";

    busqueda(url);
}

void busqueda(const std::string &url){
    std::ifstream nums(url);
        if(!nums){
            std::cout << "Problemas con el archivo, reviselo\n";
            return;
        }
    int num;
    while(true){
        std::cout << "Que numero quieres buscar:\n";
        if(std::cin >> num) break;
        else{
            std::cout << "Entrada no valida";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }

    int x;
    int contador = 0;
    bool en_archivo = false;
    while(nums >> x){
        if(x == num){
            contador++;
            en_archivo = true;
        } 
    }
    if(en_archivo)
        std::cout << "El numero si esta en el archivo\n"
                  << "Aparece : " << contador << " de veces\n";
    else
        std::cout << "No se encontro el numero\n";
}