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
void rand_string(std::string*);
void dataPrint(Data *);
bool dataEquals(Data *, Data *);
#endif /* STACKS_FUNCTIONS_H */