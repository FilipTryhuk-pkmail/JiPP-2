//
// Created by anon on 1/3/22.
//

#ifndef JIPP_2_CSVEXCEPTION_H
#define JIPP_2_CSVEXCEPTION_H

#endif //JIPP_2_CSVEXCEPTION_H

#include <exception>
#include <iostream>
#include <stdio.h>
#include <memory>
using namespace std;

class MyException: public exception {
private:
    char *exceptionText;

public:
    MyException(char * exceptionText): exceptionText(exceptionText) {}

    const char * what() {
        return exceptionText;
    }
};
// SEE VIDEO FOR EXAMPLES
class CsvParser {
private:
    CsvParser(int column_count, char delimiter);
    char delimiter;
    int column_count;
    std::unique_ptr<string[]> column_names;
public:
    void readLine();
};