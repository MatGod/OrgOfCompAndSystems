//
// Created by matgod on 16.10.17.
//

#include <cstdint>
#include <string>
#include <iostream>
#include <cmath>
#include "change.h"

using namespace std;

void printInBit(int num) {
    string result;
    int bitCount = sizeof(num) * 8;
    for(int i = 0; i < bitCount; i++) {
        cout << ((num & 0x80000000) >> 31);
        num <<= 1;
    }
}

void printInBit(long double x) {
    union {
        long double lDoubleCount;
        int IntCount[4];
    } lDoubleNum;
    lDoubleNum.lDoubleCount = x;
    for (int i = 3; i >= 0; i--) {
        printInBit(lDoubleNum.IntCount[i]);
    }
}

int reversGroup(int x, unsigned int start_position, unsigned int count_of_bits) {
    if (start_position < 0 || start_position + count_of_bits > 31) {
        cout << "Ошибка. Выход за пределы числа. Операция прервана.\n";
        return x;
    } else {
        unsigned int zeros = UINT32_MAX;
        int int_bit_count = sizeof(int) * 8;
        for (int i = 0; i < count_of_bits; i++) {
            zeros -= pow(2, int_bit_count - start_position - i - 1);
        }
        int ones = ~zeros;
        return ((x & zeros) | (~x & ones));
    }
}

long double reversGroup(long double x, unsigned int start_position, unsigned int count_of_bits) {
    if (start_position < 0 || start_position + count_of_bits > 127) {
        cout << "Ошибка. Выход за пределы числа. Операция прервана.\n";
        return x;
    } else {
        union {
            long double lDoubleCount;
            unsigned IntCount[4];
        } lDoubleNum;
        lDoubleNum.lDoubleCount = x;
        unsigned int zeros[4] = {UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX};
        //int int_bit_count = sizeof(int) * 8;
        int zer_num, pow_step;
        for (int i = 0; i < count_of_bits; i++) {
            zer_num = (start_position + i) / 33;
            pow_step = 32 - ((start_position + i) % 33);
            zeros[zer_num] -= pow(2, pow_step);
        }
        int ones[4] = {~zeros[0], ~zeros[1], ~zeros[2], ~zeros[3]};
        for (int i  = 0; i < 4; i++) {
            lDoubleNum.IntCount[3 - i] = (lDoubleNum.IntCount[3 - i] & zeros[i]) | (~lDoubleNum.IntCount[3 - i] & ones[i]);
        }
        return lDoubleNum.lDoubleCount;
    }
}