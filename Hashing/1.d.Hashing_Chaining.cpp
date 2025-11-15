/*
    Write a program to store some data 
    (54, 26, 93, 17, 77, 31, 44, 55, 20) 
    to a hash table (Size of hash table is a prime number).
    While storing data if there is a collision 
    use the Chaining technique .Next search for
    an item .
*/

#include <iostream>
#define TABLE_SIZE 11
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* HASH_TABLE[TABLE_SIZE];

void init_Table(){
    for(int i = 0;i<TABLE_SIZE;i++){
        HASH_TABLE[i] = nullptr; 
    }
}

int hash_Function(int key){
    return key % TABLE_SIZE;
}

void insert(int key ){
    int index = hash_Function(key);
    Node *newNode = new Node();
    newNode->data = key;
    newNode->next = nullptr;
    if(HASH_TABLE[index] == nullptr){
        HASH_TABLE[index] = newNode;
        return;
    }
    Node *temp = HASH_TABLE[index];
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}   

void display(){
    cout<<"\nIndex  \tValue\n";
    for(int i = 0 ;i<TABLE_SIZE;i++){
        cout<<i<<" \t";
        Node *temp = HASH_TABLE[i];
        while(temp != nullptr){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

void search(int key){
    int index = hash_Function(key);
    Node *temp = HASH_TABLE[index];

    while(temp != nullptr){
        if(temp->data == key){
            cout<<"Element is found at index : "<<index<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<"Element is  not found"<<endl;
}

int main(){

    int data[] = { 54, 26, 93, 17, 77, 31, 44, 55, 20};
    int size = sizeof(data) / sizeof(data[0]);
    init_Table();

    for(int i = 0;i<size;i++){
        insert(data[i]);
    }

    display();
    search(55);
    search(54);
    search(100);
    return 0;
}
