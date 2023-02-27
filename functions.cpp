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
int randInt() {
    int random = rand();
    if ((rand() % 2) == 0) {
        random *= -1;
    }
    return random;
}
int pushPeek(Stack *s, int id, string *str) {
    int result = -4;
    Data input;
    input.id = id;
    input.information = *str;
    if (s -> push(id, str)) {
        Data *output = new Data;
        if (s -> peek(output)) {
            if (dataEquals(&input, output)) {
                result = 0;
            } else {
                result = -3;
                std::cout << "Bad push." << std::endl;
            }
        } else {
            result = -2;
            std::cout << "Failed peek after push." << std::endl;
        }
        delete output;
    } else {
        result = -1;
    }
    return result;
}
int peekPop(Stack *s) {
    int result = -4;
    Data *peekTester = new Data;
    if (s -> peek(peekTester)) {
        Data *popTester = new Data;
        if (s -> pop(popTester)) {
            if (dataEquals(peekTester, popTester)) {
                result = 0;
            } else {
                result = -3;
                cout << "Peek does not match pop." << endl;
            }
        } else {
            result = -2;
            cout << "Peek was allowed, but subseqent pop failed." << endl;
        }
        delete popTester;
    } else {
        result = -1;
    }
    delete peekTester;
    return result;
}