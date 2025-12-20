#include <iostream>

int main() {
   int arr[5] = {4,2,6,7,4};
   int *puntero = arr;

   for (int i = 0; i < 5; i++){
        std::cout << "Elemento " << i + 1 << ":" << *(puntero + i) << std::endl
        <<"Duplicado: " << *(puntero + i) * 2 << std::endl;
   }
   
   return 0;
}
