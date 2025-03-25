/* Declare una variable que contenga la frase obtenida en el ejercicio anterior. Coloque las mayusculas necesarias
y una comadetras de la palabra "trabajador". Imprima la frase, sustituya la frase trabajador por estudiante y la 
frase herramienta por profesor convenientemente. Imprima la frase */ 
#include <iostream>
#include <string>

int main() {
    std::string frase = "Un Trabajador, siempre culpa a la Herramienta";

    std::cout << "Frase original: " << frase << std::endl;

    size_t pos = frase.find("Trabajador");
    if (pos != std::string::npos) {
        frase.replace(pos, 10, "Estudiante");
    }

    pos = frase.find("Herramienta");
    if (pos != std::string::npos) {
        frase.replace(pos, 11, "Profesor");
    }

    std::cout << "Frase modificada: " << frase << std::endl;

    return 0;
}
