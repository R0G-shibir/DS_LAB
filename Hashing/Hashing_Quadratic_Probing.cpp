/*
    Write a program to store some data 
    (54, 26, 93, 17, 77, 31, 44, 55, 20) 
    to a hash table (Size of hash table is a prime number).
    While storing data if there is a collision 
    use the Quadratic Probing technique .Next search for
    an item .
*/

#include <iostream>
#define TABLE_SIZE 11
using namespace std;

int HASH_TABLE[TABLE_SIZE];

void init_Table(){
    for(int i = 0 ;i<TABLE_SIZE;i++){
        HASH_TABLE[i] = -1;
    }
}

int hash_Function(int key){
    return key % TABLE_SIZE;
}

void insert(int key){
    int index = hash_Function(key);
    if(HASH_TABLE[index] == -1){
        HASH_TABLE[index] = key;
        return;
    }

    int i = 1;
    int start_index = index;
    while(i < TABLE_SIZE){
        index = (start_index + (i*i)) % TABLE_SIZE;
        if(HASH_TABLE[index] == -1){
            HASH_TABLE[index] = key;
            return;
        }
        i++;  
    } 
    cout << "Hash table is full! Cannot insert " << key << endl;
}

void display(){
    cout<<"\nIndex  \tValue\n";
    for(int i = 0;i<TABLE_SIZE;i++){
        cout<<"   "<<i<<"\t  "<<HASH_TABLE[i]<<endl;
    }
}

void search(int key){
    int index = hash_Function(key);
    if(HASH_TABLE[index] == key){
        cout<<"Element is found at index : "<<index<<endl;
        return;
    }
    int start_index = index;
    int i = 1; 
    while(i < TABLE_SIZE){
        index = (start_index + (i*i)) % TABLE_SIZE;
        if(HASH_TABLE[index] == key){
            cout<<"Element is found at index : "<<index<<endl;
            return;
        }
        else if(HASH_TABLE[index] == -1){
            cout<<"Element is not found"<<endl;
            return;
        }
        i++;  
    } 
    cout<<"Element is not found"<<endl;
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