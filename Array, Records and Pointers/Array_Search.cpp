/*
     Searching:
        a) Search for 77 using Linear/Binary Search.
        b) Search for “Karim” using Linear/Binary Search
*/

#include <iostream>
using namespace std;

void Binary_search(int ar[],int size,int key){
    int mid,low=0,high=size-1;
    while(low<=high){
        mid = (high + low)/2;
        if(ar[mid] == key){
            cout << "Found at index: " << mid+1 << endl;
            return ;
        }
        else if(ar[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << "Not Found" << endl;
}

void Linear_search(string names[], int names_size, string key){
    for(int i=0; i<names_size; i++){
        if(names[i] == key){
            cout << "Found at index: " << i+1 << endl;
            return ;       
        }
    }
    cout << "Not Found" << endl;
}

int main(){

    int arr[] = {1, 11 , 22, 33, 44, 55, 66, 77, 88, 99};
    int size = sizeof(arr)/sizeof(arr[0]);
    Binary_search(arr, size, 77);

    string names[] = {"Arafat", "Karim", "Rahim", "Jabbar", "Sakib", "Tamim", "Shakib"};
    int names_size = sizeof(names)/sizeof(names[0]);
    Linear_search(names, names_size, "Karim");

    return 0;

}