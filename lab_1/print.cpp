//
// Created by matgod on 11.10.17.
//

#include <cstdio>
#include <iostream>
#include <iomanip>
#include "print.h"
using namespace std;

void printInBit(unsigned int x, int i) {
    if (i < sizeof(int) * 8) {
        printInBit(x >> 1, ++i);
        cout << (x & 1);
    }
}

void printInBit(int x) {
    union{
        int i;
        unsigned int ui;
    } intUint;
    intUint.i = x;
    printInBit(intUint.ui, 0);
}

void printInBit(long double x) {
    union {
        long double lDoubleCount;
        int IntCount[4];
    } lDoubleNum;
    lDoubleNum.lDoubleCount = x;

    for(int i = 3; i >= 0; i--) {
        printInBit(lDoubleNum.IntCount[i]);
    }
}



