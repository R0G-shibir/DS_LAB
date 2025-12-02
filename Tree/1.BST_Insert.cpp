/*
    Write a program to insert an element in a Binary search tree;
    if the element already inserted before then display the location.
*/

#include <iostream>
using namespace std;

struct Node {
    int data ;
    Node* left;
    Node* right ;

    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool bst_search (Node *root , int data, string &path){
    
    if(root == nullptr) return false;

    if (root->data == data) return true;

    if(root->data > data) {
        path += " -> L";
        return bst_search(root -> left , data , path);
    }
    else{
        path += " -> R";
        return bst_search(root -> right, data , path);
    }

}

Node* insert(Node *root,int data){

    string path = "Root ";

    if(bst_search(root,data,path)){
        cout<<data<<" Element already in the Tree at "<<path<<endl;
        return root;
    }
    
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    else if(data < root->data){
        root->left = insert(root->left , data);
    }
    else{
        root->right = insert(root->right , data);
    }   
    return root;
}

int main(){
    Node *root = NULL;
    int arr[] = { 10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90, 100 ,
                  10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90, 100 };
    int n = sizeof(arr) / sizeof (arr[0]);
    for(int i = 0 ;i < n;i++){
        root = insert(root,arr[i]);
    }
    return 0;
}
