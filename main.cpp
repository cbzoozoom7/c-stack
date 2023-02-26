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
        cout << "Testing empty..." << endl;
        if (myStack.isEmpty()) {
            cout << "My stack is very empty." << endl;
        } else {
            cout << "Somebody's been in my stack." << endl;
        }
        Data *emptyTest = new Data;
        if (myStack.peek(emptyTest)) {
            cout << "Peeked ";
            dataPrint(emptyTest);
        }
        if (myStack.pop(emptyTest)) {
            cout << "Popped ";
            dataPrint(emptyTest);
        }
        delete emptyTest;
        cout << "Filling..." << endl;
        int emptyCount = 0;
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
                if (myStack.peek(pushTester)) {
                    Data pushed;
                    pushed.id = myId;
                    pushed.information = strtemp;
                    if (!dataEquals(pushTester, &pushed)) {
                        cout << "Bad push." << endl;
                    }
                } else {
                    cout << "Failed peek after push." << endl;
                }
                delete pushTester;
            } else {
                pushFail++;
            }
        }
        cout << "Successful pushes: \t" << pushSuccess << " \tFailed pushes: \t" << pushFail << " \tEmpty Count: \t" << emptyCount << "\nPeeking & popping the whole stack..." << endl;
        int correctPeekPop = 0;
        int incorrectPeekPop = 0;
        int failedPeekPop = 0;
        for (int i = 0; i < (size * SCALE); i++) {
            Data *fullPeekTester = new Data;
            if (myStack.peek(fullPeekTester)) {
                Data *fullPopTester = new Data;
                if (myStack.pop(fullPopTester)) {
                    if (dataEquals(fullPeekTester, fullPopTester)) {
                        correctPeekPop++;
                    } else {
                        incorrectPeekPop++;
                    }
                } else {
                    failedPeekPop++;
                }
                delete fullPopTester;
            } else {
                failedPeekPop++;
            }
            delete fullPeekTester;
        }
        cout << "Correct Peek Pops: \t" << correctPeekPop << " \tIncorrect Peek Pops: \t" << incorrectPeekPop << "\tFailed Peek Pops: \t" << failedPeekPop << " \t" << (myStack.isEmpty() ? "Stack is empty." : "Stack is NOT empty.") << "\nFilling stack halfway..." << endl;
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
     * Your code will be tested by applying your stack to a custom main
     * designed to break your code. If it can be broken, you risk a
     * substantially reduced grade, up to and including a zero.
     * ***************************************************************/
    
    // WHEN YOU SUBMIT, DELETE ALL THESE INSTRUCTIONALCOMMENTS
    
    return 0;
}
