#include "tarea.h"
#include "menu.h"

int main(){
    std::vector<Tarea> tareas;
    std::string url = "tarea.txt";

    iniciar_menu(tareas, url);

    return 0;
}