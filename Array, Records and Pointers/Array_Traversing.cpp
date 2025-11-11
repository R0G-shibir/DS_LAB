#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int Max_value(int arr[], int size ){

    int max = INT_MIN;
    for(int i = 0 ;i<size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;

}

int Min_value(int arr[], int size ){

    int min = INT_MAX;
    for(int i = 0 ;i<size;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;

}

int Total(int arr[], int size ){

    int sum = 0;
    for(int i = 0 ;i<size;i++){
        sum += arr[i];
    }
    return sum;

}

double Average_Value(int arr[], int size ){

    double total = Total(arr , size);
    
    return total/size;

}

void Sine (int arr[],int size){

    cout<<"Sine Values (in degree):"<<endl;
    for(int i =0 ;i<size;i++){
        double radians = arr[i] * (M_PI / 180.0);
        cout<<"sine("<<arr[i]<<"°) = "<<sin(radians)<<endl;
    }

}

int main(){

    int arr[] = {1 , 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Maximum Value : "<< Max_value(arr,n) <<endl;

    cout<<"Minimum Value : "<< Min_value(arr,n) <<endl;

    cout<<"Total Value : "<< Total(arr,n) <<endl;

    cout<<"Average_Value : "<< Average_Value(arr,n) <<endl;

    Sine(arr,n);

}