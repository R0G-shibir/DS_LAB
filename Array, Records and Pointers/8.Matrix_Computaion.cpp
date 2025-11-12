//Matrix: Addition/Subtraction/Multiplication of two matrices.

#include <iostream>
using namespace std;

void Matrix_Addition(int mat1[5][5], int mat2[5][5], int result[5][5]) {
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void Matrix_Subtraction(int mat1[5][5], int mat2[5][5], int result[5][5]) {
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void Matrix_Multiplication(int mat1[5][5], int mat2[5][5], int result[5][5]) {
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            result[i][j] = 0;
            for(int k =0;k<5;k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void display_Matrix(int mat[5][5]) {
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    
    int matrix1[5][5] = {
        { 1, 2, 3, 4, 5},
        { 6, 7, 8, 9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    int matrix2[5][5] = {
        {25,24,23,22,21},
        {20,19,18,17,16},
        {15,14,13,12,11},
        {10, 9, 8, 7, 6},
        { 5, 4, 3, 2, 1}
    };

    int sum[5][5], diff[5][5], prod[5][5];
    
    Matrix_Addition(matrix1, matrix2, sum);
    display_Matrix(sum);

    Matrix_Subtraction(matrix1, matrix2, diff);
    display_Matrix(diff);

    Matrix_Multiplication(matrix1, matrix2, prod);
    display_Matrix(prod);

    return 0;

}