#ifndef IO_H
#define IO_H

#include <string>
#include <vector>

// Carga enteros desde un archivo a un vector.
// Devuelve true si pudo abrir y leer, false si no.
bool cargarEnteros(const std::string& path, std::vector<int>& out);

// Guarda enteros (reescribe completo).
bool guardarEnteros(const std::string& path, const std::vector<int>& nums);

// Pide un entero validado por consola.
int pedirEntero(const std::string& msg);

#endif
