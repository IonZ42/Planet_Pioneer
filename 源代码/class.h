#pragma once
#ifndef TEXT_H
#define TEXT_H
#include<windows.h>
#include<string>
#include "Functions.h"
using namespace std;


class obj{
public:
	int num;//编号。
	string name;
	string smallpic;//小图标
	string intropc;//介绍图鉴
	int grow_day;
	int birthday;
	int ripe_day;
	int judge=0;//判断是否被赋予值。或者是说是否指向。
	int ifopen = 0;//判断仓库中的该图鉴是否开启。
	int total = 0;//总数

	obj(int n, string a, string b, string c, int d, int e, int f, int = 1){ num = n; name = a; smallpic = b; intropc = c; grow_day = d; birthday = e; ripe_day = f; judge = 1; ifopen = 0; total = 0; }
	obj(){ num = -1; judge = 0;  ifopen = 0; total = 0; birthday = 0;};//一开始，judge=0；被同类对象直接赋值后，judge=1；
	obj operator=(obj& aa){
		num = aa.num;
		name = aa.name;
		smallpic = aa.smallpic;
		intropc = aa.intropc;
		grow_day = aa.grow_day;
		birthday = aa.birthday;
		ripe_day = aa.ripe_day;
		judge = aa.judge;
		ifopen = aa.ifopen;
		return *this;
	}
	void text();


};

class arobj{
public:
	int size;
	obj* p;
	arobj(int s)
	{
		p = new obj[s];
		size = s;
	}
	obj& operator [](int i)
	{
		if (i >= size)
		{
			// 越界处理
		}
		return p[i];
	}
};
class text
{
public:
	string filename;
	COORD co;
};

struct data
{
	string index;
	int day;

};
struct point{
	short x;
	short y;
};
struct bag{
	point bag_posi;
	int if_empty = 1;
};

class Map
{
public:
	
	string map_name;
	COORD cg1, cg2, cg3, cg4, cg5;
	obj b1, b2, b3, b4, b5;
	int numb;

	//point back_home_point;

public:
	Map(string, COORD, COORD, COORD, COORD, COORD, obj, obj, obj, obj, obj,int);
	Map(string,  COORD, obj);
	Map(string);
	void show_full(int ,int ,int);
	short index;
	void show_main_map(int, int );
	bool judgecg(int x,int y);
	void cg(int x, int y,int &bagn);
	void resetmap();

};

void Map::show_main_map(int x, int y){
	show_screen(buffer, map_name, 0,0);
	show_screen(buffer, ".\\pic\\map\\dot.txt", x, y);
	//show_screen(buffer, foot_name, x+25, y+25);
}
Map::Map(string s1, COORD a, COORD b, COORD c, COORD d, COORD e, obj a1, obj a2, obj a3, obj a4, obj a5,int n){
	map_name = s1;

	cg1 = a;
	cg2 = b;
	cg3 = c;
	cg4 = d;
	cg5 = e;

	b1 = a1;
	b2 = a2;
	b3 = a3;
	b4 = a4;
	b5 = a5;

	numb = n;

}
Map::Map(string s1, COORD a, obj a1)
{
	map_name = s1;
	cg1 = a;
	b1 = a1;

}

Map::Map(string s1){
	map_name = s1;
	
}


class articles {
protected :
	string name;
	string filename;
public:
	void bag_show();
	void warehouse_show();
};

class creature:public articles{
protected:
	int ripe_day;
	int grow_name;
public:

};

class treasure :public articles{
protected:
public:

};


void articles::bag_show(){

}

#endif