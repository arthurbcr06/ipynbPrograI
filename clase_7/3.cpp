#include <iostream>
using namespace std;
int main(){
    double largo, ancho;
    cout<<"Escribe el largo (en metros) : ";
    cin>>largo;
    cout<<"EScribe el ancho (en metros):";
    cin>>ancho;
    float area = largo * ancho;
    cout<<"El area es "<<area<<" metros cuadrados"<<endl;
    return 0;
}
