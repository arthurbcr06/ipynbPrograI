/* escriba un programa que le pida al usuario que ingrese el ancho y el largo de una habitacion. Una vez que se 
hayan leido los valores, su programa deberia calcular y mostrar el aera de la habitacion. La longitud y el ancho se
ingreseran como numeros de punto flotante. Incluya unidades en su mensaje de aviso y salida; ya sea pies o metros, 
dependiendo de con qué unidad se sienta mas comodo trabajando */
#include <iostream>

int main() {
    double largo, ancho;
    std::cout << "Ingrese el ancho de la habitacion en metros: ";
    std::cin >> ancho;
    std::cout << "Ingrese el largo de la habitacion en metros: ";
    std::cin >> largo;
    double area = largo * ancho;
    std::cout << "El area de la habitacion es: " << area << " metros cuadrados." << std::endl;

    return 0;
}
