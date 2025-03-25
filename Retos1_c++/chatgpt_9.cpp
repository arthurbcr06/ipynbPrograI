#include <iostream>

int main() {
    int cantidadWidgets, cantidadGizmos;
    std::cout << "Ingrese la cantidad de widgets y gizmos: ";
    std::cin >> cantidadWidgets >> cantidadGizmos;
    std::cout << "El peso total del pedido es: " << (cantidadWidgets * 75 + cantidadGizmos * 112) << " gramos.\n";
    return 0;
}
