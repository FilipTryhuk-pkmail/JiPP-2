//
// Created by anon on 10/29/21.
//

#ifndef JIPP_2_MATRIX_H
#define JIPP_2_MATRIX_H

int **addMatrix(int **mat1, int **mat2, int rows, int cols);
int **subtractMatrix(int **mat1, int **mat2, int rows, int cols);
int **multiplyMatrix(int **mat1, int **mat2, int rows, int cols1, int cols2);
int **multiplyByScalar(int **mat, int rows, int cols, int scalar);
int **transposeMatrix(int **mat, int rows, int cols);
int **powerMatrix(int **mat, int rows, int cols, unsigned degree);
int determinantMatrix(int **mat, int rows, int cols);
bool matrixIsDiagonal(int **mat, int rows, int cols);
void swap(int &a, int &b);
void sortRow(int arr[], int cols);
void sortRowsInMatrix(int **mat, int rows, int cols);


double **addMatrix(double **mat1, double **mat2, int rows, int cols);
double **subtractMatrix(double **mat1, double **mat2, int rows, int cols);
double **multiplyMatrix(double **mat1, double **mat2, int rows, int cols1, int cols2);
double **multiplyByScalar(double **mat, double rows, int cols, double scalar);
double **transposeMatrix(double **mat, int rows, int cols);
double **powerMatrix(double **mat, int rows, int cols, unsigned degree);
double determinantMatrix(double **mat, int rows, int cols);
bool matrixIsDiagonal(double **mat, int rows, int cols);
void swap(double &a, double &b);
void sortRow(double arr[], int cols);
void sortRowsInMatrix(double **mat, int rows, int cols);


#endif //JIPP_2_MATRIX_H
