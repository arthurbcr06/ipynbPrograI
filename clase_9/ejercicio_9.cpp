
#include <iostream> 

using namespace std;

int main(){

    double saldo, saldo1, saldo2, saldo3; 
    const double interes = 0.04;
    cout << "Ingrese la cantidad de dinero :"<<endl;
    cin >> saldo;
    saldo1 = saldo * 1.04;
    saldo2= saldo1*1.04;
    saldo3 = saldo2*1.04;
    cout<<"Saldo inicial : "<<saldo<<endl<<"Saldo ano 1 : "<<saldo1<<endl<<"Saldo ano 2 :"<<saldo2<<endl<<" Saldo ano 3 :"<<saldo3<<endl;

    return 0;
}
