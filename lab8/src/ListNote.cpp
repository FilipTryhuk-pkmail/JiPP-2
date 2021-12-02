//
// Created by anon on 11/29/21.
//

#include "ListNote.h"
#include <iostream>

string ListNote::getContent() {
    string result;
    for (int i=0; i < size; i++) {
        result.append("\n");
        result.append(content[i]);
    }
    result.append("\n");
    return result;
}

void ListNote::setContent(string *newContent) {
    for (int i=0; i++; i < size){
        content[i] = newContent[i];
    }
}

ListNote::ListNote(string &title, string *content, int size) {
    this->title = title;
    this->size = size;
    for (int i=0; i < size; i++){
        this->content[i] = content[i];
    }
}
