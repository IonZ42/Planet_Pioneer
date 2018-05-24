#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<windows.h>
#include<cstring>
#include<fstream>
using namespace std;

//char scene[600][800];
//const int scr_width, scr_height;
//char screen[scr_height][scr_width];
extern HANDLE handle;
extern HANDLE buffer;

extern int key_up, key_click, key_down;
void Gotoxy(int x, int y, HANDLE& handle);
void SetFontSize(int FontSizeX, int FontSizeY, HANDLE& hOut);
void hide_cursor(HANDLE&handle);
void set_console(HANDLE&handle);
void show_screen(HANDLE&buffer, const string &filename, COORD cursor);
void show_screen(HANDLE&buffer, const string &filename, int ,int);
int getx(CONSOLE_SCREEN_BUFFER_INFO);
int gety(CONSOLE_SCREEN_BUFFER_INFO);
int getkey(int);

#endif
