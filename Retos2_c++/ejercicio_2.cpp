
#include <iostream>
using namespace std;

class VerificadorDeLetra {
public:
    void verificarLetra() {
        char letra;
        cout << "Introduce una letra: ";
        cin >> letra;

        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            cout << "La letra es una vocal." << endl;
        } else if (letra == 'y') {
            cout << "A veces, 'y' es una vocal, a veces una consonante." << endl;
        } else {
            cout << "La letra es una consonante." << endl;
        }
    }
};

int main() {
    VerificadorDeLetra verificador;
    verificador.verificarLetra();
    return 0;
}
