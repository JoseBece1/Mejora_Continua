#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>


struct Alumno
{
    int id = 0;
    std::string nombre;
    double promedio;
};

bool cargar_archivo (std::vector<Alumno> &alumnos, const std::string &url);
bool guardar(const std::vector<Alumno> &alumnos, const std::string &url);

void agregar_alumnos(std::vector<Alumno> &alumnos);
void promedioGeneral(const std::vector<Alumno>& alumnos, double &promedioGeneral);
void buscarMejorAlumno(const std::vector<Alumno>& alumnos, std::vector<int>& ids, int& cont);
void imprimir(const std::vector<Alumno> &a);
void errores();

int MAX_id(const std::vector<Alumno> &alumnos);

int main(){
    std::string url = "alumnos.txt";
    std::vector<Alumno> alumnos;
    double promedioGeneral_var;

    if(cargar_archivo(alumnos, url)){
        std::cout << "Hay: " << alumnos.size() << " alumnos.\n";
    }
    else
        std::cout << "Error al cargar el archivo, lo iniciaremos de 0\n";
    
    while (true){
        std::cout << "------------Menu------------\n"
                  << "1) Imprimir\n"
                  << "2) Agregar alumnos\n"
                  << "3) Guardar\n"
                  << "4) Promedio General\n"
                  << "5) Mejor/ Mejores alumnos\n"
                  << "0) Salir\n";
        int opc;

        if(!(std::cin >> opc)){ errores(); continue;}

        switch(opc){
            case 0:
                return 0;
            case 1:
                imprimir(alumnos);
                break;
            case 2:
                agregar_alumnos(alumnos);
                break;
            case 3:
                guardar(alumnos, url);
                break;
            case 4:
                promedioGeneral(alumnos, promedioGeneral_var);
                std::cout << "Promdio General de los alumnos: " << promedioGeneral_var << '\n';
                break;
            case 5:{
                std::vector<int> repetidos;
                int contador = 0;
                buscarMejorAlumno(alumnos, repetidos, contador);
                if(contador == 0){
                    std::cout << "No hay alumnos...\n";
                    break;
                }

                if(contador == 1){
                    for(size_t i = 0; i < alumnos.size(); i++){
                        if(alumnos.at(i).id == repetidos.at(0)){
                            std::cout << "El mejor alumno es: " << alumnos.at(i).nombre << '\n';
                        }
                    }
                }

                else{
                    std::cout << "Hay " << contador << " alumnos con el mejor promedio, son:\n";
                    for(int i = 0; i < contador; i++){
                        for(size_t j = 0; j < alumnos.size(); j++){

                            if(repetidos.at(i) == alumnos.at(j).id){
                                std::cout << alumnos.at(j).nombre;
                                if(i + 2 < contador)
                                    std::cout << ", ";
                                else if(i + 2 == contador)
                                    std::cout << " y ";
                                else 
                                    std::cout << ".\n";
                                break;
                            }

                        }
                    }
                }
                break;
            }
            default:
                std::cout << "Opcion no encontrada\n";
        }

    }
    
    
}

int MAX_id(const std::vector<Alumno> &alumnos){
    if(alumnos.size() == 0) return 0;

    int max = alumnos.at(0).id;

    for(size_t i = 0; i < alumnos.size(); i++){
        if(max < alumnos.at(i).id) max = alumnos.at(i).id;
    }
    return max;
}

void buscarMejorAlumno(const std::vector<Alumno>& alumnos, std::vector<int>& ids, int& cont){
    if(alumnos.size() == 0){cont = 0; return;}

    double max = alumnos.at(0).promedio;
    
    for(size_t i = 0; i < alumnos.size(); i ++)
        if(max < alumnos.at(i).promedio) max = alumnos.at(i).promedio;
    
        for(size_t i = 0; i < alumnos.size(); i ++){
            if(max == alumnos.at(i).promedio){
                cont++;
                ids.push_back(alumnos.at(i).id);
            }
    }
}

bool cargar_archivo (std::vector<Alumno> &alumnos, const std::string &url){
    std::ifstream archivo(url);
    if(!archivo) {std::ofstream crear(url);return false;}

    Alumno x;
    char barra;

    while(archivo >> x.id >> barra){
        std::getline(archivo, x.nombre, '|');
        archivo >> x.promedio;
        alumnos.push_back(x);
    }

    archivo.close();
    return true;
}

bool guardar(const std::vector<Alumno> &alumnos, const std::string &url){
    std::ofstream archivo(url);
    if(!archivo) return false;

    for(size_t i = 0; i < alumnos.size(); i++){
        archivo << alumnos.at(i).id << "|" << alumnos.at(i).nombre << "|" << alumnos.at(i).promedio << '\n';
    } 

    archivo.close();
    return true;
}

void agregar_alumnos(std::vector<Alumno> &alumnos){
    while(true){
        Alumno a;
        a.id = MAX_id(alumnos) + 1;
        std::cout << "Dame el nombre (-1 para salir): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, a.nombre);

        if(a.nombre == "-1") break;
        while(true){
            std::cout << "Dame el promedio: ";
            if(std::cin >>a.promedio) break;
            errores();
        }
        alumnos.push_back(a);
    }
}

void errores(){
    std::cout << "Entrada invalida\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void imprimir(const std::vector<Alumno> &a){
    if(a.size() == 0){
        std::cout << "No hay alumnos aun\n";
        return;
    }

    for(const Alumno &x : a){
        std::cout << "ID: " << x.id << '\n'
                  << "Alumno: " << x.nombre << '\n'
                  << "Promedio: " << x.promedio << '\n';

    }
}
void promedioGeneral(const std::vector<Alumno>& alumnos, double &promedioGeneral){
    if(alumnos.size() == 0) {promedioGeneral = 0; return;}

    double suma = 0;
    for(const Alumno &x : alumnos){
        suma += x.promedio;
    }
    promedioGeneral = suma / alumnos.size();
}

