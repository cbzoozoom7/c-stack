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
}