#ifndef STORAGE_H
#define STORAGE_H

#include "tarea.h"

bool cargar_archivo(std::vector<Tarea> &tarea, const std::string &url, int &corruptas);
bool guardar(std::vector<Tarea> &tarea, const std::string &url);

#endif