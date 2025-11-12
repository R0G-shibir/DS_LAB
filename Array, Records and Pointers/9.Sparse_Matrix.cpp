//Sparse Matrix: Store the element of a Triangular matrix A into a 1D array B and locate the elements A32 in the array B.

#include <iostream>
using namespace std;

int main(){

    int sparseMatrix[5][5] = {
        { 1,  0,  0,  0,  0},
        { 2,  3,  0,  0,  0},
        { 4,  5,  6,  0,  0},
        { 7,  8,  9, 10,  0},
        {11, 12, 13, 14, 15}
    };

    int LinerArray[15];
    int index = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            LinerArray[index++] = sparseMatrix[i][j];
        }
    }
    
    cout<<"Enter the position to locate (row and column): ";
    int row, col; cin>>row>>col;
    cout<<"Element at position A"<<row<<col<<" is: ";
    cout<<LinerArray[(row*(row-1))/2 + (col-1)]<<endl;

    return 0;

}