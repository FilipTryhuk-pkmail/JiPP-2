//
// Created by anon on 10/17/21.
//
#include <iostream>
#include <string>

using namespace std;

void add(int num1, int num2){
    int res = num1 + num2;
    cout << "Wynik dodawania: " << res << endl;
};

void subtract(int num1, int num2){
    int res = num1 - num2;
    cout << "Wynik odejmowania: " << res << endl;
};

void volume(int a, int b, int h, int H){
    int area = ((a+b)/2 * h);
    int vol = area * H;
    cout << "Objętość graniastosłupa: " << vol << endl;
};

void help(){
    cout << "Simple calculator" << endl << "simpleCalc [nazwa działania]" << endl << endl;
    cout << "Działania:" << endl << "add [a] [b]" << endl << "Dodawanie dwóch liczb ([a] i [b]) całkowitych" << endl << endl;
    cout << "subtract [a] [b]" << endl << "Odejmowanie dwóch liczb ([b] od [a]) całkowitych" << endl << endl;
    cout << "volume [a] [b] [h] [H]" << endl << "Obliczanie objętości graniastosłupa prostego o podstawie trapezu (podstawy długości [a] i [b], wysokość [h]) i wysokości [H]" << endl << endl;
    cout << "help" << endl << "Wyświetlenie tej dokumentacji" << endl;
};