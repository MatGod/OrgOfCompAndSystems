//
// Created by matgod on 16.10.17.
//

#include <cstdint>
#include <string>
#include "change.h"

using namespace std;

string intToString(int num) {
    string result;
    int bitCount = sizeof(num) * 8;
    for(int i = 0; i < bitCount; i++) {
        result += ((num & 0x80000000) >> 31) + '0';
        num <<= 1;
    }
    return result;
}

string change(string str, unsigned long first_position,
              unsigned long second_position, unsigned long count_of_bits) {
    string start = "", end = "";
    if (first_position != 0) {
        start = str.substr(0, first_position - 1);
    }
    if ((second_position + count_of_bits) < 32) {
        end = str.substr(second_position + count_of_bits + 1);
    }
    string first_group = str.substr(first_position, count_of_bits),
    mid = str.substr(first_position + count_of_bits, second_position - first_position - count_of_bits),
    second_group = str.substr(second_position, count_of_bits);
    return start + second_group + mid + first_group + end;
}