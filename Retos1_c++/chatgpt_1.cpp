#include <iostream>
int main() {
    std::cout << "Ingrese tu nombre: ";
    std::string nombre;
    std::getline(std::cin, nombre); // Permite nombres con espacios
    std::cout << "Buenos días, " << nombre << "!\n";
    return 0;
}
