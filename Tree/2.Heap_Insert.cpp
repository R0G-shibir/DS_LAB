/*
    Write a program to insert an element into the heap
*/

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int data){
        this -> data = data;
        left = right = nullptr;
    }

};