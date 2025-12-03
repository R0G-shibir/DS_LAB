/*
    Write a program to delete an element from the heap
*/

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