//
// Created by matgod on 18.10.17.
//

#ifndef LAB_2_WORK_H
#define LAB_2_WORK_H

#include <ncurses.h>
#include <panel.h>
#include <malloc.h>
#include <cstring>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define msleep(msec) Sleep(msec)
#else
#include <unistd.h>

#include "conio.h"

#define msleep(msec) usleep(msec*1000)
#endif

#include <string>

int lab2() {
    initscr(); //инициализируем библиотеку

    /******************/
    curs_set(0); //"Убиваем" курсор, чтобы не мешался
    char* colors[8] = {"BLACK", "RED", "GREEN", "YELLOW",
                                        "BLUE", "LILAC", "LIGHTBLUE", "WHITE"};
    textbackground(0);
    window(25, 12, 55, 23);
    std::string background_name, font_name;
    while (true) {
        for (int i = 0; i < 8; ++i) {
            textbackground(i);
            for (int j = 0; j < 8; ++j) {
                textcolor(j);
                cprintf("Background: %s, text: %s\n\n", colors[i], colors[j]);
                msleep(600);
            }
        }
    }

    /*****************/
    endwin();                    // Выход из curses-режима. Обязательная команда.
    return 0;
}

#endif //LAB_2_WORK_H
