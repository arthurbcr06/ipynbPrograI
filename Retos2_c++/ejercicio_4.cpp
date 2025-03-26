
#include <iostream>
#include <string>
using namespace std;

class DiasDelMes {
public:
    void mostrarDias() {
        string mes;
        cout << "Introduce el nombre del mes: ";
        cin >> mes;

        if (mes == "enero" || mes == "marzo" || mes == "mayo" || mes == "julio" ||
            mes == "agosto" || mes == "octubre" || mes == "diciembre") {
            cout << "31 días" << endl;
        } else if (mes == "abril" || mes == "junio" || mes == "septiembre" || mes == "noviembre") {
            cout << "30 días" << endl;
        } else if (mes == "febrero") {
            cout << "28 o 29 días" << endl;
        } else {
            cout << "Mes no válido" << endl;
        }
    }
};

int main() {
    DiasDelMes dias;
    dias.mostrarDias();
    return 0;
}
