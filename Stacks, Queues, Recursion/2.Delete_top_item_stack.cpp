//Delete the top elements of Stack.

#include <iostream>
#define MAX 100
using namespace std ;

class Stack{
private :
    int stack [MAX];
    int top ;

public:
    Stack(){
        top = -1;
    }

    //Function push item on stack
    void push (int data){
        if(top == MAX-1){
            cout<<"Stack Overflow"<<endl;
            return ;
        }
        stack[++top] = data;
    }

    //Function delete item from stack
    void pop(){
        if(top == -1){
            cout<<"Stack is empty! "<<endl;
            return ;
        }
        cout<<"Top item : "<<stack[top--]<<endl;
    }

    //Function to display elements of stack
    void display(){
        if(top == -1){
            cout<<"Stack is empty! "<<endl;
            return ;
        }
        cout<<"Elements of the stack : ";
        for(int i = top;i>=0;i--){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Stack s;

    cout<<"Enter the size of the stack : ";
    int n ;cin>>n;

    cout << "Enter " << n << " elements:" << endl;
    while(n--){
        int x;cin>>x;
        s.push(x);
    }

    s.display();
    s.pop();
    s.display();
    
    return 0;
}
