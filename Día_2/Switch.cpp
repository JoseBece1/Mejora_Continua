#include <iostream>

int main(){
    int opc = 0;

    do{
        std::cout << "\n---------Menu---------\n" 
                  << "1) Saludar\n"
                  << "2) Mostrar Edad\n"
                  << "3) Salir\n";
        std::cin >> opc;
        
        if(std::cin.fail()){
            std::cout << "Entrada invalida\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        } 
        else{
            switch (opc)
            {
            case 1:
                std::cout << "Holaaa\n";
                break;
            
            case 2:
                std::cout << "Tu edad es...\n";
                break;

            case 3:
                std::cout << "Adioss\n";
                break;

            default:
                std::cout << "Opcion no encontrada\n";
                break;
            }
        }
    }while(opc != 3);
    
    return 0;
}