/*
Searching : carry out the following operations on a Linked List
    a) Search for 77 using Linear/Binary Search.
    b) Search for Karim using Linear/Binary Search.
*/
#include <iostream>
using namespace std;

struct Node{
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

// Function to search a value in Linked List (linear search)
void linearSearch(Node *head,string data){
    int pos = 0;
    while (head != nullptr){
        pos++;
        if(head->data == data){
            cout<<data<<" found in the list at pos "<<pos<<endl;
            return;
        }
        head = head->next;
    }
    cout << data << " not found in the list." << endl;
}

int main (){

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

    linearSearch(head,"77");

    linearSearch(head,"Karim");

}