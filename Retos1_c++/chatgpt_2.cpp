#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::vector<std::string> palabras = {"culpa", "mal", "un", "siempre", "la", "trabajador", "a", "herramienta"};
    std::vector<std::string> orden = {"un", "trabajador", "siempre", "culpa", "a", "la", "herramienta"};

    std::unordered_map<std::string, int> indice;
    for (size_t i = 0; i < palabras.size(); ++i) {
        indice[palabras[i]] = i;
    }

    for (size_t i = 0; i < orden.size(); ++i) {
        std::cout << palabras[indice[orden[i]]] << (i < orden.size() - 1 ? " " : "");
    }

    return 0;
}
