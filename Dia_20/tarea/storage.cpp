#include "storage.h"
#include <fstream>
#include <sstream>

bool cargar_archivo(std::vector<Tarea> &tarea, const std::string &url, int &corruptas){
    std::ifstream archivo(url);
    if(!archivo) return false;

    std::string linea, id_str, titulo, prioridad, estado;

    while(std::getline(archivo, linea)){
        std::stringstream ss(linea);
        
        if(!std::getline(ss, id_str, '|')||
           !std::getline(ss,titulo, '|')||
           !std::getline(ss,prioridad, '|')||
           !std::getline(ss,estado)){corruptas++; continue;}
        if(titulo == "" || titulo == " "){corruptas ++; continue;}
        try{
            Tarea t;
            t.id = std::stoi(id_str);
            t.titulo = titulo;
            t.prioridad = stoi(prioridad);
            t.estado = stoi(estado);
            tarea.push_back(t);
        }
        catch(...){
            corruptas++;
        }
    }
    archivo.close();
    return true;
}

bool guardar(std::vector<Tarea> &tarea, const std::string &url){
    std::ofstream archivo(url);
    if(!archivo) return false;

    for(Tarea t : tarea){
        archivo << t.id << "|" << t.titulo << "|" << t.prioridad << "|" << t.estado << '\n';
    }
    archivo.close();
    return true;
}