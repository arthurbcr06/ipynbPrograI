/* cree un programa que lea la longitud y el ancho del campo de un agricultor en pies (dados por un usuario a 
traves de la terminal). Mostrar el aera del campo en acres */
#include <iostream>

int main() {

    double longitud, ancho;
    std::cout << "Ingrese la longitud del campo en pies: ";
    std::cin >> longitud;
    std::cout << "Ingrese el ancho del campo en pies: ";
    std::cin >> ancho;
    double area_pies_cuadrados = longitud * ancho;
    double area_acres = area_pies_cuadrados / 43560;
    std::cout << "El area del campo es: " << area_acres << " acres." << std::endl;
    
    return 0;
}
