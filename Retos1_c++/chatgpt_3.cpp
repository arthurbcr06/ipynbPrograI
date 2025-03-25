#include <iostream>

int main() {
    std::string frase = "Un Trabajador, siempre culpa a la Herramienta";
    std::cout << "Frase original: " << frase << '\n';

    for (const auto& [mot, remplacement] : {std::pair{"Trabajador", "Estudiante"}, {"Herramienta", "Profesor"}}) {
        size_t pos = frase.find(mot);
        if (pos != std::string::npos) {
            frase.replace(pos, std::string(mot).length(), remplacement);
        }
    }

    std::cout << "Frase modificada: " << frase << '\n';
    return 0;
}

