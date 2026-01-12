#include "logic.h"
#include "error.h"
#include <limits>

void imprimir(const std::vector<Tarea> &tarea){
    if(tarea.empty()){
        std::cout << "No hay elementos aun...\n";
        return;
    }
    for(Tarea t : tarea){
        std::cout << "\nID: " << t.id
                  << "\nTitulo: " << t.titulo
                  << "\nPrioridad: " << t.prioridad
                  << "\nEstado: ";
        if(t.estado == 1) std::cout << "completado\n";
        else std::cout << "aun no completado\n";
    }
}

void agregar_tarea(std::vector<Tarea> &tarea, const bool &cantidad){
    while(true){
        Tarea t;
        t.id = MAX_ID(tarea) + 1;
        
        while(true){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Dame el titulo de la tarea: ";
            if(cantidad == false)std::cout <<"(-1 para salir)\n";
            if(!(std::getline(std::cin, t.titulo)) || t.titulo == "" || t.titulo == " "){error();continue;}
            break;
        }
        if(t.titulo == "-1") break;
        do{
            std::cout << "Dame la prioridad de la tarea (1 - 10)\n";
            if(!(std::cin >> t.prioridad)) {
                error();
                continue;
            }
            else if(t.prioridad < 1 || t.prioridad > 10) {
                std::cout << "Prioridad fuera de rango\n";
            }
        }while(t.prioridad < 1 || t.prioridad > 10);

        int estado_input = 0;
        do{
            std::cout << "Dame el estado de la tarea (1 hecha, 0 aun no acabada)\n";
            if(!(std::cin >> estado_input)) {
                error();
                continue;
            }
            else if(estado_input < 0 || estado_input > 1) {
                std::cout << "Estado debe ser 0 o 1\n";
            }
            else {
                t.estado = estado_input;
            }
        }while(estado_input < 0 || estado_input > 1);
        
        tarea.push_back(t);
        if(cantidad == true) break;
    }
}

void actualizar_estado(std::vector<Tarea> &tarea){
    int id =  0;
    while(true){
        std::cout << "Cual tarea quieres modificar? (pon la ID)\n"
                << "Si no te la sabes pon -1 para salir y ver el listado.\n";
        if(id == -1) return;
        if(!(std::cin >> id)){error(); continue;}
        break;
    }

    for(Tarea &t : tarea){
        if(t.id == id){
            int estado = 0;
            std::cout << "Tarea encontrada\n";
            do{
               std::cout << "Dame el nuevo estado: (1 completado y 0 no completado)\n";
               if(!(std::cin >> estado)){error(); continue;}
               else if(estado < 0 || estado > 1){
                   std::cout << "Estado debe ser 0 o 1\n";
                   continue;
               }
               break;
            }while(true);
            t.estado = estado;
        }

    }
}

void eliminar(std::vector<Tarea> &tarea){
    int id =  0;
    while(true){
        std::cout << "Cual tarea quieres eliminar? (pon la ID)\n"
                << "Si no te la sabes pon -1 para salir y ver el listado.\n";
        if(id == -1) return;
        if(!(std::cin >> id)){error(); continue;}
        break;
    }
    std::vector<Tarea> tarea_nueva;
    bool encontrado = false;
    for(Tarea t : tarea){
        if(t.id == id){
            encontrado = true;
            continue;
        }
        tarea_nueva.push_back(t);
    }
    if(encontrado == true)
        std::cout << "Tarea encontrada y eliminada\n";
    else
        std::cout << "Tarea no encontrada\n";
    tarea = tarea_nueva;
}
