#include <iostream>
#include <cmath>
using namespace std;

class CalculadorDeFrecuencia {
public:
    double obtenerFrecuencia(char nota, int octava) {
        double frecuencias[7] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};
        int indice = nota - 'C';

        if (indice < 0 || indice >= 7) {
            return -1; // Nota no válida
        }

        double frecuenciaBase = frecuencias[indice];
        return frecuenciaBase * pow(2, octava - 4);
    }

    void calcularFrecuencia() {
        char nota;
        int octava;
        cout << "Introduce la nota (C, D, E, F, G, A, B): ";
        cin >> nota;
        cout << "Introduce la octava (0-8): ";
        cin >> octava;

        double frecuencia = obtenerFrecuencia(toupper(nota), octava);
        if (frecuencia > 0) {
            cout << "La frecuencia de " << nota << octava << " es " << frecuencia << " Hz." << endl;
        } else {
            cout << "Nota no válida" << endl;
        }
    }
};

int main() {
    CalculadorDeFrecuencia calculador;
    calculador.calcularFrecuencia();
    return 0;
}
