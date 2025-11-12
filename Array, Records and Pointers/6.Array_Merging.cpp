/*
6. Merging:
    a) Add two integer type arrays.
    b) Add two character type arrays.
*/

#include <iostream>
using namespace std;


void merge_int(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int k = 0;
    for(int i = 0; i < size1; i++)
        result[k++] = arr1[i];
    for(int i = 0; i < size2; i++)
        result[k++] = arr2[i];
}

void merge_char(char arr1[], int size1, char arr2[], int size2, char result[]) {
    int k = 0;
    for(int i = 0; i < size1; i++)
        result[k++] = arr1[i];
    for(int i = 0; i < size2; i++)
        result[k++] = arr2[i];
}

void display(int arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void display(char arr[], int size) {
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int size1 = 4, size2 = 4;
    int merged_int[size1 + size2];

    merge_int(arr1, size1, arr2, size2, merged_int);
    cout << "Merged integer array: ";
    display(merged_int, size1 + size2);

    char arr_char1[] = {'A', 'B', 'C'};
    char arr_char2[] = {'X', 'Y', 'Z'};
    int size_char1 = 3, size_char2 = 3;
    char merged_char[size_char1 + size_char2];

    merge_char(arr_char1, size_char1, arr_char2, size_char2, merged_char);
    cout << "Merged character array: ";
    display(merged_char, size_char1 + size_char2);

    return 0;
}
