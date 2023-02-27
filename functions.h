/*
 * functions.h
 * Chris Bowman
 * Recieved 23 Feb 2023
 */

#ifndef STACKS_FUNCTIONS_H
#define STACKS_FUNCTIONS_H

#define MAXSTRSIZE 8

#include <stdlib.h>   /* srand, rand */
#include <time.h>     /* time */
#include <time.h>     /* time */
#include <string>     /* string */
#include <iostream>
#include "data.h"
#include "stack.h"
using std::cout;
using std::endl;
void rand_string(std::string*);
void dataPrint(Data *);
bool dataEquals(Data *, Data *);
int randInt();
int pushPeek(Stack*, int, string*); //Pushes the input onto the provided stack, then peeks it, & compares the input to the output. Key for the returned result follows. 0 = OK, -1 = Push failed, -2 = Peek failed, -3 = Push/peek mismatch
int peekPop(Stack*);
#endif /* STACKS_FUNCTIONS_H */