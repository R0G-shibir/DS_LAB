//Find the value of a Arithmetic expression P written in Postfix notation.

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

// Function to evaluate a postfix expression
int eval_Postfix(string v){

    stack<int>s;
    stringstream ss(v);
    string token;
    while(ss >> token){
        if(isdigit(token[0]) || (token.size()>1 && token[0] == '-')){
            s.push(stoi(token));
        }
        else{
            int num1 = s.top(); s.pop();
            int num2 = s.top(); s.pop();
            
            switch(token[0]){
                case '+':
                    s.push(num1 + num2);
                    break;
                case '-':
                    s.push(num2 - num1);
                    break;
                case '*':
                    s.push(num1 * num2);
                    break;
                case '/':
                    s.push(num2 / num1);
                    break;
            }
        }
    }
    return s.top();
}

int main(){
    
    vector<string>v {
        "12 3 + 4 *",                     // 60
        "15 7 1 1 + - / 3 * 2 1 1 + + -", // 5
        "5 1 2 + 4 * + 3 -",              // 14
        "10 2 8 * + 3 -",                 // 23
        "7 2 3 * - 4 +",                  // 5
        "3 4 + 2 * 7 /",                  // 2
        "6 5 2 3 + 8 * + 3 + -",          // -42
        "4 2 + 3 5 1 - * +",              // 18
        "9 3 / 2 1 + * 5 -",              // 4
        "15 7 1 1 + - / 3 * 2 1 1 + + -"  // 5
    };

    for(int i = 0; i < v.size(); i++ ){

        cout<<eval_Postfix(v[i])<<endl;

    }

    return 0;

}