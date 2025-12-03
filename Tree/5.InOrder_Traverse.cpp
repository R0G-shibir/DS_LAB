/*
    Traverse the tree in inorder
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