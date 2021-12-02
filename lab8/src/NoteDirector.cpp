//
// Created by anon on 11/29/21.
//

#include "NoteDirector.h"
#include "Note.h"
#include "TextNote.h"

void NoteDirector::printAll() {

    for (int i=0; i<used; i++) {
        //cout << used;
        cout << notesList[i]->getTitle() << "   " <<notesList[i]->getContent() << endl;
    }
}

void NoteDirector::printAllTitles() {
    for (int i=0; i<used; i++) {
        cout << notesList[i]->getTitle() << endl;
    }

}

void NoteDirector::addNote(Note *newNote) {
    notesList[used] = newNote;
    used++;
}

void NoteDirector::deleteNote() {
    TextNote sample = TextNote();
    notesList[used-1] = &sample;
    used--;
}

void NoteDirector::editNote(Note *newNote, int target) {
    notesList[target] = newNote;
}

void NoteDirector::clearNotesList() {
    for (used; used>0;) {
        deleteNote();
    }
}

NoteDirector::NoteDirector() {
    used = 0;
    TextNote sample = TextNote();
    for (int i=0; i<100; i++) {
        notesList[i] = &sample;
    }
}
