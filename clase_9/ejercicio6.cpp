
#include <iostream> 

using namespace std;

int main() {
    const double impuesto = 0.05; // 
    const double propina = 0.18; // 18%

    double costoComida;
    double impuestoValor, propinaValor, costoTotal;

    cout << "Ingrese el costo de la comida: ";
    cin >> costoComida;

    impuestoValor = costoComida * impuesto;
    propinaValor = costoComida * propina;
    costoTotal = impuestoValor + propinaValor + costoComida;

    cout << "Impuesto: $" << impuestoValor << endl;
    cout << "Propina: $" << propinaValor << endl;
    cout << "Total a pagar: $" << costoTotal << endl;

    return 0;
}
