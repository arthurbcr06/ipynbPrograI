
#include <iostream>
using namespace std;

class ZodiacoChino {
public:
    string obtenerAnimal(int año) {
        // Lista de animales del zodíaco chino según la tabla proporcionada
        string animales[] = {"Dragón", "Serpiente", "Caballo", "Oveja", "Mono", "Gallo", "Perro", "Cerdo", "Rata", "Buey", "Tigre", "Liebre"};

        // Calcular el índice del animal basado en el año
        int indice = (año - 2000) % 12;
        if (indice < 0) indice += 12; // Ajuste para años negativos

        return animales[indice];
    }

    void mostrarAnimal() {
        int año;
        cout << "Introduce un año: ";
        cin >> año;

        if (año >= 0) {
            cout << "El animal asociado es: " << obtenerAnimal(año) << endl;
        } else {
            cout << "Año no válido. Debe ser mayor o igual a 0." << endl;
        }
    }
};

int main() {
    ZodiacoChino zodiaco;
    zodiaco.mostrarAnimal();
    return 0;
}
