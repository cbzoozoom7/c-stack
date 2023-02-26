/*
 * main.cpp
 * Chris Bowman
 * 23 Feb 2023
 */

#include "main.h"

int main(int argc, char **argv) {
    // here for the rand_string() function
    srand(time(NULL));
    int size;
    bool goodArg = false;
    try {
        size = std::stoi(argv[1]);
        goodArg = true;
    } catch (...) {
        cout << "Please pass in the desired stack size as an int in the first command line argument." << endl;
    }
    if (goodArg) {
        Stack myStack(size);
        //making sure it's empty
        int emptyCount = 0;
        for (int i = 0; i < (SCALE * SCALE); i++) {
            if (myStack.isEmpty()) {
                emptyCount++;
            }
        }
        if (emptyCount == (SCALE * SCALE)) {
            cout << "My stack is very empty." << endl;
        } else {
            cout << "Somebody's been in my stack." << endl;
        }
        emptyCount = 0;
        //attempt to push random data onto the stack
        int pushSuccess = 0;
        int pushFail = 0;
        for (int i = 0; i < (size * SCALE); i++) {
            if (myStack.isEmpty()) {
                emptyCount++;
            }
            int myId = rand();
            if ((rand() % 2) == 0) {
                myId *= -1;
            }
            std::string strtemp;
            rand_string(&strtemp);
            if (myStack.push(myId, &strtemp)) {
                pushSuccess++;
                Data *pushTester = new Data;
                myStack.peek(pushTester);
                if ((pushTester -> id != myId) || (pushTester -> information != strtemp)) {
                    cout << "incorrect push" << endl;
                }
            } else {
                pushFail++;
            }
        }
        cout << "Successful pushes: \t" << pushSuccess << " \tFailed pushes: \t" << pushFail << " \tEmpty Count: \t" << emptyCount << endl;
    }
    /* ***************************************************************
     * Throughly test your stack. You must perform an exhaustive series
     * of tests on your stack. Show all possible ways your stack can be used
     * and abused and prove that your stack can gracefully handle ALL cases.
     * You must use automated testing (no user input). First cover all
     * explicit cases which you can think of, then execute random operations.
     * When generating test data, use random ints for ids and random short
     * strings for string. There is a string generator made for you in the
     * functions module. You are free to use it or make your own.
     * ***************************************************************/

    /* ***************************************************************
     * Below is some sample code for the random string function. It's
     * only here to demonstrate the function. DELETE it once you study
     * it and understand it and can use it yourself in your code.
     * ***************************************************************/
    
    /* ***************************************************************
     * Your code will be tested by applying your stack to a custom main
     * designed to break your code. If it can be broken, you risk a
     * substantially reduced grade, up to and including a zero.
     * ***************************************************************/
    
    // WHEN YOU SUBMIT, DELETE ALL THESE INSTRUCTIONALCOMMENTS
    
    return 0;
}
