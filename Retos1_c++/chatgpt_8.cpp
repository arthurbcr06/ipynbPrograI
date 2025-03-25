#include <iostream>

int main() {
    int n;
    std::cout << "Ingrese un numero entero positivo: ";
    std::cin >> n;
    std::cout << "La suma de los primeros " << n << " enteros positivos es: " << (n * (n + 1)) / 2 << "\n";
    return 0;
}
