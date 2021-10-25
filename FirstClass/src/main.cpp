//
// Created by anon on 10/25/21.
//

#include <iostream>
#include <string>
#include "FirstClass.h"

using namespace std;

int main(int argc, char *argv[]) {
    FirstClass person("Jan", "Kowalski", 40, 180);
    person.printAllData();
    person.setHeight(170);
    person.printAllData();
    return 0;
}