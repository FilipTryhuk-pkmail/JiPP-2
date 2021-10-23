//
// Created by anon on 10/18/21.
//

#include <iostream>
#include <string>
#include <cstdlib>
//#include "lib2.h"

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
    cout << "Pierwsza: " << tab[0] << " i ostatnia wartość: " << tab[arr_size-1] << endl;


    return 0;
}