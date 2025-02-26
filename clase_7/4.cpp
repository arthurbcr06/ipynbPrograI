#include <iostream> 
using namespace std; 
int main(){
    float largo, ancho;
    cout<<"Ingrese el largo : ";
    cin>>largo;
    cout<<"Ingrese el ancho : ";
    cin>>ancho;
    double area_acres = (largo*ancho) / 43560;
    cout<<"EL area es : "<<area_acres<<" acres"<<endl;
    return 0;
}
