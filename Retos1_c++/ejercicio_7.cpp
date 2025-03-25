/* El programa que crees para este ejercicio comenzara leyendo el costo de una comida pedida en un restaurante y 
dadas por el usuario. Entonces su programa calculara el impuesto y propina para la comida. Utilice su tasa
impositiva local al calcular el monto del impuesto adeudado. 
Calcule la propina como el 18 por ciento del monto de la comida (sin el impuesto). La salida de su programa debe 
incluir el monto del impuesto, el monto de la propina y el total general para la comida incluye tanto el impuesto
como la propina. Formatee la salida para que todos los valores se muestran utilizando dos decimales */
#include <iostream>
#include <iomanip>

int main() {
    double costoComida;
    std::cout << "Ingrese el costo de la comida: ";
    std::cin >> costoComida;
    const double tasaImpuesto = 0.10;
    double impuesto = costoComida * tasaImpuesto;
    double propina = costoComida * 0.18;
    double totalGeneral = costoComida + impuesto + propina;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Monto del impuesto: $" << impuesto << std::endl;
    std::cout << "Monto de la propina: $" << propina << std::endl;
    std::cout << "Total general: $" << totalGeneral << std::endl;

    return 0;
}
