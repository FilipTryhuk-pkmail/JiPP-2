//
// Created by anon on 10/29/21.
//

#ifndef JIPP_2_MATRIX_H
#define JIPP_2_MATRIX_H

void butReally();
int **addMatrix(int **mat1, int **mat2, int rows, int cols);
int **subtractMatrix(int **mat1, int **mat2, int rows, int cols);
int **multiplyMatrix(int **mat1, int **mat2, int rows, int cols1, int cols2);
int **multiplyByScalar(int **mat1, int rows, int cols, int scalar);
int **transposeMatrix(int **mat1, int rows, int cols);
int **powerMatrix(int **mat1, int rows, int cols, unsigned degree);
int determinantMatrix(int **mat1, int rows, int cols);
bool matrixIsDiagonal(int **mat1, int rows, int cols);
void swap(int &a, int &b);
int sortRow(int *arr, int cols);
int **sortRowsInMatrix(int **mat1, int rows, int cols);


double **addMatrix(double **mat1, double **mat2, int rows, int cols);
double **subtractMatrix(double **mat1, double **mat2, int rows, int cols);
double **multiplyMatrix(double **mat1, double **mat2, int rows, int cols1, int cols2);
double **multiplyByScalar(double **mat1, double rows, int cols, double scalar);
double **transposeMatrix(double **mat1, int rows, int cols);
double **powerMatrix(double **mat1, int rows, int cols, unsigned degree);
double determinantMatrix(double **mat1, int rows, int cols);
bool matrixIsDiagonal(double **mat1, int rows, int cols);
void swap(double &a, double &b);
double sortRow(double *arr, int cols);
double **sortRowsInMatrix(double **mat1, int rows, int cols);


#endif //JIPP_2_MATRIX_H
