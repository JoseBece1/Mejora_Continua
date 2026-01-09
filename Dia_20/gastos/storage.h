#ifndef STORAGE_H
#define STORAGE_H
#include "gastos.h"
#include <fstream>

bool cargar_archivo(std::vector<gastos> &gastos, int &corruptas, const std::string &url);
bool guardar(const std::vector<gastos> &gastos, const std::string &url);

#endif