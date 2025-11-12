//Transform an Infix expression into Postfix expression.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int Precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

int main(){


}