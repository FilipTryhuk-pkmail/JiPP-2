//
// Created by anon on 10/17/21.
//

#include <iostream>
#include <string>
#include "calc.h"

using namespace std;

void param_help(){
    cout << "Niepoprawna liczba parametroów!" << endl;
    help();
}

int main(int argc, char *argv[]) {
    --argc;
    if(argc != 3 && argc != 5) {
        param_help();
        return 1;
    }

    string op = argv[1];
    if(op.compare("add") == 0) {
        if(argc == 5) {
            param_help();
            return 1;
        }
        add(stoi(argv[2]), stoi(argv[2]));
    }

    else if(op.compare("subtract") == 0) {
        if(argc == 5) {
            param_help();
            return 1;
        }
        subtract(stoi(argv[2]), stoi(argv[2]));
    }

    else if(op.compare("volume") == 0) {
        if(argc == 3) {
            param_help();
            return 1;
        }
        volume(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]));
    }

    else if(op.compare("help") == 0) {
        help();
    }

    else {
        cout << "Niepoprawna operacja!" << endl;
        help();
        return 1;
    }

    return 0;
}