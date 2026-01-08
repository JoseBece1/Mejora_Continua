#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>

struct Alumno {
    int ID = 0;
    std::string nombre;
    double calificacion = 0.0;
    char genero = '?'; // 'M' / 'F' (o lo que uses)
};

bool cargar_archivo(std::vector<Alumno> &alum, const std::string &url);
bool guardar(const std::vector<Alumno> &alum, const std::string &url);
int MAX_ID(const std::vector<Alumno> &alum);
void error();
void agregar_alumno(std::vector<Alumno> &alum);
void imprimir(const std::vector<Alumno> &alum);

int main() {
    std::vector<Alumno> alumnos;
    std::string url = "Alumnos_2.txt";

    if (cargar_archivo(alumnos, url))
        std::cout << "Archivo cargado correctamente\n";
    else
        std::cout << "Archivo no encontrado. Se creara vacio...\n";

    imprimir(alumnos);

    agregar_alumno(alumnos);

    if (guardar(alumnos, url))
        std::cout << "Guardado correctamente\n";
    else
        std::cout << "Error al guardar\n";

    return 0;
}

bool cargar_archivo(std::vector<Alumno> &alum, const std::string &url) {
    std::ifstream archivo(url);

    // Si no existe, lo creamos vacío
    if (!archivo) {
        std::ofstream crear(url);
        return false;
    }

    Alumno x;
    char barra;

    // Formato esperado:
    // ID|Nombre|Genero|Calificacion
    while (archivo >> x.ID >> barra) {
        std::getline(archivo >> std::ws, x.nombre, '|');   // nombre con espacios
        archivo >> x.genero >> barra >> x.calificacion;    // genero (1 char), luego |, luego calificacion
        alum.push_back(x);
    }

    return true;
}

bool guardar(const std::vector<Alumno> &alum, const std::string &url) {
    std::ofstream archivo(url);
    if (!archivo) return false;

    // Guardamos sin espacios alrededor de '|', así nunca aparecen espacios raros
    for (const Alumno &x : alum) {
        archivo << x.ID << '|'
                << x.nombre << '|'
                << x.genero << '|'
                << x.calificacion << '\n';
    }
    return true;
}

int MAX_ID(const std::vector<Alumno> &alum) {
    int maxId = 0;
    for (const Alumno &x : alum) {
        if (x.ID > maxId) maxId = x.ID;
    }
    return maxId;
}

void agregar_alumno(std::vector<Alumno> &alum) {
    // Limpia el \n pendiente (por si vienes de algún cin >> ...)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {
        Alumno x;

        std::cout << "Dame el nombre (-1 para salir): ";
        std::getline(std::cin, x.nombre);

        if (x.nombre == "-1") break;

        x.ID = MAX_ID(alum) + 1;

        std::cout << "Dame el genero (M/F): ";
        if (!(std::cin >> x.genero)) { error(); continue; }

        std::cout << "Dame la calificacion: ";
        if (!(std::cin >> x.calificacion)) { error(); continue; }

        // Deja listo el buffer para el siguiente getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        alum.push_back(x);
    }
}

void imprimir(const std::vector<Alumno> &alum) {
    if (alum.empty()) {
        std::cout << "No hay alumnos\n";
        return;
    }

    std::cout << "---- Alumnos ----\n";
    for (const Alumno &x : alum) {
        std::cout << "ID: " << x.ID << "\n"
                  << "Nombre: " << x.nombre << "\n"
                  << "Genero: " << x.genero << "\n"
                  << "Calificacion: " << x.calificacion << "\n\n";
    }
}

void error() {
    std::cout << "Entrada invalida...\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
