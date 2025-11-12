/*
    Sorting: 
        a) Sort integer data using Bubble sort. 
        b) Sort string data using Bubble sort.
*/
#include <iostream>
using namespace std;

void bubble_sort(int arr[],int size){

    for(int i = 0;i<size;i++){
        for(int j = i+1;j<size;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubble_sort(string arr[],int size){

    for(int i = 0;i<size;i++){
        for(int j = i+1;j<size;j++){
            if(arr[i]>arr[j]){
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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

    int arr_int[10] = {64,34,25,12,22,36,55,44,11,90};
    int size_int = 10;

    display(arr_int,size_int);
    bubble_sort(arr_int,size_int);
    display(arr_int,size_int);

    string arr_str[7] = {"Zain","Ali","Omar","Kareem","Nabil","Sami","Tariq"};
    int size_str = 7;

    display(arr_str,size_str);
    bubble_sort(arr_str,size_str);
    display(arr_str,size_str);

    return 0;
    
}