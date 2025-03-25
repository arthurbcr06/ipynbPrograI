#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string texto = "mas de una vez he visto, la luz de la manana, acariciar las cumbres "
                        "con ojo soberano, besar su labio de oro el verdor de los campos, "
                        "dorando los arroyos con celestial alquimia.";

    // Compter les occurrences de 'a'
    int contador = std::count(texto.begin(), texto.end(), 'a');

    // Imprimer le résultat
    std::cout << "La letra 'a' aparece " << contador << " veces en la estrofa." << std::endl;
    
    return 0;
}
