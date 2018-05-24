#pragma once
#ifndef STAGE_H
#define STAGE_H

void loadtitle();
void loadintro();
bool loadsl();
void loadcre();
void loadmain();
void outside();
void home();
void colle();
void show_num(int num, int x, int y);//展现数字的函数,如果输出的是两位数，传递第一个左上顶点的坐标。
#endif