/*
    Write a program to store some data to a hash table
    (Size of hash table is a prime number). Before storing
    data perform the Mid Square Method Hash function. While
    storing data if there is a collision use the Chaining
    technique.Next search for an item.
*/

#include <iostream>
#define TABLE_SIZE 11
using namespace std;

struct Node {
    int key;
    Node* next; 
};

Node* HASH_TABLE[TABLE_SIZE];

void init_Table(){
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HASH_TABLE[i] = nullptr;
    }
}

int hash_Function(int key){
    long long square = 1LL * key * key;
    string s = to_string(square);
    int len = s.length();
    int mid = len / 2;
    string mid_digit;
    if(len >= 2){
        mid_digit = s.substr(mid - 1, 2);
    }
    else{
        mid_digit = s;
    }
    return stoi(mid_digit) % TABLE_SIZE;
}

void insert(int key){
    int index = hash_Function(key);
    Node * newNode = new Node();
    newNode->key = key;
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
    for(int i = 0;i<TABLE_SIZE;i++){
        cout<<i<<" \t";
        Node *temp = HASH_TABLE[i];
        while(temp != nullptr){
            cout<<temp->key<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

void search(int key){
    int index = hash_Function(key);
    Node* temp = HASH_TABLE[index];
    
    while(temp != nullptr){
            if(temp->key == key){
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
