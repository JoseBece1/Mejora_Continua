#include "mathematics.h"
#include <iostream>

int main(){
    int x, y;
    std::cout << "Dame dos numeros para hacer suma y resta\n";
    std:: cin >> x >> y;

    std::cout << "Suma: " << suma(x, y) << '\n'
              << "Resta: " << resta(x, y) << '\n';
              
}