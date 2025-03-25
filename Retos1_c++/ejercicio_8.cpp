/* Escriba un programa que lea un numero entero positivo, n, desde el usuario y luego muestra la suma de todos los 
numeros enteros del 1 al n. La suma de los primeros n enteros positivos se puede calcular mediante la formula : 
suma = (n)(n+1)/2 */
#include <iostream>

int main() {
    int n;
    std::cout << "Ingrese un numero entero positivo: ";
    std::cin >> n;
    int suma = (n * (n + 1)) / 2;
    std::cout << "La suma de los primeros " << n << " enteros positivos es: " << suma << std::endl;

    return 0;
}
