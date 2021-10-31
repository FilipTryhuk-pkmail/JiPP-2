//
// Created by anon on 10/29/21.
//

#include <iostream>
#include <cmath>

using namespace std;

// INT

/*
 * Dodaje dwie macierze liczb naturalnych
 *
 * **mat1 - macierz pierwsza liczb naturalnych
 *
 * **mat2 - macierz druga liczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Odejmuje dwie macierze liczb naturalnych, drugą od pierwszej
 *
 * **mat1 - macierz pierwsza liczb naturalnych
 *
 * **mat2 - macierz druga liczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Mnoży dwie macierze liczb naturalnych
 *
 * **mat1 - macierz pierwsza liczb naturalnych
 *
 * **mat2 - macierz druga liczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Mnoży macierz liczb naturalnych przez skalar
 *
 * **mat - macierz liczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 *
 * scalar - skalar, liczba naturalna
 */
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

/*
 * Transponuje macierz liczb naturalnych
 *
 * mat1 - macierz liczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Podnosi macierz liczb naturalnych do podanej potęgi
 *
 * **mat - macierzliczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 *
 * degree - stopień potęgi
 */
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

/*
 * Oblicza determinantę macierzy liczb naturalnych
 *
 * **mat - macierz liczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Sprawdza czy macierz jest diagonalna
 *
 * **mat - macierz liczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Zamienia "w miejscu" dwie liczby naturalne
 *
 * a - pierwsza liczba naturalna
 *
 * b - druga liczba naturalna
 */
void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

/*
 * Sortuje w kolejności rosnącej liczby naturalne w podanej tabeli
 *
 * arr[] - tabela liczb naturalnych
 *
 * cols - liczba elementów w tebeli
 */
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

/*
 * Sortuje w kolejności rosnącej liczby naturalne w każdym wierszu podanej macierzy
 *
 * **mat - macierz liczb naturalnych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
void sortRowsInMatrix(int **mat, int rows, int cols) {

    for (int i=0; i<rows; i++) {
        sortRow(mat[i], cols);
    }
}





// DOUBLE

/*
 * Dodaje dwie macierze liczb zmiennoprzecinkowych
 *
 * **mat1 - macierz pierwsza liczb zmiennoprzecinkowych
 *
 * **mat2 - macierz druga liczb zmiennoprzecinkowych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Odejmuje dwie macierze liczb zmiennoprzecinkowych, drugą od pierwszej
 *
 * **mat1 - macierz pierwsza liczb zmiennoprzecinkowych
 *
 * **mat2 - macierz druga liczb zmiennoprzecinkowych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Mnoży dwie macierze liczb zmiennoprzecinkowych
 *
 * **mat1 - macierz pierwsza liczb zmiennoprzecinkowych
 *
 * **mat2 - macierz druga liczb zmiennoprzecinkowych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Mnoży macierz liczb zmiennoprzecinkowych przez skalar
 *
 * **mat - macierz liczb zmiennoprzecinkowych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 *
 * scalar - skalar, liczba naturalna
 */
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

/*
 * Transponuje macierz liczb zmiennoprzecinkowych
 *
 * mat1 - macierz liczb zmiennoprzecinkowych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Podnosi macierz liczb zmiennoprzecinkowych do podanej potęgi
 *
 * **mat - macierz liczb zmiennoprzecinkowych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 *
 * degree - stopień potęgi
 */
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

/*
 * Oblicza determinantę macierzy liczb zmiennoprzecinkowych
 *
 * **mat - macierz liczb zmiennoprzecinkowych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Sprawdza czy macierz liczb zmiennoprzecinkowe jest diagonalna
 *
 * **mat - macierz liczb zmiennoprzecinkowych
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
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

/*
 * Zamienia "w miejscu" dwie liczby zmiennoprzecinkowe
 *
 * a - pierwsza liczba
 *
 * b - druga liczba
 */
void swap(double &a, double &b) {
    double c = a;
    a = b;
    b = c;
}

/*
 * Sortuje w kolejności rosnącej liczby zmiennoprzecinkowe w podanej tabeli
 *
 * arr[] - tabela liczb zmiennoprzecinkowe
 *
 * cols - liczba elementów w tebeli
 */
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

/*
 * Sortuje w kolejności rosnącej liczby zmiennoprzecinkowe w każdym wierszu podanej macierzy
 *
 * **mat - macierz liczb zmiennoprzecinkowe
 *
 * rows - liczba wierszy
 *
 * cols - liczba kolumn
 */
void sortRowsInMatrix(double **mat, int rows, int cols) {

    for (int i=0; i<rows; i++) {
        sortRow(mat[i], cols);
    }
}

void typeHelp() {
    cout << "Pierwszy argument wywołania powinien być \"int\" dla działań na liczbach" << endl;
    cout << "całkowitych lub \"double\" dla liczby zmiennoprzecinkowych," << endl << endl;
}

void help() {
    typeHelp();
    cout << "Obsługiwane operacje na macierzach wraz z odpowiednią nazwą parametru:" << endl;
    cout << "\t\"+\"" << endl << "Dodaje dwie macierze." << endl << endl;
    cout << "\t\"-\"" << endl << "Odejmuje macierz drugą od pierwszej" << endl << endl;
    cout << "\t\"*m\"" << endl << "Mnoży macierz pierwszą przez macierz drugą" << endl << endl;
    cout << "\t\"*s\"" << endl << "Mnoży macierz przez skalar" << endl << endl;
    cout << "\t\"t\"" << endl << "Transponuje macierz" << endl << endl;
    cout << "\t\"^\"" << endl << "Podnosi macierz do podanej potęgi" << endl << endl;
    cout << "\t\"det\"" << endl << "Liczy determinantę macierzy" << endl << endl;
    cout << "\t\"sort\"" << endl << "Sortuje w kolejności rosnącej elementy w każdym wierszu macierzy" << endl << endl;
}