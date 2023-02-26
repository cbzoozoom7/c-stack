/*
 * functions.cpp
 * Chris Bowman
 * Recived 23 Feb 2023
 */

#include "functions.h"

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;
    
    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete buffer;
    return;
}
void dataPrint(Data *d) {
    std::cout << "ID: \t" << d -> id << " \tInformation: \t" << d -> information << std::endl;
}
bool dataEquals(Data *d, Data *other) {
    return (d -> id == other -> id) && (d -> information == other -> information);
}