
#include <iostream>

int main() {
    int x[3] = {10,4,6};
    int *p = x;

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Numeros en el arreglo: " << *(p + i) << std::endl;
    }


    return 0;
}
