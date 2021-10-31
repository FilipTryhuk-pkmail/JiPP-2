//
// Created by anon on 10/29/21.
//

#include <iostream>
#include <cmath>

using namespace std;

// INT

int **addMatrix(int **mat1, int **mat2, int rows, int cols) {

    int** res = new int *[rows];
    for(int i = 0; i < rows; i++)
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

int **multiplyByScalar(int **mat, int rows, int cols, int scalar) {

    int** res = new int *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new int[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = mat[i][j] * scalar;
        }
    }

    return res;
}

int **transposeMatrix(int **mat, int rows, int cols){

    int** res = new int *[cols];
    for(int i = 0; i < cols; ++i)
        res[i] = new int[rows];

    for (int i=0; i<cols; i++) {
        for (int j=0; j<rows; j++) {
            res[i][j] = mat[j][i];
        }
    }

    return res;
}

int **powerMatrix(int **mat, int rows, int cols, unsigned degree){

    int** res = new int *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new int[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = int (pow(mat[i][j], degree));
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

void sortRow(int arr[], int cols) {

    bool finished;
    for (int i=0; i<(cols-1); i++) {
        finished = true;
        for (int j=0; j<(cols-1-i); j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                finished = false;
            }
        }
        if (finished) {break;}
    }
}

void sortRowsInMatrix(int **mat, int rows, int cols) {

    for (int i=0; i<rows; i++) {
        sortRow(mat[i], cols);
    }
}





// DOUBLE

double **addMatrix(double **mat1, double **mat2, int rows, int cols) {

    double **res = new double *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new double[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return res;
}

double **subtractMatrix(double **mat1, double **mat2, int rows, int cols) {

    double **res = new double *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new double[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    return res;
}

double **multiplyMatrix(double **mat1, double **mat2, int rows, int cols1, int cols2) {

    double **res = new double *[rows];
    for(int i = 0; i<rows; ++i)
        res[i] = new double[cols2];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols2; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return res;
}

double **multiplyByScalar(double **mat, int rows, int cols, double scalar) {

    double** res = new double *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new double[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] = mat[i][j] * scalar;
        }
    }

    return res;
}

double **transposeMatrix(double **mat, int rows, int cols){

    double **res = new double *[cols];
    for(int i = 0; i < cols; ++i)
        res[i] = new double[rows];

    for (int i=0; i<cols; i++) {
        for (int j=0; j<rows; j++) {
            res[i][j] = mat[j][i];
        }
    }

    return res;
}

double **powerMatrix(double **mat, int rows, int cols, unsigned degree){

    double **res = new double *[rows];
    for(int i = 0; i < rows; ++i)
        res[i] = new double[cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            res[i][j] =  pow(mat[i][j], degree);
        }
    }

    return res;
}

double determinantMatrix(double **mat, int rows, int cols) {

    double det = 0;

//    double **sub = new double *[rows];
//    for(int i = 0; i < rows; ++i)
//        sub[i] = new double[cols];

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

bool matrixIsDiagonal(double **mat, int rows, int cols) {

    bool diagonal = true;

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (i==j) {continue;}
            if (abs(mat[i][j]) > 0.0001) {diagonal = false;}
        }
    }

    return diagonal;
}

void swap(double &a, double &b) {
    double c = a;
    a = b;
    b = c;
}

void sortRow(double arr[], int cols) {

    bool finished;
    for (int i=0; i<(cols-1); i++) {
        finished = true;
        for (int j=0; j<(cols-1-i); j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                finished = false;
            }
        }
        if (finished) {break;}
    }
}

void sortRowsInMatrix(double **mat, int rows, int cols) {

    for (int i=0; i<rows; i++) {
        sortRow(mat[i], cols);
    }
}