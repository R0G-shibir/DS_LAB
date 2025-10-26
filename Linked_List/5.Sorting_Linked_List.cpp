//Sorting: Sort the contents of a list.

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display (Node *ptr){
    cout<<"Elements of the List : ";

    while(ptr != nullptr){
        cout<<ptr->data<< " ";
        ptr = ptr->next; 
    }
    cout<<endl;
}
//Function to sort the Linked List
void sort(Node* head){
    if(head == nullptr ) return ;

    Node *i,*j;
    int temp;

    for( i = head ; i->next != nullptr ;i = i->next ){
        for( j = i->next ; j != nullptr ; j = j->next){
            if(i-> data > j->data){
                temp = i->data ;
                i->data = j->data;
                j->data = temp ;
            }
        }
    }
}

int main (){

    cout<<"Enter the size of List : "<<endl;
    int n;cin>>n;

    cout<<"Enter the data : ";

    Node *head = nullptr;
    Node *tail = nullptr;

    while(n--){
        int x;cin>>x;
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

    sort(head);

    display(head);

}