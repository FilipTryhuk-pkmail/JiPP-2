//
// Created by anon on 10/29/21.
//


#include <iostream>
#include "../../matrixLib/matrixLib.h"

using namespace std;

void printMatrix(int **arr, int rows, int cols);
void printMatrix(double **arr, int rows, int cols);

int main(int argc, char *argv[]) {

    //Pobierz od uźytkownika rozmiar macierzy
    bool ints;
    int rows = 0;
    int cols = 0;
    cout << "Podaj liczby wierszy i kolumn pierwszej macierzy oddzielone spacjami" << endl;
    //cin automatycznie zabezpiecza przed wpisanie zmiennej niewłaściwego typu
    cin >> rows >> cols;
    try {
        //Sprawdź, czy użytkownik zapytał o pomoc
        if (string(argv[1]) == "help") {
            help();
            return 1;
        }
    }
    catch (logic_error) {
        help();
        return 1;
    }
    //Sprawdź, czy podano odpowiednią liczbę parametrów
    if (argc != 2) {
        help();
        return 1;
    }
/*
    //Odczytaj typ liczb i przygotuj macierze odpowiednich typów
    if (string(argv[1]) == "int") {
        ints = true;
    }
    else if (string(argv[1]) == "double") {
        ints = false;
    } else {
        typeHelp();
        cout << endl << endl << argv[1] << endl << argv[2] << endl << argv[3];
        return 1;
    } */ ints = true;

    //Przygotuj macierze odpowednich rozmiarów jako tablice wskaźników do wskaźników
    int **iArr1, **iArr2;
    iArr1 = new int *[rows];
    iArr2 = new int *[rows];
    for (int i = 0; i < rows; i++) {
        iArr1[i] = new int[cols];
        iArr2[i] = new int[cols];
    }
    double **dArr1, **dArr2;
    dArr1 = new double *[rows];
    dArr2 = new double *[rows];
    for (int i = 0; i < rows; i++) {
        dArr1[i] = new double[cols];
        dArr2[i] = new double[cols];
    }
/*
    //Wczytaj macierz na której wykonana zostanie wybrana operacja
    if (ints) {
        for (int i=0; i<rows; i++) {
            for (int j=0; j<rows; j++) {
                cout << "Podaj liczbę na miejsce " << j << " w wierszu " << i << " macierzy pierwszej" << endl;
                //cin automatycznie zabezpiecza przed wpisanie zmiennej niewłaściwego typu
                cin >> iArr1[i][j];
            }
            cout << endl;
        }
    }*/
//    else {
      for (int i=0; i<rows; i++) {
          for (int j=0; j<rows; j++) {
              cout << "Podaj liczbę na miejsce " << j << " w wierszu " << i << " macierzy pierwszej" << endl;
              //cin automatycznie zabezpiecza przed wpisanie zmiennej niewłaściwego typu
              cin >> dArr1[i][j];
              //jeżeli którakolwiek z liczb jest niecałkowita ustaw bool ints na false
              if (((dArr1[i][j] - int(dArr1[i][j])) > 0.0001) || ((int(dArr1[i][j] - dArr1[i][j])) > 0.0001)) {ints = false;}
          }
          cout << endl;
      }
      if (ints) {
          //jeżeli wszystkie były całkowite to przenieś liczby do tabeli intów
          for (int i=0; i<rows; i++) {
              for (int j=0; j<rows; j++) {
                  iArr1[i][j] = int(dArr1[i][j]);
              }
          }
          //następnie usuń zbędną macierz liczb całkowitych
          for (int i=0; i<rows; i++) {
                  delete dArr1[i];
          }
          delete dArr1;
      }
      else {
          //jeżeli są liczby całkowite to usuń macierz naturalną
          for (int i=0; i<rows; i++) {
              delete iArr1[i];
          }
          delete iArr1;
      }
//    }

    //Wczytaj drugą macierz jeśli operacja wymaga dwóch
    if (string(argv[1]) == "a" || string(argv[1]) == "s" || string(argv[1]) == "m2") {
        if (ints) {
            for (int i=0; i<rows; i++) {
                for (int j=0; j<rows; j++) {
                    cout << "Podaj liczbę na miejsce " << j << " w wierszu " << i << " macierzy drugiej" << endl;
                    //cin automatycznie zabezpiecza przed wpisanie zmiennej niewłaściwego typu
                    cin >> iArr2[i][j];
                }
                cout << endl;
            }
            //usuń zbędną macierz
            for (int i=0; i<rows; i++) {
                delete dArr2[i];
            }
            delete dArr2;
        } else {
            for (int i=0; i<rows; i++) {
                for (int j=0; j<rows; j++) {
                    cout << "Podaj liczbę na miejsce " << j << " w wierszu " << i << " macierzy drugiej" << endl;
                    //cin automatycznie zabezpiecza przed wpisanie zmiennej niewłaściwego typu
                    cin >> dArr2[i][j];
                }
                cout << endl;
            }
            //usuń zbędną macierz
            for (int i=0; i<rows; i++) {
                delete iArr2[i];
            }
            delete iArr2;
        }
    } else {
        //usuń obie zbędne macierze
        //usuń zbędną macierz
        for (int i=0; i<rows; i++) {
            delete dArr2[i];
            delete iArr2[i];
        }
        delete dArr2;
        delete iArr2;
    }


    if (string(argv[1]) == "a") {
        if (ints) {
            int **res = addMatrix(iArr1, iArr2, rows, cols);
            printMatrix(res, rows, cols);
        } else {
            double **res = addMatrix(dArr1, dArr2, rows, cols);
            printMatrix(res, rows, cols);
        }
    } else if (string(argv[1]) == "s") {
        if (ints) {
            int **res = subtractMatrix(iArr1, iArr2, rows, cols);
            printMatrix(res, rows, cols);
        } else {
            double **res = subtractMatrix(dArr1, dArr2, rows, cols);
            printMatrix(res, rows, cols);
        }
    } else if (string(argv[1]) == "m2") {
        if (ints) {
            int **res = multiplyMatrix(iArr1, iArr2, rows, cols, cols);
            printMatrix(res, rows, cols);
        } else {
            double **res = multiplyMatrix(dArr1, dArr2, rows, cols, cols);
            printMatrix(res, rows, cols);
        }
    } else if (string(argv[1]) == "ms") {
        if (ints) {
            int scalar = 1;
            cout << "Podaj liczbę naturalną - skalar" << endl;
            cin >> scalar;
            int **res = multiplyByScalar(iArr1, rows, cols, scalar);
            printMatrix(res, rows, cols);
        } else {
            double scalar = 1;
            cout << "Podaj liczbę zmiennoprzecinkową - skalar" << endl;
            cin >> scalar;
            double **res = multiplyByScalar(dArr1, rows, cols, scalar);
            printMatrix(res, rows, cols);
        }
    } else if (string(argv[1]) == "t") {
        if (ints) {
            int **res = transposeMatrix(iArr1, rows, cols);
            printMatrix(res, rows, cols);
        } else {
            double **res = transposeMatrix(dArr1, rows, cols);
            printMatrix(res, rows, cols);
        }
    } else if (string(argv[1]) == "p") {
        unsigned degree;
        cout << "Podaj liczbę naturalną - stopień potęgi" << endl;
        cin >> degree;
        if (ints) {
            int **res = powerMatrix(iArr1, rows, cols, degree);
            printMatrix(res, rows, cols);
        } else {
            double **res = powerMatrix(dArr1, rows, cols, degree);
            printMatrix(res, rows, cols);
        }
    } else if (string(argv[1]) == "det") {
        if (ints) {
            int res = determinantMatrix(iArr1, rows, cols);
            cout << endl << endl;
            cout << "Determinanta podanej macierzy to: " << res << endl;
        } else {
            double res = determinantMatrix(dArr1, rows, cols);
            cout << endl << endl;
            cout << "Determinanta podanej macierzy to: " << res << endl;
        }
    } else if (string(argv[1]) == "i") {
        if (ints) {
            bool res = matrixIsDiagonal(iArr1, rows, cols);
            if (res) {cout << endl << endl << "Podana macierz jest diagonalna." << endl; }
            else {cout << endl << endl << "Podana macierz nie jest diagonalna." << endl; }
        } else {
            bool res = matrixIsDiagonal(dArr1, rows, cols);
            if (res) {cout << endl << endl << "Podana macierz jest diagonalna." << endl; }
            else {cout << endl << endl << "Podana macierz nie jest diagonalna." << endl; }
        }
    } else if (string(argv[1]) == "sort") {
        if (ints) {
            sortRowsInMatrix(iArr1, rows, cols);
            printMatrix(iArr1, rows, cols);
        } else {
            sortRowsInMatrix(dArr1, rows, cols);
            printMatrix(dArr1, rows, cols);
        }
    } else {
        cout << "Niepoprawny parametr operacji!" << endl;
        cout << "Wyświetlam pomoc" << endl << endl;
        help();
        return 1;
    }







    /* legacy test code to check individual functions
    for(int i=0; i<rows; i++) {
        iArr1[i][i] = i;
        iArr2[rows - 1 - i][rows - 1 - i] = i;
        if(i < (rows - 1)) {
            iArr1[i][i + 1] = 2;
            iArr2[i + 1][i] = 3;
        }
    }

    for(int i=0; i<rows; i++) {
        dArr1[i][i] = i + 0.5;
        dArr2[rows - 1 - i][rows - 1 - i] = i + 0.5;
        if(i < (rows - 1)) {
            dArr1[i][i + 1] = 1.7;
            dArr2[i + 1][i] = 2.7;
        }
    }

    double **mul = multiplyMatrix(dArr2, dArr1, rows, cols, cols);
    cout << endl;
    for (int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << dArr1[i][j] << " ";
        }
        cout << endl << endl;
    }
    for (int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << mul[i][j] << " ";
        }
        cout << endl << endl;
    }


    for(int i=0; i<rows; i++) {
        iArr1[i][i] = i;
        iArr2[rows - 1 - i][rows - 1 - i] = i;
        if(i < (rows - 1)) {
            iArr1[i][i + 1] = 2;
            iArr2[i + 1][i] = 3;
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
    int *row;
    row = new int [5];
    row[0] = 3;
    row[1] = 9;
    row[2] = 7;
    row[3] = 0;
    row[4] = 6;
    cout << endl << a << " " << b << endl;


    int **add = addMatrix(iArr2, iArr1, rows, cols);                    //OK
    int **subst = subtractMatrix(iArr2, iArr1, rows, cols);             //OK
    int **mul = multiplyMatrix(iArr2, iArr1, rows, cols, cols);         //OK
    int **by_scalar = multiplyByScalar(small_arr1, 3, 3, 4);            //OK
    int **transpose = transposeMatrix(small_arr1, 4, 3);                //OK
    int **power = powerMatrix(iArr1, rows, cols, 3);                    //OK
    int det = determinantMatrix(small_arr1, 3, 3);                      //not OK, only hardcoded for 2x2 and 3x3
    bool diag = matrixIsDiagonal(iArr1, rows, cols);                    //OK
    swap(a, b);                                                         //OK
    sortRow(row, 5);                                                    //OK
    sortRowsInMatrix(iArr1, rows, cols);                                //OK


    cout << endl << endl;
    for (int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << iArr1[i][j] << " ";
        }
        cout << endl << endl;
    }

    cout << det << endl;
    cout << endl << a << " " << b << endl;
    cout << endl << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << " " << endl;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << by_scalar[i][j] << " ";
        }
        cout << endl;
    }
*/
    return 0;
}



void printMatrix(int **arr, int rows, int cols) {
    cout << endl << endl;
    for (int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl << endl;
    }
}

void printMatrix(double **arr, int rows, int cols) {
    cout << endl << endl;
    for (int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl << endl;
    }
}