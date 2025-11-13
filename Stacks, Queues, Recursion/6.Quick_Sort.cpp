//Sort 10 integer data using Quick-Sort algorithm.

#include <iostream>
using namespace std;

int Partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high){
    if(low < high){

        int j = Partition(arr, low, high);

        QuickSort(arr, low, j - 1);
        QuickSort(arr, j + 1, high);
    }    
}

void DisplayArray(int arr[], int n){
    for(int i =0 ;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    int arr[10] = {34, 7, 23, 32, 5, 62, 32, 4, 3, 12};
    int n = 10;
    cout<<"Original Array: ";
    DisplayArray(arr, n);

    QuickSort(arr, 0, n - 1);
    cout<<"Sorted Array: ";
    DisplayArray(arr, n);

    return 0;

}