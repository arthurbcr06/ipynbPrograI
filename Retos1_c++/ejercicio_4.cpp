/* Dado el siguiente texto de Shakespeare : mas de una vez he visto, la luz de la manana, acariciar las cumbres
con ojo soberano, besar su labio de oro el verdor de los campos, dorando los arroyos con celestial alquimia. 
cuanta cuantas veces aparece la "a" en la estrofa */

#include <iostream>
#include <string>

int main() {
    std::string texto = "mas de una vez he visto, la luz de la manana, acariciar las cumbres "
                        "con ojo soberano, besar su labio de oro el verdor de los campos, "
                        "dorando los arroyos con celestial alquimia.";
    int contador = 0;
    for (char c : texto) {
        if (c == 'a') {
            contador++;
        }
    }

    std::cout << "La letra 'a' aparece " << contador << " veces en la estrofa." << std::endl;
    return 0;
}
