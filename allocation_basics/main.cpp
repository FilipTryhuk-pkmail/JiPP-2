//
// Created by anon on 10/11/21.
//

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    for(int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }



    int *n = new int;
    int k;
//    cout << n << endl << *n << endl << &n << endl << &k << endl;
    delete n;

    int *tab = new int[5];
    delete[] tab;

    int **tab2 = new int*[5];
    for(int i =0; i < 5; ++i){
        tab2[i] = new int[5];
    }

    for(int i =0; i < 5; ++i){
        delete[] tab2[i];
    }
    delete[] tab2;

    int tab3[3] = {3, 2, 1};
//    cout << tab3[0] << endl << tab3[1] << endl << tab3[2] << endl;

    return 0;
}