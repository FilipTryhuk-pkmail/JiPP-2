//
// Created by anon on 11/29/21.
//

#ifndef JIPP_2_NOTEDIRECTOR_H
#define JIPP_2_NOTEDIRECTOR_H
#include <vector>
#include "Note.h"
#include "TextNote.h"
#include "ListNote.h"

class NoteDirector {
private:
    Note *notesList[100];
    int used;
public:
    NoteDirector();
    void printAll();
    void printAllTitles();
    void addNote(Note *newNote);
    void deleteNote();
    // replace note at position {target} with newNote
    void editNote(Note *newNote, int target);
    void clearNotesList();
};


#endif //JIPP_2_NOTEDIRECTOR_H
