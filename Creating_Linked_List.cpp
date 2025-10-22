//Create a Linked List and store the value 5, 3, 9, 42, 0, 10.

#include <iostream>
using namespace std;

struct Node{
    
    int data;
    Node *next;

};

int main(){

    Node *head = new Node {5,nullptr};

    Node *temp = new Node {3,nullptr};
    head->next = temp;

    temp->next = new Node {9,nullptr};
    temp = temp->next;

    temp->next = new Node {42,nullptr};
    temp = temp->next;

    temp->next = new Node {0,nullptr};
    temp = temp->next;

    temp->next = new Node {10,nullptr};

    Node *current = head;

    while(current!=nullptr){

        cout<<current->data<<" ";

        current = current->next;

    }

    cout<<endl;

}