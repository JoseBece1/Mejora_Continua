#include "gastos.h"

int MAX_ID(const std::vector<gastos> &gasto){
    if(gasto.empty()) return 0;

    int max = gasto.at(0).id;
    
    for(const gastos &x : gasto){
        if(max < x.id) max = x.id;
    }

    return max;
}