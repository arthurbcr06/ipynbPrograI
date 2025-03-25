
/* Ponga en orden la frase garantizado que la longitud de la cadena solo tenga un espacio entre frase y frase 
excepto en el comienzo y el final : culpa, mal,un,siempre,la,trabajador,a,herramienta*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Vector con las palabras desordenadas
    std::vector<std::string> palabras = {"culpa", "mal", "un", "siempre", "la", "trabajador", "a", "herramienta"};

    // Vector con el orden deseado
    std::vector<std::string> orden = {"un", "trabajador", "siempre", "culpa", "a", "la", "herramienta"};

    // Imprimir la frase ordenada
    for (size_t i = 0; i < orden.size(); ++i) {
        std::cout << orden[i];
        if (i < orden.size() - 1) {
            std::cout << " ";
        }
    }

    return 0;
}
