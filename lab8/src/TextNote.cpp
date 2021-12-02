//
// Created by anon on 11/29/21.
//

#include "../include/TextNote.h"

string TextNote::getContent() {
    return content;
}

void TextNote::setContent(string *newContent) {
    content = *newContent;
}

TextNote::TextNote(string title, string content): content(content) {
    this->title = title;
    size = content.length();
}

TextNote::TextNote() {
    title = "not_specified";
    size = 0;
    content = " ";

}
