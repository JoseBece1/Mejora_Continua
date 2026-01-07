#include "io.h"

#include <iostream>
#include <vector>

int main() {
    const std::string path = "datos.txt";
    std::vector<int> nums;

    if (cargarEnteros(path, nums)) {
        std::cout << "Cargados " << nums.size() << " numeros desde " << path << "\n";
    } else {
        std::cout << "No se pudo abrir " << path << ". Se empezara vacio.\n";
    }

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1) Agregar numero\n";
        std::cout << "2) Mostrar\n";
        std::cout << "3) Guardar\n";
        std::cout << "0) Salir\n";

        int op = pedirEntero("Opcion: ");

        if (op == 1) {
            int x = pedirEntero("Numero a agregar: ");
            nums.push_back(x);
            std::cout << "OK. Ahora hay " << nums.size() << " numeros.\n";
        } 
        else if (op == 2) {
            std::cout << "Contenido:\n";
            for (int i = 0; i < (int)nums.size(); ++i) {
                std::cout << i << ": " << nums.at(i) << "\n";
            }
        } 
        else if (op == 3) {
            if (guardarEnteros(path, nums)) {
                std::cout << "Guardado en " << path << "\n";
            } else {
                std::cout << "Error guardando en " << path << "\n";
            }
        } 
        else if (op == 0) {
            std::cout << "Saliendo...\n";
            break;
        } 
        else {
            std::cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
