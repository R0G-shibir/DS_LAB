// Insert an element into a queue.

#include <iostream>
#define MAX 100
using namespace std;

class Queue{
    private:
        int front, rear;
        int arr[MAX];
    public:
        Queue(){
            front = -1;
            rear = -1;
        }
        void insert(int value){
            if(rear == MAX - 1){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            if(front == -1){
                front = 0;
            }
            arr[++rear] = value;
        }
        void display(){
            if(front == -1 || front > rear){
                cout<<"Queue is empty"<<endl;
                return;
            }
            for(int i = front; i <= rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){

    Queue q;
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);

    cout<<"Current Queue: ";
    q.display();    
    return 0;
}