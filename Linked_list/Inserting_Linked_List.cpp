/*
Inserting: carry out the following operations on a Linked List 
    a) 54 to a sorted array. 
    b) Rahim to a sorted array. 
    c) 99 to position 5. 
    d) Karim to position 5.
*/

#include <iostream>
using namespace std;

struct Node{
    string data;
    Node *next;
};

//Function to display Linked List
void display(Node *ptr){
    while(ptr != nullptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){

    

}
