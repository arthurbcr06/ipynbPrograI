#include <iostream>
using namespace std;

class VerificadorDeNumero {
public:
    void verificarNumero() {
        int numero;
        cout << "Introduce un número entero: ";
        cin >> numero;

        if (numero % 2 == 0) {
            cout << "El número es par." << endl;
        } else {
            cout << "El número es impar." << endl;
        }
    }
};

int main() {
    VerificadorDeNumero verificador;
    verificador.verificarNumero();
    return 0;
}
