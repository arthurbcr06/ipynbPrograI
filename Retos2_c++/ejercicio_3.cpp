#include <iostream>
using namespace std;

class IdentificadorDeFigura {
public:
    void identificarFigura() {
        int lados;
        cout << "Introduce el número de lados: ";
        cin >> lados;

        switch (lados) {
            case 3: cout << "Es un triángulo." << endl; break;
            case 4: cout << "Es un cuadrilátero." << endl; break;
            case 5: cout << "Es un pentágono." << endl; break;
            case 6: cout << "Es un hexágono." << endl; break;
            case 7: cout << "Es un heptágono." << endl; break;
            case 8: cout << "Es un octógono." << endl; break;
            case 9: cout << "Es un nonágono." << endl; break;
            case 10: cout << "Es un decágono." << endl; break;
            default: cout << "Número de lados no válido." << endl;
        }
    }
};

int main() {
    IdentificadorDeFigura identificador;
    identificador.identificarFigura();
    return 0;
}
