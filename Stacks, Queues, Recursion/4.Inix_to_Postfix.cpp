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

bool IsOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string Infix_to_Postfix(string infix){
    stack<char>s;
    string postfix = "";

    s.push('(');
    infix += ')';
    for(int i=0;i<infix.length();i++){
        if(infix[i] == '('){
            s.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(!s.empty() && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if(!IsOperator(infix[i])){
            postfix += infix[i];
        }
        else if(IsOperator(infix[i])){
            while(!s.empty() && 
                ((Precedence(infix[i]) < Precedence(s.top())) || 
                (Precedence(infix[i]) == Precedence(s.top()) && infix[i] != '^'))){
                    postfix += s.top();
                    s.pop();
            }
            s.push(infix[i]);
        }
    }
    return postfix;
}


int main(){

    cout<<"Enter Infix Expression : ";
    string infix;cin>>infix;

    cout << "Postfix Expression: " << Infix_to_Postfix(infix) << endl;
    return 0;

}