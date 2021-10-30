//
// Created by anon on 10/29/21.
//


#include <iostream>
#include "../../matrixLib/matrixLib.h"

using namespace std;

int main(int argc, char *argv[]) {

    //butReally();

    int rows = 0;
    int cols = 0;
    cout << "Podaj liczbę wierszy i kolumn oddzielone spacjami" << endl;
    cin >> rows >> cols;

    int **test_arr1, **test_arr2;
    test_arr1 = new int *[rows];
    test_arr2 = new int *[rows];
    for (int i=0; i<rows; i++) {
        test_arr1[i] = new int[cols];
        test_arr2[i] = new int[cols];
    }

    for(int i=0; i<rows; i++) {
        test_arr1[i][i] = i;
        test_arr2[rows -1-i][rows -1-i] = i;
        if(i < (rows - 1)) {
            test_arr1[i][i+1] = 2;
            test_arr2[i+1][i] = 3;
        }
    }

    int **small_arr1;
    small_arr1 = new int *[3];
    for (int i=0; i<rows; i++) {
        small_arr1[i] = new int[3];
    }
    small_arr1[0][0] = 7;
    small_arr1[0][1] = 1;
    small_arr1[0][2] = 3;
    small_arr1[1][0] = 2;
    small_arr1[1][1] = 4;
    small_arr1[1][2] = 1;
    small_arr1[2][0] = 1;
    small_arr1[2][1] = 5;
    small_arr1[2][2] = 1;
//    small_arr1[3][0] = 4;
//    small_arr1[3][1] = 4;
//    small_arr1[3][2] = 4;
    int a = 7;
    int b = 3;
//    cout << endl << a << " " << b << endl;


    int **add = addMatrix(test_arr2, test_arr1, rows, cols);                    //OK
    int **subst = subtractMatrix(test_arr2, test_arr1, rows, cols);             //OK
    int **mul = multiplyMatrix(test_arr2, test_arr1, rows, cols, cols);         //OK
    int **by_scalar = multiplyByScalar(small_arr1, 3, 3, 4);    //OK
    int **transpose = transposeMatrix(small_arr1, 4, 3);              //OK
    int **power = powerMatrix(test_arr1, rows, cols, 3);                 //OK
    int det = determinantMatrix(small_arr1, 3, 3);                    //not OK, only hardcoded for 2x2 and 3x3
    bool diag = matrixIsDiagonal(test_arr1, rows, cols);                        //OK
    swap(a, b);                                                           //OK




    cout << endl << endl;
    for (int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << test_arr1[i][j] << " ";
        }
        cout << endl << endl;
    }
//    cout << det << endl;
//    cout << endl << a << " " << b << endl;
/*
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << by_scalar[i][j] << " ";
        }
        cout << endl;
    }
*/
    return 0;
}