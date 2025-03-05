
#include <iostream> 

using namespace std; 

int main() {
    int widgets, grizmos, pesoTotalWidgets, pesoTotalGrizmos, pesoTotal;
    const int pesoWidget = 75;
    const int pesoGrizmo = 112;

    cout << "Ingrese cuantos Widgets quiere comprar: ";
    cin >> widgets;
    
    cout << "Ingrese cuantos Grizmos quiere comprar: ";
    cin >> grizmos;

    pesoTotalWidgets = pesoWidget * widgets;
    pesoTotalGrizmos = pesoGrizmo * grizmos;
    pesoTotal = pesoTotalWidgets + pesoTotalGrizmos;

    cout << "El peso total es: " << pesoTotal << " gramos" << endl;

    return 0;
}
