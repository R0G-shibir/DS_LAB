//Create a Linked List and store the value 5, 3, 9, 42, 0, 10.

#include <iostream>
using namespace std;

struct Node{
    
    int data;
    Node *next;

};

int main(){

    cout<<"Enter the size of List : "<<endl;
    int n;cin>>n;

    cout<<"Enter the data : "<<endl;
    int x;cin>>x;

    Node *head = new Node {x,NULL};

    Node *temp = head;
    n--;

    while(n--){

        int y;cin>>y;
        Node *current = new Node {y,NULL};

        temp->next = current;
        temp = temp->next;

    }

    Node *ptr = head;
    while (ptr != NULL){

        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
    
    return 0;

}