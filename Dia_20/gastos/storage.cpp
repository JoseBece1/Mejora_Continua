#include <iostream>
#include "storage.h"
#include <sstream>

bool cargar_archivo(std::vector<gastos> &gasto, int &corruptas, const std::string &url){
    std::ifstream archivo(url);
    if(!archivo) return false;

    std::string id_str, categoria_str, monto_str;
    std::string linea;

    while(std::getline(archivo, linea)){
        std::stringstream ss(linea);
        if(!std::getline(ss, id_str,'|') ||
           !std::getline(ss, categoria_str, '|') ||
           !std::getline(ss, monto_str)){corruptas++; continue;}
        try{
            gastos g;
            g.id = std::stoi(id_str);
            g.categoria =categoria_str;
            g.monto = std::stod(monto_str);

            if(g.monto <= 0){
                corruptas++;
                continue;
            }

            gasto.push_back(g);
        }
        catch(...){
            corruptas++;
        }
    }
    
    return true;
}

bool guardar(const std::vector<gastos> &gasto, const std::string &url){
    std::ofstream archivo(url);
    if(!archivo) return false;

    for(gastos x : gasto){
        archivo << x.id << '|' << x.categoria <<'|' << x.monto;
    }
    return true;
}