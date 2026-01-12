#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>
#include <vector>

struct Tarea
{
    int id;
    std::string titulo;
    int prioridad;
    bool estado = false;
};

int MAX_ID(const std::vector<Tarea> &tareas);

#endif