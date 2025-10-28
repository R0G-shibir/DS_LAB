//Calculate the FN of a Fibonacci sequence using recursive technique.

#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main() {
    
    cout << "Enter the position (n): ";
    int n;cin >> n;
    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
    return 0;
}