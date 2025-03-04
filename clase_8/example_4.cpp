
#include <iostream> 

using namespace std;

int main(){
    for(i=0;i<=5;i++){
        switch(i){
            case 0:
            std::cout<<"i is less than one"<<endl;
            case 1:
            std::cout<<"i is less than two"<<endl;
            case 2:
            std::cout<<"i is less than three"<<endl;
            case 3:
            std::cout<<"i is less than four"<<endl;
            case 4:
            std::cout<<"i is less than five"<<endl;
        }
        std::cout<<" "<<endl;
    }
    return 0;
}
