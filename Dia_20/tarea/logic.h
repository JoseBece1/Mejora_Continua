#ifndef LOGIC_H
#define LOGIC_H
#include "tarea.h"

void imprimir(const std::vector<Tarea> &tarea);
void agregar_tarea(std::vector<Tarea> &tarea, const bool &cantidad);
void actualizar_estado(std::vector<Tarea> &tarea);
void eliminar(std::vector<Tarea> &tarea);

#endif