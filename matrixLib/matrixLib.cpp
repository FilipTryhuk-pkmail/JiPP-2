//
// Created by anon on 10/29/21.
//

#include <iostream>
#include <cmath>

using namespace std;

int **addMatrix(int **mat1, int **mat2, int rows, int cols) {

    int** res = new int *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new int[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return res;
}

int **subtractMatrix(int **mat1, int **mat2, int rows, int cols) {

    int** res = new int *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new int[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    return res;
}

int **multiplyMatrix(int **mat1, int **mat2, int rows, int cols1, int cols2) {

    int** res = new int *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new int[cols2];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols2; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return res;
}

int **multiplyByScalar(int **mat1, int rows, int cols, int scalar) {

    int** res = new int *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new int[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = mat1[i][j] * scalar;
        }
    }

    return res;
}

int **transposeMatrix(int **mat1, int rows, int cols){

    int** res = new int *[cols];
    for(int i = 0; i < cols; ++i)
        res[i] = new int[rows];

    for (int i=0; i<cols; i++) {
        for (int j=0; j<rows; j++) {
            res[i][j] = mat1[j][i];
        }
    }

    return res;
}

int **powerMatrix(int **mat1, int rows, int cols, unsigned degree){

    int** res = new int *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new int[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = int (pow(mat1[i][j], degree));
        }
    }

    return res;
}

int determinantMatrix(int **mat, int rows, int cols) {

    int det = 0;

    int** sub = new int *[rows];
    for(int i = 0; i < rows; ++i)
        sub[i] = new int[cols];

    if(rows == 2) {
        det = ((mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]));
        return det;
    }

    if(rows == 3) {
        det += (mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1])));
        det -= (mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0])));
        det += (mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0])));
    }

    return det;
}

bool matrixIsDiagonal(int **mat, int rows, int cols) {

    bool diagonal = true;

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (i==j) {continue;}
            if (mat[i][j]) {diagonal = false;}
        }
    }

    return diagonal;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}




void butReally() {
    cout << "Really!" << endl;
}




