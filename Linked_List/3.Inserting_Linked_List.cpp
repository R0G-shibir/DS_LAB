/*
Inserting: carry out the following operations on a Linked List 
    a) 54 to a sorted Linked List.
    b) Rahim to a sorted Linked List.
    c) 99 to position 5. 
    d) Karim to position 5.
*/

#include <iostream>
using namespace std;

struct Node {
    string data;
    Node *next;
};

//Funtion to display the Linked List
void display(Node *ptr){
    cout<<"Elements of the list : ";

    while(ptr != nullptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

//Funtion to add element in a sorted list
void insert_sorted(Node* &head,string data){
    Node *newNode = new Node {data,nullptr};

    if( !head || data <head->data){
        newNode->next = head;
        head = newNode ;
        return ;
    }
    Node *temp = head ;
    while(temp->next && temp->next->data < data){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//Function to insert at certail position 
void insert_to (Node* &head,string data,int pos){
    Node *newNode = new Node {data , nullptr};

    if(pos == 1 ){
        newNode->next = head;
        head = newNode ;
        return ;
    }
    Node *temp = head;
    for(int i = 1 ;i < pos -1 && temp != nullptr;i++){
        temp =temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode ;
}

int main (){

    cout<<"Enter size of the List : ";
    int n;cin>>n;

    Node *head = nullptr;
    Node *tail = nullptr;
    cout<<"Enter elements of list : ";
    while(n--){

        string x;cin>>x;
        Node *current = new Node {x,nullptr};

        if(head == nullptr){
            head = tail =current;
        }
        else{
            tail->next = current;
            tail = tail->next;
        }
    }

    cout << "\nInitial Linked List:";
    display(head);

    cout << "\nPerforming operations...\n";

    // a) Insert 54 in sorted list
    insert_sorted(head, "54");
    cout << "After inserting 54 (sorted):";
    display(head);

    // b) Insert Rahim in sorted list
    insert_sorted(head, "Rahim");
    cout << "After inserting Rahim (sorted):";
    display(head);

    // c) Insert 99 at position 5
    insert_to(head, "99", 5);
    cout << "After inserting 99 at position 5:";
    display(head);

    // d) Insert Karim at position 5
    insert_to(head, "Karim", 5);
    cout << "After inserting Karim at position 5:";
    display(head);

    return 0;

}

