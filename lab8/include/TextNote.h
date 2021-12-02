//
// Created by anon on 11/29/21.
//

#ifndef JIPP_2_TEXTNOTE_H
#define JIPP_2_TEXTNOTE_H

#include "Note.h"
using namespace std;

class TextNote : public Note{
private:
    string content;
public:
    TextNote(string title, string content);
    TextNote();
    string getContent();
    void setContent(string *newContent);
};


#endif //JIPP_2_TEXTNOTE_H
