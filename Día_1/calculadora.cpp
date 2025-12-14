#include <iostream>
float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float division(float a, float b);

int main(){
    float a, b;
    float sumares, restares, multires, divires;

    std::cout << "Dame a\n";
    std::cin >> a;

    std::cout << "Dame b\n";
    std::cin >> b;

    sumares = suma(a,b);
    restares = resta(a,b);
    multires = multiplicacion(a,b);
    divires = division(a,b);

    std::cout << "Suma: " << sumares << "\n";
    std::cout << "Resta: " << restares << "\n";
    std::cout << "Multiplicacion: " << multires << "\n";
    std::cout << "Division: " << divires << "\n";
}

float suma(float a, float b){return a+b;}

float resta(float a, float b){return a-b;}

float multiplicacion(float a, float b){return a*b;}

float division(float a, float b){return a/b;}