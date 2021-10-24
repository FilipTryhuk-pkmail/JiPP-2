//
// Created by anon on 10/18/21.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

bool initialized = false;

int randrange(int low, int high) {

    //initialize seed if not already initialized
    if (!initialized) {
        srand (time(nullptr));
        initialized = !initialized;
    }

    int res = rand() % high + low;

    return res;
}

int find_largest(const int tab[], int len) {
    int largest = tab[0];

    for(int i=0; i<len; i++){
        largest = (tab[i] > largest) ? tab[i] : largest;
    }

    return largest;
}

void arr_reverse(int tab[], int len) {
    for(int i=0; i < (len/2); i++) {
        int temp = tab[i];
        tab[i] = tab[len - (i+1)];
        tab[len - (i+1)] = temp;
    }
}

float ptr_mean(int *a, int *b) {
    float mean = (*a + *b) / 2.;
    return mean;
}

void find_pos(int tab[], int len){
    //Tablice przekazywane są przez wskaźniki
    for(int i=0; i < len; i++) {
        if(tab[i] > 0) {
            cout << tab[i] << endl;
        }
    }
}

void sort_arr(int tab[], int len){
    //Tablice przekazywane są przez wskaźniki
    int temp_arr[len];
    for(int i=0; i < len; i++) {
        temp_arr[i] = tab[i];
    }

    for(int i=0; i < len; i++) {

        int lowest_val;
        for (int j = 0; j < len; j++) {
            if (temp_arr[j] <= tab[i]) {tab[i] = temp_arr[j]; lowest_val = j;}
        }
        //remove the lowest element from available
        temp_arr[lowest_val] = INT32_MAX;
    }
}

void change_int(int key, int *target){
    *target = key;
}

void e_divide(int a, int b) {
    int res;
    float f_res;
    try {
        res = a / b;
        f_res = (a * 1.) / b;
        if (f_res - res > 0.0001) {throw "Niepoprawne dane!";}
        else {cout << "Wynik dzielenia to: " << res << endl << endl;}
    }
    catch(const char* msg) {
        cout << "Niepoprawne dane!" << endl;
    }
}

void to_int(string s) {
//    string letter;
    int len = s.length();
    int conv;
/*
    try {
        for (int i = 0; i < len; i++) {
            letter[0] = s[i];
            if (stoi(letter) > 9 || stoi(letter) < 0) { throw "Wprowadzony ciąg zawiera nieprawidłowe znaki"; }
        }
    }
    catch(const char* msg) {
        cout << "Wprowadzony ciąg zawiera nieprawidłowe znaki." << endl;
        return 0;
    }
*/
    try {
        conv = stoi(s);
        if ((conv / pow(10, len-1)) < 1) {throw "Wprowadzony ciąg zawiera nieprawidłowe znaki.";}
    }
    catch(out_of_range) {
        cout << "Liczba jest za duża." << endl;
        return;
    }
    catch(const char* msg) {
        cout << "Wprowadzony ciąg zawiera nieprawidłowe znaki." << endl;
        return;
    }

    cout << "Podana liczba to: " << conv << endl << endl;
}

int main(int argc, char *argv[]) {

    //Generate three random numbers between 13 and 22
    for(int i=0; i<3; i++) {
        cout << randrange(13, 22) << endl;
    }

    //create an array of random ints from 1 to 100 and return largest one found
    int arr_size;
    cout << "Podaj rozmiar tablicy: ";
    cin >> arr_size;
    cout << endl;
    int tab[arr_size];
    for(int i=0; i < arr_size; i++) {
        tab[i] = randrange(1, 100);
    }
    cout << "Największy element w tablicy to: " << find_largest(tab, arr_size) << endl;

    //reverse the order of an array
    cout << "Pierwsza: " << tab[0] << " i ostatnia wartość: " << tab[arr_size-1] << endl;
    arr_reverse(tab, arr_size);
    cout << "Zamiana!" << endl << "Pierwsza: " << tab[0] << " i ostatnia wartość: " << tab[arr_size-1] << endl;

    //get two numbers from user, set pointers to addresses and calculate mean
    int num1, num2;
    cout << endl << "Podaj pierwszą liczbę: ";
    cin >> num1;
    cout << endl;
    cout << "Podaj drugą liczbę: ";
    cin >> num2;
    cout << endl;
    int *num1_ptr = &num1;
    int *num2_ptr = &num2;
    cout << "Średnia to: " << ptr_mean(num1_ptr, num2_ptr) << endl << endl;

    //find positive elements from an array
    for(int i=0; i < arr_size; i++) {
        tab[i] = tab[i] - 50;
    }
    find_pos(tab, arr_size);

    //sort elements in ascending order
    if(arr_size > 4) {cout << endl <<"Pierwsze pięć elementów tablicy: " << tab[0] << " " << tab[1] << " " << tab[2] << " " << tab[3] << " " << tab[4] << endl;}
    sort_arr(tab, arr_size);
    if(arr_size > 4) {cout << "Sortowanie!" << endl << "Pierwsze pięć elementów tablicy: " << tab[0] << " " << tab[1] << " " << tab[2] << " " << tab[3] << " " << tab[4] << endl << endl;}

    //change x into w with a void func
    int x = 10, w = 5;
    int *w_ptr = &w;
    cout << "W wynosi: " << w << " X wynosi:" << x << endl;
    change_int(x, w_ptr);
    cout << "Wpisanie X do W" << endl << "W wynosi: " << w << " X wynosi:" << x << endl;

    //divide two numbers, catch exception if not possible
    int a, b;
    cout << endl << "Podaj pierwszą liczbę: ";
    cin >> a;
    cout << endl;
    cout << "Podaj drugą liczbę: ";
    cin >> b;
    cout << endl;
    e_divide(a, b);

    //convert string of numbers to int
    string st_inp;
    cout << endl << "Podaj ciąg znaków: ";
    cin >> st_inp;
    cout << endl;
    to_int(st_inp);


    return 0;
}