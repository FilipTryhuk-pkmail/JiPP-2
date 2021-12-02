//
// Created by anon on 11/29/21.
//

#ifndef JIPP_2_LISTNOTE_H
#define JIPP_2_LISTNOTE_H
#include <iostream>
#include "Note.h"

using namespace std;

class ListNote: public Note{
private:
    string content[100];
public:
    string getContent();
    void setContent(string *newContent);
    ListNote(string &title, string *content, int size);
};


#endif //JIPP_2_LISTNOTE_H
