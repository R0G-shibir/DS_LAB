/*
    Write a program to store some data to a hash table
    (Size of hash table is a prime number). Before storing
    data perform the Character Based Method Hash function. While
    storing data if there is a collision use the Linear Probing
    technique.Next search for an item.
*/

#include <iostream>
#define TABLE_SIZE 11
using namespace std;

int Hash_Table[TABLE_SIZE];

void init_Table(){
    for(int i =0;i<TABLE_SIZE;i++){
        Hash_Table[i] = -1;
    }
}

int hash_Function(int key){
    int sum = 0;
    while(key > 0){
        int digit = key % 10;
        char ch = digit + '0';
        sum+= int (ch);
        key /= 10;
    }
    return sum % TABLE_SIZE;
}

void insert(int key){
    int index = hash_Function(key);
    int startIndex = index ;

    while(Hash_Table[index] != -1){
        index = (index + 1) % TABLE_SIZE;
        if(startIndex == index){
            cout << "Hash table is full! Cannot insert " << key << endl;
            return ;
        }
    }
    Hash_Table[index] = key;
}

void display(){
    cout<<"\nIndex  \tValue\n";
    for(int i = 0;i<TABLE_SIZE;i++){
        cout<<"   "<<i<<"\t  "<<Hash_Table[i]<<endl;
    }
}

void search(int key){
    int index = hash_Function(key);
    int start_index = index;

    while(Hash_Table[index] != -1){
        if(Hash_Table[index] == key){
            cout<<"Element is found at index : "<<index<<endl;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if(index == start_index){
            break;
        }
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
    search(26);
    search(100);
    return 0;
}