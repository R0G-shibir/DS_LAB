//Calculate the factorial of a given number using recursive technique.

#include <iostream>
using namespace std;

int fact(int x){
    if(x == 1 || x == 0){
        return 1;
    }
    else{
        return x*fact(x-1);
    }
}
int main(){
    cout<<"Enter the value : ";

    int x;cin>>x;
    cout<<"Factorial of "<<x<<" is "<<fact(x)<<endl;
}