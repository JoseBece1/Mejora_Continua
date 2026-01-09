#ifndef GASTOS_H
#define GASTOS_H
#include <string>
#include <vector>

struct gastos
{
    int id;
    std::string categoria;
    double monto;
};

int MAX_ID(const std::vector<gastos> &gasto);

#endif
