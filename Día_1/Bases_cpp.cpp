#include <iostream>
#include <string>
using namespace std;

int main(){
    string nombre;
    int edad;
    
    cout << "Nombre: \n";
    getline(cin, nombre);

    cout << "Edad: \n";
    cin >> edad;

    cout << "Hola " << nombre 
         <<" en 20 anios tendras " 
         << edad + 20 << " anios\n";
}