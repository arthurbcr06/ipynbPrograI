/* Un minorista en linea vende dos productos : widgets y gizmos. Cada widget pesa 75 gramos. Cada gizmo pesa 
112 gramos. Escriba un programa que lea la cantidad de widgets y la cantidad de gizmos en un pedido del 
usuario. Entonces su programa deberia calcular y mostrar el peso total del pedido */
#include <iostream>

int main() {
    int cantidadWidgets, cantidadGizmos;
    const int pesoWidget = 75; // en gramos
    const int pesoGizmo = 112; // en gramos
    std::cout << "Ingrese la cantidad de widgets: ";
    std::cin >> cantidadWidgets;
    std::cout << "Ingrese la cantidad de gizmos: ";
    std::cin >> cantidadGizmos;
    int pesoTotal = (cantidadWidgets * pesoWidget) + (cantidadGizmos * pesoGizmo);
    std::cout << "El peso total del pedido es: " << pesoTotal << " gramos." << std::endl;

    return 0;
}
