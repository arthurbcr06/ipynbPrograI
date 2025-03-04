#include <iostream> 
using namespace std;
int main(){
    char choice;
    std::cout<<"HElp on:"<<endl;
    std::cout<<"1. if"<<endl;
    std::cout<<"2. switch"<<endl;
    std::cout<<"Choose one :"<<endl;  
    std::cin>>choice;
    
    switch(choice){
        case'1':
        std::cout<<"The if:\n"<<endl;
        std::cout<<"If(condition) statement;"<<endl;
        std::cout<<"else statement;"<<endl;
        break;
        case'2':
        std::cout<<"The switch:\n"<<endl;
        std::cout<<"switch(expression) {"<<endl;
        std::cout<<"case cosntant :"<<endl;
        std::cout<<"statement sequence"<<endl;
        std::cout<<"break;"<<endl;
        std::cout<<"/"<<"/..."<<endl;
        std::cout<<"}"<<endl;
        break;
        defaul:
        std::cout<<"Selection not found."<<endl;
    }
    return 0;
}
