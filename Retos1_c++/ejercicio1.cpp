#include <iostream>
#include <string>

/* Escriba un programa que solicite al usuario que ingrese su nombre.
El programa debe responder con un mensaje que salude al usuario, utilizando su nombre */

int main() {
    std::string nombre;
    std::cout << "Ingrese tu nombre: ";
    std::cin >> nombre;
    std::cout << "Buenos dias, " << nombre << std::endl;
    return 0;
}
