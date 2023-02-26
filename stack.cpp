/*
 * stack.cpp
 * Chris Bowman
 * Recieved 23 Feb 2023
 */

// each cpp includes ONLY it's header directly
/////////////////////////*its
#include "stack.h"
Stack::Stack(int s) {
    top = -1;
    if (s >= MIN_SIZE) {
        size = s;
    } else {
        size = 10;
    }
    stack = new Data*[size];
}
bool Stack::push(int id, string *s) {
    bool pushed = false;
    if (top < size-1 && id > 0 && *s != "") {
        Data *pushData = new Data();
        pushData -> id = id;
        pushData -> information = *s;
        stack[++top] = pushData;
        pushed = true;
    }
    return pushed;
}
bool Stack::isEmpty() {
    return (top < 0);
}
bool Stack::peek(Data *d) {
    bool peeked = false; //ok now i understand why Apple names their bools like that.
    if (!isEmpty()) {
        Data topD = *stack[top];
        d -> id = topD.id;
        d -> information = topD.information;
        peeked = true;
    } else {
        d -> id = -1;
        d -> information = "";
    }
    return peeked;
}