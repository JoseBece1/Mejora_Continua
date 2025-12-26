#include <iostream>
#include <vector>

void datos(std::vector<int> &array, int tam);
void errores();
float promedio(const std::vector<int> &array);
void cont_menores_mayores(const std::vector<int> &array ,const float promedio, int &menores, int &mayores);

int main() {
    std::vector<int> array;
    int tam = 0;
    do{
        std::cout << "Dame el tamaño del array:\n";
        std::cin >> tam;
        if(std::cin.fail()){errores(); continue;}
        
        else if(tam <= 0) std::cout << "Tamano invalido...\n";       
    }while(tam <= 0);

    datos(array, tam);
    float promedio_var = promedio(array);

    std::cout << "El promedio es de: " << promedio_var << std::endl;

    int menores = 0;
    int mayores = 0;

    cont_menores_mayores(array , promedio_var, menores, mayores);
    std::cout <<"Hay " << menores <<" numeros menores que el promedio\n"
              <<"Hay " << mayores <<" numeros mayores que el promedio\n";
              
    return 0;

}

void datos(std::vector<int> &array, int tam){
    for(int i = 0; i < tam; i++){
        int num = 0;
        std::cout << "Dame los datos del numero " << i + 1
                  <<": \n";  
        std::cin >> num;
        if(std::cin.fail()){
            errores();
            i--;
            continue;
        }
        array.push_back(num);
    }
}

float promedio(const std::vector<int> &array){
    int suma = 0;
    for(int x : array){
        suma += x;
    }
    return (float)suma / (float)array.size();

}

void cont_menores_mayores(const std::vector<int> &array ,const float promedio, int &menores, int &mayores){
    for(int x : array){
        if(promedio < x) mayores++;
        else if(promedio > x) menores++;
    }
}

void errores(){
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Datos invalidos...\n";
}