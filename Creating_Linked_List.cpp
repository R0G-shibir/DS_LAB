//Create a Linked List and store the value 5, 3, 9, 42, 0, 10.

#include <iostream>
using namespace std;

struct Node{
    
    int data;
    Node *next;

};
//Function to create Node  
Node* createNode (int x) {

    Node* newNode = new Node {x,nullptr};
    return newNode;

}

int main(){

    cout<<"Enter the size of List : "<<endl;
    int n;cin>>n;

    cout<<"Enter the data : "<<endl;

    Node *head = nullptr;

    Node *tail = nullptr;

    while(n--){

        int x;cin>>x;
        Node *current = createNode(x);

        if(head==nullptr){
            head=tail=current;
        }
        else{
            tail->next=current;
            tail = tail->next;
        }

    }

    //Display Nodes to Console 
    Node *ptr = head;
    cout<<"\nLinked List : ";
    while (ptr != NULL){

        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
    
    return 0;

}