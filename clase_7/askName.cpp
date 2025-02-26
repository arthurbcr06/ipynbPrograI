#include <iostream> 
using namespace std;
int main(){
    string nombre, apellido; 
    cout<<"Escribe tu nombre : ";
    cin>>nombre;
    cout<<"Escribe tu apellido :";
    cin>>apellido;
    getLIne(cin, nombre);
    cout<< "Hola "<<nombre<<" "<<apellido<<endl;
    return 0;
}
