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
            std::string *fillingStackString = new string;
            rand_string(fillingStackString);
            switch (pushPeek(&myStack, myId, fillingStackString)) {
                case 0:
                    pushSuccess++;
                    break;
                case -1:
                    pushFail++;
                    break;
            }
            delete fillingStackString;
        }
        cout << "Successful pushes: \t" << pushSuccess << " \tFailed pushes: \t" << pushFail << " \tEmpty Count: \t" << emptyCount << "\nPeeking & popping the whole stack..." << endl;
        int correctPeekPop = 0;
        int incorrectPeekPop = 0;
        int failedPeekPop = 0;
        for (int i = 0; i < (size * SCALE); i++) {
            switch (peekPop(&myStack)) {
                case 0:
                    correctPeekPop++;
                    break;
                case -1:
                    failedPeekPop++;
                    break;
                case -2:
                case -3: {
                    incorrectPeekPop++;
                    break;
                }
            }
        }
        cout << "Correct Peek Pops: \t" << correctPeekPop << " \tIncorrect Peek Pops: \t" << incorrectPeekPop << "\tFailed Peek Pops: \t" << failedPeekPop << " \t";
        if (myStack.isEmpty()) {
            cout << "Stack is empty.";
        } else {
            cout << "Stack is NOT empty.";
        }
        cout << "\nFilling stack halfway..." << endl;
        for (int i = 0; i < int(size / 2); i++) {
            string halfStackString = std::to_string(i + 1);
            myStack.push(i + 1, &halfStackString);
        }
        cout << "Here come the random operations." << endl;
        int randomPushes = 0;
        int randomPops = 0;
        int randomFailedPeekOrPop = 0;
        Data *propData = new Data;
        for (int i = 0; i < (size * SCALE); i++) {
            int choice = rand() % CHOICES;
            switch (choice) {
            case 0: //push
            case 1: {//push
                string *randStackString = new string;
                rand_string(randStackString);
                if (pushPeek(&myStack, randInt(), randStackString) == 0) {
                    randomPushes++;
                }
                delete randStackString;
                break;
            }
            case 2: //pop
            case 3: {//pop
                if (peekPop(&myStack)) {
                    randomPops++;
                }
                break;
            }
            case 4: //peek
                if (!myStack.peek(propData)) {
                    randomFailedPeekOrPop++;
                }
                break;
            case 5: //isEmpty
                myStack.isEmpty();
            }
        }
        delete propData;
        cout << "Pushed " << randomPushes << " times. \tPopped " << randomPops << " times. \tA peek or pop failed " << randomFailedPeekOrPop << " times. Done" << endl;
    }
    return 0;
}
