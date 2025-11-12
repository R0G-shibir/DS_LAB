//Copy elements of a 2D array into a 1D/linear array and print the elements of group 3 from the 1D array.

#include <iostream>
using namespace std;

int main(){
    cout<<"Enter rows and columns of 2D Array: ";
    int row , col; cin>>row>>col;
    int arr[row][col];

    cout<<"Enter elements of 2D Array: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }

    int linearArr[row * col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            linearArr[i * col + j] = arr[i][j];
        }
    }

    cout<<"1D Array is: ";
    for(int i=0;i<row * col;i++){
        cout<<linearArr[i]<<" ";    
    }
    cout<<endl;

    cout<<"Elements of group 3 are: ";
    for(int i=(3-1)*col;i<3*col;i++){
        cout<<linearArr[i]<<" ";
    }
    cout<<endl;
    return 0;
}