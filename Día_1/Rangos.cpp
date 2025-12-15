#include <iostream>

int main(){
    int calificacion = 0;

    std::cout << "Dame tu calificacion:\n";
    std::cin >> calificacion;

    if(std::cin.fail()){
        std::cout << "Entrada invalida";
        std::cin.clear();              // Limpia el estado de error del flujo
        std::cin.ignore(1000, '\n');   // Descarta los caracteres restantes del buffer
    }

    else if (calificacion < 0 || calificacion > 100) std::cout << "Calificacion invalida...\n";
    else if (calificacion >= 90 && calificacion <= 100) std::cout << "Calificacion EXCELENTE\n";
    else if (calificacion >= 80 && calificacion <= 89) std::cout << "Calificacion BUENA\n";
    else if (calificacion >= 70 && calificacion <= 79) std::cout << "Calificacion MEDIA\n";
    else if (calificacion < 70) std::cout << "Calificacion REPROBATORIA\n";

    return 0;
}