#include <iostream>
float suma(float a, float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float division(float a, float b);

int main(){
    float a, b;

    std::cout << "Dame a\n";
    std::cin >> a;

    std::cout << "Dame b\n";
    std::cin >> b;


    std::cout << "Suma: " << suma(a,b) << "\n";
    std::cout << "Resta: " << resta(a,b) << "\n";
    std::cout << "Multiplicacion: " << multiplicacion(a,b) << "\n";
    std::cout << "Division: " << division(a,b) << "\n";

    return 0;
}

float suma(float a, float b){return a+b;}

float resta(float a, float b){return a-b;}

float multiplicacion(float a, float b){return a*b;}

float division(float a, float b){return a/b;}