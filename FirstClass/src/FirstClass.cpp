//
// Created by anon on 10/25/21.
//

#include "FirstClass.h"

void FirstClass::printName() {
    cout << firstName << " " << lastName <<endl;
}

void FirstClass::printSizeData() {
    cout << shoeSize << " " << height <<endl;
}

void FirstClass::printAllData() {
    printName();
    printSizeData();
}

FirstClass::FirstClass(string FirstName, string LastName, unsigned int shoeSize, unsigned int height) {
    firstName = FirstName;
    lastName = LastName;
    this->shoeSize = shoeSize;
    this->height = height;
}

void FirstClass::setHeight(unsigned int newHeight) {
    this -> height = newHeight;
}
