/*
Deleting: carry out the following operations on a Linked List
    a)Delete Karim from a sorted array. 
    b) Delete an Item from position 2.
*/
#include <iostream>
using namespace std;

struct Node{
    string data;
    Node *next;
};

void display(Node *ptr){
    cout<<"Elements of the List : ";

    while(ptr != nullptr){
        cout<<ptr->data<< " ";
        ptr = ptr->next; 
    }
    cout<<endl;
}

// Function to delete a node by value
Node* deleteByValue(Node* &head , string data){
    if(head == nullptr) return head;

    if(head->data == data){
        Node *temp = head;
        head = temp->next;
        delete temp;
        return head;
    }

    Node *current = head ;
    while(current->next != nullptr && current->next->data != data){
        current = current->next ;
    }

    if(current->next != nullptr){
        Node *temp = current->next ;
        current->next = current->next->next;
        delete temp ;
    }
    else{
        cout<<"Not found in the list "<<endl;
    }
    
    return head;

}

// Function to delete a node by position
Node* deleteByPosition(Node* &head,int pos){
    if(head == nullptr || pos <= 0) return head ;

    if(pos == 1){
        Node *temp = head ;
        head = temp->next ;
        delete temp ;
        return head ;
    }
    
    Node *current = head ;
    for(int i = 1 ;i < pos -1 && current != nullptr ;i++){
        current = current->next;
    }

    if(current == nullptr || current->next == nullptr){
        cout<<"Position is out of range "<<endl;
        return head ;
    }
    
    Node *temp = current->next ;
    current->next = current->next->next;
    delete temp;
    return head ;

}

int main(){

    cout<<"Enter the size of List : "<<endl;
    int n;cin>>n;

    cout<<"Enter the data : ";

    Node *head = nullptr;
    Node *tail = nullptr;

    while(n--){
        string x;cin>>x;
        Node *current = new Node {x,nullptr};

        if(head==nullptr){
            head=tail=current;
        }
        else{
            tail->next=current;
            tail = tail->next;
        }
    }

    display(head);

    cout<<"After removing Karim ";

    display(deleteByValue(head , "Karim"));

    cout<<"After removing position 2 ";

    display(deleteByPosition(head,2));

}