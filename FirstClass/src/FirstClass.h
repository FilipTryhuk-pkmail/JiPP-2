//
// Created by anon on 10/25/21.
//

#ifndef JIPP_2_FIRSTCLASS_H
#define JIPP_2_FIRSTCLASS_H
#include <iostream>


using namespace std;

class FirstClass {
private:
    string firstName;
    string lastName;
    unsigned int shoeSize;
    unsigned int height;
public:
    void printName();
    void printSizeData();
    void printAllData();

    FirstClass(string FirstName, string LastName, unsigned int shoeSize, unsigned int height);

    void setHeight(unsigned int newHeight);
};


#endif //JIPP_2_FIRSTCLASS_H
