#include "menu.h"


void ejecutar_menu(std::vector<gastos> &gasto){
    while(true){
        std::cout << "\n-_-_-_-_- Menu _-_-_-_-\n"
                  << "1) Agregar gasto\n"
                  << "2) Listar gastos\n"
                  << "0) Salir\n";
        int opc;
        if(!(std::cin >> opc)){error(); continue;}

        switch (opc){
        case 1:{
            gastos g;
            std::cout << "Dame la categoria del gasto:\n";
            std::cin >> g.categoria;
            
            g.id = MAX_ID(gasto) + 1;

            while(true){
                std::cout << "Dame el monto del gasto:\n";
                if(!(std::cin >> g.monto)){error(); continue;}
                break;
            }

            gasto.push_back(g);
            break;
        }

        case 2:
            if(gasto.empty()){
                std::cout << "No hay gastos reportados.\n";
                break;
            }
            for(gastos x : gasto){
                std::cout << "\nID del gasto: " << x.id << '\n'
                          << "Etiqueta del gasto: " << x.categoria << '\n'
                          << "Monto del gasto: " << x.monto << '\n';
            }
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}