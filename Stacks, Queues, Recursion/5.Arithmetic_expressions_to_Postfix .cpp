//Find the value of an Arithmetic expression I written in Infix notation.

#include <iostream>
#include <stack>
using namespace std;

int OperatorPrecedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int operation(int num1 ,int num2 , char op){
    switch(op){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        case '^': {
            int res = 1;
            for(int i =0 ;i<num2;i++){
                res *= num1;
            }
            return res;
        }
    }
    return 0;
}

int Evaluate_Infix(string infix){
    stack<int> values;
    stack<char> ops;

    for(int i =0 ;i<infix.length();i++){
        if(infix[i] == ' '){
            continue;
        }
        else if(infix[i] == '('){
            ops.push(infix[i]);
        }
        else if(isdigit(infix[i])){
            int val = 0;
            while (i < infix.length() && isdigit(infix[i])) {
                val = (val * 10) + (infix[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }
        else if(infix[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                int res = operation(val1 , val2 , op);
                values.push(res);
            }
            if(!ops.empty()){
                ops.pop();
            }
        }
        else if(isOperator(infix[i])){
            while(!ops.empty() && OperatorPrecedence(ops.top()) >= OperatorPrecedence(infix[i])){
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();

                int res = operation(val1 , val2 , op);
                values.push(res);
            }
            ops.push(infix[i]);
        }
    }
    while(!ops.empty()){
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();

        int res = operation(val1 , val2 , op);
        values.push(res);
    }
    return values.top();
}
int main(){
    cout << "Enter the Infix expression: ";
    string infix;
    getline(cin , infix);

    cout << "The value of the Infix expression is: " << Evaluate_Infix(infix) << endl;
    return 0;  
     
}