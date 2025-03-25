#include <iostream>

int main() {
    double largo, ancho;

    std::cout << "Ingrese el ancho de la habitacion en metros: ";
    std::cin >> ancho;
    std::cout << "Ingrese el largo de la habitacion en metros: ";
    std::cin >> largo;

    std::cout << "El area de la habitacion es: " << (largo * ancho) << " metros cuadrados.\n";
    
    return 0;
}
