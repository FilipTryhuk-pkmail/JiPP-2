//
// Created by anon on 11/29/21.
//

#include "Note.h"
#include "TextNote.h"
#include "NoteDirector.h"
#include "ListNote.h"
using namespace std;

int main() {
    NoteDirector note_dir;
    note_dir.printAll();

    string lista[2];
    lista[0] = "l_note1";
    lista[1] = "l_note2";
    string lnote_name = "list";
    ListNote lists(lnote_name, lista, 2);
    TextNote text("text", "sample text forming the text note");

    note_dir.addNote(&lists);
    note_dir.addNote(&text);
    note_dir.printAll();
    note_dir.deleteNote();
    note_dir.printAll();

    return 0;
}