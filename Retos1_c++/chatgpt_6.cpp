#include <iostream>

int main() {
    double longitud, ancho;

    std::cout << "Ingrese la longitud del campo en pies: ";
    std::cin >> longitud;
    std::cout << "Ingrese el ancho del campo en pies: ";
    std::cin >> ancho;

    std::cout << "El area del campo es: " << (longitud * ancho / 43560) << " acres.\n";

    return 0;
}
