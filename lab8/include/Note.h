//
// Created by anon on 11/29/21.
//

#ifndef JIPP_2_NOTE_H
#define JIPP_2_NOTE_H
#include <iostream>

using namespace std;

class Note {
protected:
    string title;
    int size;
public:
    string getTitle();
    void setTitle(string newTitle);
    virtual string getContent() = 0;
    virtual void setContent(string *setContent) = 0;
};


#endif //JIPP_2_NOTE_H
