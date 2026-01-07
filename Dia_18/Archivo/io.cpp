#include "io.h"

#include <fstream>
#include <iostream>
#include <limits>

bool cargarEnteros(const std::string& path, std::vector<int>& out) {
    std::ifstream in(path);
    if (!in) return false;

    out.clear();
    int x;
    while (in >> x) {
        out.push_back(x);
    }
    return true;
}

bool guardarEnteros(const std::string& path, const std::vector<int>& nums) {
    std::ofstream out(path, std::ios::trunc);
    if (!out) return false;

    for (int x : nums) {
        out << x << '\n';
    }
    return true;
}

int pedirEntero(const std::string& msg) {
    int x;
    while (true) {
        std::cout << msg;
        if (std::cin >> x) return x;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Intenta de nuevo.\n";
    }
}
