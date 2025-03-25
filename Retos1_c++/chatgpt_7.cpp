#include <iostream>
#include <iomanip>

int main() {
    double costoComida;

    std::cout << "Ingrese el costo de la comida: ";
    std::cin >> costoComida;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Monto del impuesto: $" << (costoComida * 0.10) << "\n";
    std::cout << "Monto de la propina: $" << (costoComida * 0.18) << "\n";
    std::cout << "Total general: $" << (costoComida * 1.28) << "\n";

    return 0;
}
