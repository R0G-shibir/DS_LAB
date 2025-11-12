/*Inserting: Insert 
    a) 54 to a sorted array. 
    b) Rahim to a sorted array. 
    c) 99 to position 5. 
    d) Karim to position 5.
*/

#include <iostream>
using namespace std;

void insert_sorted(int arr[],int &size,int item){
    int temp = size;
    while(temp>=0 && arr[temp-1]>item){
        arr[temp] = arr[temp-1];
        temp--;
    }
    arr[temp] = item;
    size++;
}

void insert_sorted(string arr[],int &size,string item){
    int temp = size;
    while(temp>=0 && arr[temp-1]>item){
        arr[temp] = arr[temp-1];
        temp--;
    }
    arr[temp] = item;
    size++;
}

void insert_at(int arr[],int &size,int item,int pos){
    for(int i = size;i>pos-1;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = item;
    size++;
}

void insert_at(string arr[],int &size,string item,int pos){
    for(int i = size;i>pos-1;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = item;
    size++;
}

void display(int arr[],int size){
    cout<<"Array elements: ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void display(string arr[],int size){
    cout<<"Array elements: ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main (){
    //array for integers
    int arr[20] = {1,10,20,30,40,50,60,70,80,90};
    int size = 10;

    insert_sorted(arr,size,54);
    display(arr,size);

    insert_at(arr,size,99,5);
    display(arr,size);

    //array for strings
    string arr_str[20] = {"Amin","Babul","Dabul","Jabbar","Kalu","Lalu","Mintu","Raju","Shanu","Tanu"};
    int size_str = 10;

    insert_sorted(arr_str,size_str,"Rahim");
    display(arr_str,size_str);

    insert_at(arr_str,size_str,"Karim",5);
    display(arr_str,size_str);

    return 0;

}