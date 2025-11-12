/*
    Deleting: 
        a) Delete Karim from a sorted array.
        b) Delete an Item from position 2.
*/

#include <iostream>
using namespace std;

void delete_item(string arr[],int &size,string item){
    int index = -1;
    for(int i = 0;i<size;i++){
        if(arr[i]==item){
            index = i;
            break;
        }
    }
    if(index!=-1){
        for(int i = index;i<size-1;i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    else{
        cout<<"Item not found!"<<endl;
    }
}

void delete_at(string arr[],int &size,int pos){

    if(pos<0 || pos>=size){
        cout<<"Invalid position!"<<endl;
        return;
    }
    for(int i = pos-1;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
}

void display(string arr[],int size){
    cout<<"Array elements: ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    string arr[10] = {"Ahmed","Karim","Nabil","Omar","Sami","Tariq"};
    int size = 6;

    delete_item(arr,size,"Karim");
    display(arr,size);

    delete_at(arr,size,2);
    display(arr,size);
}