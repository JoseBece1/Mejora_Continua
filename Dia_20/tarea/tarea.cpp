#include "tarea.h"

int MAX_ID(const std::vector<Tarea> &tareas){
    if(tareas.empty()) return 0;

    int max = tareas[0].id;

    for(Tarea i : tareas){
        if(i.id > max) max = i.id;
    }
    
    return max;
}