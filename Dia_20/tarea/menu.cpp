#include "menu.h"
#include "error.h"
#include "storage.h"
#include "logic.h"

bool iniciar_menu(std::vector<Tarea> &tarea, const std::string &url){
    int corruptas = 0;
    if(!cargar_archivo(tarea, url, corruptas)){
        std::cout <<"No se encontro el archivo...\nSe creara uno desde cero\n";
        corruptas = 0;
    }
    else{
        std::cout <<"Archivo cargado correctamente\n";
        if(corruptas > 0) std::cout << "Se encontraron " << corruptas << " lineas corruptas.\n";
    }
    while (true){
        std::cout << "\n_-_-_- MENU -_-_-_\n"
                  << "1) Enlistar tareas\n"
                  << "2) Agregar una tarea\n"
                  << "3) Agregar x tareas\n"
                  << "4) Actualizar estado de tarea\n"
                  << "5) Eliminar tarea\n"
                  << "0) Salir\n";
        int opc;
        if(!(std::cin >> opc)) {error(); continue;}

        switch (opc){
            case 0:
                return true;
            case 1:
                imprimir(tarea);
                break;
            case 2:
                agregar_tarea(tarea, true);
                break;
            case 3:
                agregar_tarea(tarea, false);
                break;
            case 4:
                actualizar_estado(tarea);
                break;
            case 5:
                eliminar(tarea);
                break;
            default:
                std::cout << "Opcion no valida\n";
                break;
        }
        guardar(tarea, url);
    }
    
}