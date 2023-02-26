/*
 * stack.h
 * Chris Bowman
 * Recieved 23 Feb 2023
 */

#ifndef STACK_H
#define STACK_H
#define DEFAULT_SIZE 10
#define MIN_SIZE 2
/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
class Stack {

public:
    Stack(int);
    bool push(int, string*);
    //bool push (Data*);
    bool isEmpty();
    bool peek(Data*);
    bool pop(Data*);
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    Data **stack;
    // notice stack is a pointer to a pointer. That means if you do
    // a single array allocation, you will get an array of pointers
};

#endif //STACK_H
