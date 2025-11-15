/*
    Write a program to store some data to a hash table
    (Size of hash table is a prime number). Before storing
    data perform the Folding Method Hash function. While
    storing data if there is a collision use the Linear Probing technique.
    Next search for an item.
*/

#include <iostream>
#define TABLE_SIZE 11
using namespace std;

int HASH_TABLE[TABLE_SIZE];
void init_Table(){
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HASH_TABLE[i] = -1;
    }
}

int hash_Function(int key){
    int sum = 0;
    while (key > 0) {
        sum += key % 100;
        key /= 100;
    }
    return sum % TABLE_SIZE;
}

void insert(int key){
    int index = hash_Function(key);
    int start_index = index;

    while (HASH_TABLE[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) {
            cout << "Hash table is full! Cannot insert " << key << endl;
            return;
        }
    }

    HASH_TABLE[index] = key;
}

void search(int key){
    int index = hash_Function(key);
    int start_index = index;

    while (HASH_TABLE[index] != -1) {
        if (HASH_TABLE[index] == key) {
            cout << "Element is found at index: " << index << endl;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start_index) {
            break;
        }
    }

    cout << "Element is not found" << endl;
}

void display(){
    cout << "\nIndex\tValue\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << " " << i << "\t" << HASH_TABLE[i] << endl;
    }
}

int main(){
    int data[] = {
        123456,
        654321,
        129900,
        991200,
        341256,
        563412,
        778899,
        889977,
        450045,
        220011
    };

    int size = sizeof(data) / sizeof(data[0]);

    init_Table();

    for (int i = 0; i < size; ++i) {
        insert(data[i]);
    }

    display();

    search(220011);
    search(606060);
    search(123);

    return 0;
}