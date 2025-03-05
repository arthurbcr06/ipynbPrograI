
#include <iostream> 

using namespace std;

int main() {
    int n;
    cout << "Ingrese un número entero positivo: ";
    cin >> n;
    if (n > 0) {
        int suma = (n * (n + 1)) / 2;
        cout << "La suma de los primeros " << n << " enteros positivos es: " << suma << endl;
    } else {
        cout << "Por favor, ingrese un número entero positivo válido." << endl;
    }
    return 0;
}
