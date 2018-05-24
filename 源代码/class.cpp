#include"stage.h"
#include"class.h"
#include"Functions.h"
#include<ctime>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;

/***************************     初始化各种数据        *********************************************************************/
int life = 0;//游戏运行天数
int slnum = 0;//设置选择哪个存档。
//加载图片的文件名和位置。
text newgame = { ".\\pic\\start\\newgame.txt", { 0, 0 } }, load = { ".\\pic\\start\\load.txt", { 0, 0 } }, exitp = { ".\\pic\\start\\exit.txt", { 0, 0 } }, start = { ".\\pic\\start\\start.txt", { 0, 0 } };
text t3c = { ".\\pic\\UI\\ASCII-3cre.txt", { 250, 200 } }, t4e = { ".\\pic\\UI\\ASCII-4exit.txt", { 250, 250 } }, p = { ".\\pic\\UI\\ASCII-p.txt", { 150, 100 } };
text st1 = { ".\\pic\\CG\\0\\1.txt", { 0, 0 } }, st2 = { ".\\pic\\CG\\0\\2.txt", { 0, 0 } }, st3 = { ".\\pic\\CG\\0\\3.txt", { 0, 0 } };
text UI_out = { ".\\pic\\main\\outside.txt", { 0, 0 } }, UI_ware = { ".\\pic\\main\\colle.txt", { 0, 0 } }, UI_home = { ".\\pic\\main\\home.txt", { 0, 0 } };

//对所有的物品初始化，homeshow，小图，图鉴,。0，成长天数，成熟所需要天数。
obj atc[25]{obj(0,".\\pic\\obj\\01_home.txt", ".\\pic\\obj\\01.txt", ".\\pic\\colle\\01.txt", 0, 0, 3),
obj(1, ".\\pic\\obj\\02_home.txt", ".\\pic\\obj\\02.txt", ".\\pic\\colle\\02.txt", 0, 0, 3),
obj(2, ".\\pic\\obj\\03_home.txt", ".\\pic\\obj\\03.txt", ".\\pic\\colle\\03.txt", 0, 0, 3),
obj(3, ".\\pic\\obj\\04_home.txt", ".\\pic\\obj\\04.txt", ".\\pic\\colle\\04.txt", 0, 0, 3),
obj(4, ".\\pic\\obj\\05_home.txt", ".\\pic\\obj\\05.txt", ".\\pic\\colle\\05.txt", 0, 0, 3),
obj(5, ".\\pic\\obj\\06_home.txt", ".\\pic\\obj\\06.txt", ".\\pic\\colle\\06.txt", 0, 0, 3),
obj(6, ".\\pic\\obj\\07_home.txt", ".\\pic\\obj\\07.txt", ".\\pic\\colle\\07.txt", 0, 0, 3),
obj(7, ".\\pic\\obj\\08_home.txt", ".\\pic\\obj\\08.txt", ".\\pic\\colle\\08.txt", 0, 0, 3),
obj(8, ".\\pic\\obj\\09_home.txt", ".\\pic\\obj\\09.txt", ".\\pic\\colle\\09.txt", 0, 0, 3),
obj(9, ".\\pic\\obj\\10_home.txt", ".\\pic\\obj\\10.txt", ".\\pic\\colle\\10.txt", 0, 0, 3),
obj(10, ".\\pic\\obj\\11_home.txt", ".\\pic\\obj\\11.txt", ".\\pic\\colle\\11.txt", 0, 0, 5),
obj(11, ".\\pic\\obj\\12_home.txt", ".\\pic\\obj\\12.txt", ".\\pic\\colle\\12.txt", 0, 0, 5),
obj(12, ".\\pic\\obj\\13_home.txt", ".\\pic\\obj\\13.txt", ".\\pic\\colle\\13.txt", 0, 0, 5),
obj(13, ".\\pic\\obj\\14_home.txt", ".\\pic\\obj\\14.txt", ".\\pic\\colle\\14.txt", 0, 0, 5),
obj(14, ".\\pic\\obj\\15_home.txt", ".\\pic\\obj\\15.txt", ".\\pic\\colle\\15.txt", 0, 0, 5),
obj(15, ".\\pic\\obj\\16.txt", ".\\pic\\obj\\16.txt", ".\\pic\\colle\\16.txt", 0, 0, 0),
obj(16, ".\\pic\\obj\\17.txt", ".\\pic\\obj\\17.txt", ".\\pic\\colle\\17.txt", 0, 0, 0),
obj(17, ".\\pic\\obj\\18.txt", ".\\pic\\obj\\18.txt", ".\\pic\\colle\\18.txt", 0, 0, 0),
obj(18, ".\\pic\\obj\\19.txt", ".\\pic\\obj\\19.txt", ".\\pic\\colle\\19.txt", 0, 0, 0),
obj(19, ".\\pic\\obj\\20.txt", ".\\pic\\obj\\20.txt", ".\\pic\\colle\\20.txt", 0, 0, 0),
obj(20, ".\\pic\\obj\\21.txt", ".\\pic\\obj\\21.txt", ".\\pic\\colle\\21.txt", 0, 0, 0),
obj(21, ".\\pic\\obj\\22.txt", ".\\pic\\obj\\22.txt", ".\\pic\\colle\\22.txt", 0, 0, 0),
obj(22, ".\\pic\\obj\\23.txt", ".\\pic\\obj\\23.txt", ".\\pic\\colle\\23.txt", 0, 0, 0),
obj(23, ".\\pic\\obj\\24.txt", ".\\pic\\obj\\24.txt", ".\\pic\\colle\\24.txt", 0, 0, 0),
obj(24, ".\\pic\\obj\\25.txt", ".\\pic\\obj\\25.txt", ".\\pic\\colle\\25.txt", 0, 0, 0)
};


obj hplant[5];//基地数据
obj bag[4];//背包数据
obj emp= {};//空物品。
Map map[5]{Map(".\\pic\\map\\1.txt", { 226, 55 }, { 626, 80 }, { 104, 155 }, { 353, 152 }, { 379, 255 }, atc[21], atc[4], atc[23], atc[14], atc[0],0), Map(".\\pic\\map\\2.txt", { 280, 80}, { 553,152 }, {104 , 180}, {628 ,254 }, {628 ,254 }, atc[22], atc[5], atc[10], atc[2], atc[2],1), Map(".\\pic\\map\\3.txt", {681 , 29}, {404 , 104}, { 129,153 }, {554 , 253}, { 580,278 }, atc[19], atc[12], atc[9], atc[24], atc[7],2), Map(".\\pic\\map\\4.txt", {483 , 77}, {330 ,153 }, { 30, 180}, { 484,253 }, {505 ,254 }, atc[20], atc[3], atc[13], atc[1], atc[6],3), Map(".\\pic\\map\\5.txt", {227 ,30 }, {703 ,28 }, { 354, 103}, { 304,154 }, {481 , 154}, atc[16], atc[11], atc[8], atc[18], atc[15],4)
};


/***************************     map类的函数           *********************************************************************/
void show_num(int, int, int);//展示数字的函数。
void clrbag();//清空背包。
void show_cg(int map, int num)//为每个地图设置触发点。
{
	if (map == 0){
		
		if (num == 0)
		{
			int sstate = 0;
			show_screen(buffer, ".\\pic\\CG\\1\\1-1.txt", 0, 0);
			while (1)
			{
				if (getkey(VK_SPACE) == key_click)
				{
					if (sstate == 0)
					{
						show_screen(buffer, ".\\pic\\CG\\1\\1-2.txt", 0, 0); sstate = 1; continue;
					}
					if (sstate == 1)

					{
						show_screen(buffer, ".\\pic\\CG\\1\\1-3.txt", 0, 0); sstate = 2;
					}
					if (sstate == 2)break;
				}

			}
		}
		if (num == 1){
			show_screen(buffer, ".\\pic\\CG\\1\\2.txt", 0, 0);
			while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\1\\2.txt", 0, 0); break; } }
		}
		if (num == 2){
			int sstate = 0;
			show_screen(buffer, ".\\pic\\CG\\1\\3-1.txt", 0, 0);
			while (1)
			{
				if (getkey(VK_SPACE) == key_click)
				{
					if (sstate == 0)
					{
						show_screen(buffer, ".\\pic\\CG\\1\\3-2.txt", 0, 0); sstate = 1; continue;
					}
				
					if (sstate == 1)break;
				}

			}
			
		}
		if (num == 3){ 
			int sstate = 0;
			show_screen(buffer, ".\\pic\\CG\\1\\4-1.txt", 0, 0);
			while (1)
			{
				if (getkey(VK_SPACE) == key_click)
				{
					if (sstate == 0)
					{
						show_screen(buffer, ".\\pic\\CG\\1\\4-2.txt", 0, 0); sstate = 1; continue;
					}
					if (sstate == 1){ break; }

				}

			}
			}

		if (num == 4){ show_screen(buffer, ".\\pic\\CG\\1\\5.txt", 0, 0); while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\1\\5.txt", 0, 0); break; } } }
	}


	if (map == 1){

		if (num == 0)
		{
			int sstate = 0;
			show_screen(buffer, ".\\pic\\CG\\2\\1-1.txt", 0, 0);
			while (1)
			{
				if (getkey(VK_SPACE) == key_click)
				{
					if (sstate == 0)
					{
						show_screen(buffer, ".\\pic\\CG\\2\\1-2.txt", 0, 0); sstate = 1; continue;
					}
					if (sstate == 1)break;
				}

			}
		}
		if (num == 1){
			show_screen(buffer, ".\\pic\\CG\\2\\2.txt", 0, 0); while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\2\\2.txt", 0, 0); break; } }
		}
		if (num == 2){
			
			show_screen(buffer, ".\\pic\\CG\\2\\3.txt", 0, 0); while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\2\\3.txt", 0, 0); break; } }
			}
		if (num == 3){

			show_screen(buffer, ".\\pic\\CG\\2\\4.txt", 0, 0); while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\2\\4.txt", 0, 0); break; } }
		}

		if (num == 4){}
	}

	if (map == 2){

		if (num == 0)
		{
			int sstate = 0;
			show_screen(buffer, ".\\pic\\CG\\3\\1-1.txt", 0, 0);
			while (1)
			{
				if (getkey(VK_SPACE) == key_click)
				{
					if (sstate == 0)
					{
						show_screen(buffer, ".\\pic\\CG\\3\\1-2.txt", 0, 0); sstate = 1; continue;
					}
					if (sstate == 1)break;
				}

			}
		}
		if (num == 1){
			show_screen(buffer, ".\\pic\\CG\\3\\2.txt", 0, 0); while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\3\\2.txt", 0, 0); break; } }
		}
		if (num == 2){

			show_screen(buffer, ".\\pic\\CG\\3\\3.txt", 0, 0);
			while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\3\\3.txt", 0, 0); break; } }
		}
		if (num == 3){

			show_screen(buffer, ".\\pic\\CG\\3\\4-1.txt", 0, 0);
			while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\3\\4-1.txt", 0, 0); break; } }
		}

		if (num == 4){ show_screen(buffer, ".\\pic\\CG\\3\\5.txt", 0, 0);
		while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\3\\5.txt", 0, 0); break; } }
		}
	}

	if (map == 3){

		if (num == 0)
		{	
			show_screen(buffer, ".\\pic\\CG\\4\\1-1.txt", 0, 0);
			while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\4\\1-1.txt", 0, 0); break; } }
		}
		if (num == 1){
			show_screen(buffer, ".\\pic\\CG\\4\\2.txt", 0, 0);
			while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\4\\2.txt", 0, 0); break; } }
		}
		if (num == 2){

			show_screen(buffer, ".\\pic\\CG\\4\\3.txt", 0, 0);
			while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\4\\3.txt", 0, 0); break; } }
		}
		if (num == 3){

			show_screen(buffer, ".\\pic\\CG\\4\\4.txt", 0, 0);
			while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\4\\4.txt", 0, 0); break; } }
		}

		if (num == 4){ show_screen(buffer, ".\\pic\\CG\\4\\5.txt", 0, 0); 
		while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\4\\5.txt", 0, 0); break; } }
		}
	}

	if (map == 4){

		if (num == 0)
		{
			int sstate = 0;
			show_screen(buffer, ".\\pic\\CG\\5\\1-1.txt", 0, 0);
			while (1)
			{
				if (getkey(VK_SPACE) == key_click)
				{
					if (sstate == 0)
					{
						show_screen(buffer, ".\\pic\\CG\\5\\1-2.txt", 0, 0); sstate = 1; continue;
					}
					if (sstate == 1)break;
				}
			}
		}
		if (num == 1){
			show_screen(buffer, ".\\pic\\CG\\5\\2.txt", 0, 0); while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\5\\2.txt", 0, 0); break; } }
		}
		if (num == 2){

			show_screen(buffer, ".\\pic\\CG\\5\\3.txt", 0, 0);
			while (1){ if (getkey(VK_SPACE) == key_click){ show_screen(buffer, ".\\pic\\CG\\5\\3.txt", 0, 0); break; } }
		}
		if (num == 3){
			int sstate = 0;
			show_screen(buffer, ".\\pic\\CG\\5\\4-1.txt", 0, 0);
			while (1)
			{
				if (getkey(VK_SPACE) == key_click)
				{
					if (sstate == 0)
					{
						show_screen(buffer, ".\\pic\\CG\\5\\4-2.txt", 0, 0); sstate = 1; continue;
					}
					if (sstate == 1)break;
				}
			}
		}

		if (num == 4){
			int sstate = 0;
			show_screen(buffer, ".\\pic\\CG\\5\\1-1.txt", 0, 0);
			while (1)
			{
				if (getkey(VK_SPACE) == key_click)
				{
					if (sstate == 0)
					{
						show_screen(buffer, ".\\pic\\CG\\5\\1-2.txt", 0, 0); sstate = 1; continue;
					}
					if (sstate == 1)break;
				}
			}
		}
	}


}
void Map::show_full(int bagn, int x,int y){
	if (bagn >= 4){
		while (1)
		{
			show_screen(buffer, ".\\pic\\CG\\full.txt", 0, 0);
			if (getkey(VK_SPACE) == key_click){ show_main_map(x, y); break; }
			if (getkey(VK_DOWN) == key_click){ show_main_map(x, y); break; }
			if (getkey(VK_RIGHT) == key_click){ show_main_map(x, y); break; }
			if (getkey(VK_UP) == key_click){ show_main_map(x, y); break; }
			if (getkey(VK_RIGHT) == key_click){ show_main_map(x, y); break; }
		}
		return;
	}
}
bool showchoice(int i,int x,int y)//外出探险时，显示是否获取物品
{
	int st=0;
	show_screen(buffer, ".\\pic\\CG\\yes.txt", 0, 0);
	while (1){
		if (getkey(VK_DOWN) == key_click){ st = 1; show_screen(buffer, ".\\pic\\CG\\no.txt", 0, 0); }
		
		if (getkey(VK_UP) == key_click){ st = 0; show_screen(buffer, ".\\pic\\CG\\yes.txt", 0, 0); }
		if (getkey(VK_SPACE) == key_click){ 
			if (st == 1){ map[i].show_main_map(x, y); return 0; }
			if (st == 0){ map[i].show_main_map(x, y); return 1; }
			 }
	}
}
void Map::cg(int x, int y, int& bagn){
	int xd = 25, yd = 26;
	
	if (x >= (cg1.X - xd) && x <= (cg1.X + xd) && y >= (cg1.Y - yd) && y <= (cg1.Y + yd) && b1.judge)
	{
		if (bagn >= 4){
			show_full(bagn, x, y); return;
		}show_cg(numb, 0); 
		if (showchoice(numb, x, y)){
			bag[bagn] = b1; bagn++; b1.judge = 0;
		}
		
	}
	if (x >= (cg2.X - xd) && x <= (cg2.X + xd) && y >= (cg2.Y - yd) && y <= (cg2.Y + yd) && b2.judge)
	{
		if (bagn >= 4){
			show_full(bagn, x, y); return;
		}
		//show_num(bagn, 400, 0);//设置触发点judge=0，表示已经探明。同时触发点的物品给背包。
		show_cg(numb, 1); if (showchoice(numb, x, y)){ bag[bagn] = b2; bagn++;; b2.judge = 0; }
	}
	
	
	if (x >= (cg3.X - xd) && x <= (cg3.X + xd) && y >= (cg3.Y - yd) && y <= (cg3.Y + yd) && b3.judge)
	{
		if (bagn >= 4){
			show_full(bagn, x, y); return;
		}
		 //show_num(bagn, 400, 0);
		show_cg(numb, 2);  if (showchoice(numb, x, y)){ bag[bagn] = b3; bagn++; b3.judge = 0; }
	}
	if (x >= (cg4.X - xd) && x <= (cg4.X + xd) && y >= (cg4.Y - yd) && y <= (cg4.Y + yd) && b4.judge)
	{
		if (bagn >= 4){
			show_full(bagn, x, y); return;
		}
		// show_num(bagn, 400, 0);
		show_cg(numb, 3); if (showchoice(numb, x, y)){ bag[bagn] = b4; bagn++;  b4.judge = 0; }
	}
	if (x >= (cg5.X - xd) && x <= (cg5.X + xd) && y >= (cg5.Y - yd) && y <= (cg5.Y + yd) && b5.judge)
	{
		if (bagn >= 4){
			show_full(bagn, x, y); return;
		}
		 //show_num(bagn, 400, 0);
		show_cg(numb, 4); if (showchoice(numb, x, y)){ bag[bagn] = b5; bagn++; b5.judge = 0; }
	}
	

}
void Map::resetmap()
{
	b1.judge = 1;
	b2.judge = 1;
	b3.judge = 1;
	b4.judge = 1;
	b5.judge = 1;
	

}
void remap()
{
	for (int i = 0; i < 5; i++)
	{
		map[i].resetmap();
	}
}
bool Map::judgecg(int x, int y){
	//hplant[1] = a;
	return true;
}



void show_num(int num, int x, int y)//展现数字的函数,如果输出的是两位数，传递第一个左上顶点的坐标。
{

	int a=-1;//输出十位数
	int b;//输出个位数
	if (num <= 99 && num >= 10)
	{
		a = num / 10;
		b = num - a * 10;
	}
	//if (num > 99){ b = 0; }
	else b = num;
	char t='a';
	switch (b)
	{
	case 0:t = '0'; break;
	case 1:t = '1'; break;
	case 2:t = '2'; break;
	case 3:t = '3'; break;
	case 4:t = '4'; break;
	case 5:t = '5'; break;
	case 6:t = '6'; break;
	case 7:t = '7'; break;
	case 8:t = '8'; break;
	case 9:t = '9'; break;
	default:
		break;
	}

	string title = ".\\pic\\num\\1.txt";
	title[10] = t;
	show_screen(buffer, title, x, y);
	if (a != -1)
	{
		switch (a)
		{
		case 0:t = '0'; break;
		case 1:t = '1'; break;
		case 2:t = '2'; break;
		case 3:t = '3'; break;
		case 4:t = '4'; break;
		case 5:t = '5'; break;
		case 6:t = '6'; break;
		case 7:t = '7'; break;
		case 8:t = '8'; break;
		case 9:t = '9'; break;
		default:
			break;
		}

		title[10] = t;
		show_screen(buffer, title, x - 25, y);
	}

}
void bag_full(){
	while (1)
	{
		show_screen(buffer, newgame.filename, { 0, 0 });
		if (getkey(VK_DOWN) == key_click) {// MyCls(buffer);
			return;
		}
	}
}

void show_day_main(int num, int x, int y, string filename)
{
	show_screen(buffer, filename, 0, 0);
	show_num(num, x, y);
}

BOOL SetConsoleColor(HANDLE&buffer, WORD wAttributes)
{

	if (buffer == INVALID_HANDLE_VALUE)
		return FALSE;

	return SetConsoleTextAttribute(buffer, wAttributes);
}
/***************************     开始界面的选择函数           *********************************************************************/

short staget = 1;//1_newgame,2_loadgame,3_credit,4_exit
short portal = 0;//1_newgame剧情,2_loadgame,3_credit



void startchioce()
{
	int choice = 0; show_screen(buffer, start.filename, { 0, 0 });
	while (1)
	{
		
		
		switch (choice)
		{
		case 0:
			if (_kbhit())
			{
				
				if (getkey(VK_DOWN) == key_click) {
					choice = 1; show_screen(buffer, newgame.filename, { 0, 0 }); continue;
				}
				if (getkey(VK_UP) == key_click) {
					choice = 1; show_screen(buffer, newgame.filename, { 0, 0 }); continue;
				}
				if (getkey(VK_SPACE) == key_click) {
					choice = 1; show_screen(buffer, newgame.filename, { 0, 0 }); continue;
				}
				break;
			}
		case 1:if (_kbhit())
		{
				   show_screen(buffer, newgame.filename, { 0, 0 });
				   if (getkey(VK_DOWN) == key_click) {// MyCls(buffer);
					   choice = 2;  break;
				   }
				   if (getkey(VK_SPACE) == key_click) { portal = 1; loadintro(); break; }
				   break;
		}
		case 2:if (_kbhit())
		{
				   show_screen(buffer, load.filename, { 0, 0 });
				   if (getkey(VK_UP) == key_click) { //MyCls(buffer);
					   choice = 1;
				   }
				   if (getkey(VK_DOWN) == key_click) {// MyCls(buffer);
					   choice = 3;
				   }
				   if (getkey(VK_SPACE) == key_click) { portal = 2;
				   if (loadsl()){ loadmain(); }
				   break;
				   }
				  
				   break;
		}
		case 3:if (_kbhit())
		{
				   show_screen(buffer, exitp.filename, { 0, 0 });
				   if (getkey(VK_UP) == key_click) { //MyCls(buffer);
					   choice = 2;
				   }
				   if (getkey(VK_SPACE) == key_click) { exit(1); }
				   
				   break;
		}
		}
		//break;
	}


}

void loadtitle()
{
	while (1)
	{
		switch (portal)
		{
		case 1: loadintro(); break;
		case 2: {loadsl(); break; }
		case 3: {loadcre(); break; }
		case 4:{ return; }
		}
		startchioce();
		//judgestage(staget);
	}
}

/*************************  调用开头介绍的函数        ***********************************************************************/


short stCG = 1;
short changeCG()
{
	if (getkey(VK_SPACE) == key_click)
	{
		stCG++;
		return stCG;
	}
}
void loadintro()
{
	//SetConsoleColor(buffer, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	//MyCls(buffer);
	while (1)
	{
		system("color F0\n");
		switch (stCG % 9)
		{
		case 1:

			show_screen(buffer, st1.filename, st1.co);
			break;
		case 2:

			show_screen(buffer, st2.filename, st2.co);
			break;
		case 3:
			//SetConsoleColor(buffer, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			show_screen(buffer, st3.filename, st3.co); break;
		case 4:
			show_screen(buffer,".\\pic\\CG\\0\\4.txt" , 0,0);
			break;
		case 5:
			show_screen(buffer, ".\\pic\\CG\\0\\5.txt", 0, 0);
			break;
		case 6:
			show_screen(buffer, ".\\pic\\CG\\0\\6.txt", 0, 0);
			break;
		case 7:
			show_screen(buffer, ".\\pic\\CG\\0\\7.txt", 0, 0);
			break;
		case 8:
			show_screen(buffer, ".\\pic\\CG\\0\\8.txt", 0, 0);
			break;
		
		case 0:
			loadmain();
			break;
		}
		//Sleep(1000);
		changeCG();
	}
}

/***************************      存读档功能       *********************************************************************/
void write()//存档。out,把东西输出到文件。
{
	int wstate = 0;
	if (slnum == 0)
	{
		ifstream fin1("a.dat", std::ios::binary);
		ifstream fin2("b.dat", std::ios::binary);
		int t1, t2;
		fin1.read((char*)&t1, sizeof(int));
		fin2.read((char*)&t2, sizeof(int));
		fin1.close();
		fin2.close();
		if (t1 < t2)wstate = 1;
		else wstate = 2;
	}
	if (slnum == 1||wstate==1)
	{
		std::ofstream fout("a.dat", std::ios::binary);
		fout.write((char*)&life, sizeof(int));
		for (int i = 0; i < 25; i++)
		{
			fout.write((char*)&atc[i].ifopen, sizeof(int));
			fout.write((char*)&atc[i].total, sizeof(int));
		}
		fout.close(); return;
	}

	if (slnum == 2||wstate==2)
	{
		std::ofstream fout("b.dat", std::ios::binary);
		fout.write((char*)&life, sizeof(int));
		for (int i = 0; i < 25; i++)
		{
			fout.write((char*)&atc[i].ifopen, sizeof(int));
			fout.write((char*)&atc[i].total, sizeof(int));
		}
		fout.close(); return;
	}

	
	
	
}


bool loadsl() //读档。
{
	int lstate = 1;
	
	ifstream fin1("a.dat", std::ios::binary);
	ifstream fin2("b.dat", std::ios::binary);
	int t1, t2;
	fin1.read((char*)&t1, sizeof(int));
	fin2.read((char*)&t2, sizeof(int));

	show_screen(buffer, ".\\pic\\sl\\base.txt", 0, 0);

	int choice = 1;
	while (lstate)
	{
		
		if (t1 >= 0)show_screen(buffer, ".\\pic\\sl\\1on.txt", 30, 71);
		if (t2 >= 0)show_screen(buffer, ".\\pic\\sl\\2off.txt", 30, 145);
		while (1){
			if (getkey(VK_DOWN) == key_click && t2 >= 0){
				choice = 2;
				show_screen(buffer, ".\\pic\\sl\\1off.txt", 30, 71)
					; show_screen(buffer, ".\\pic\\sl\\2on.txt", 30, 145);
			}
			if (getkey(VK_UP) == key_click&& t1 >= 0&&t2>=0){
				choice = 1;
				show_screen(buffer, ".\\pic\\sl\\1on.txt", 30, 71);
				show_screen(buffer, ".\\pic\\sl\\2off.txt", 30, 145);
			}
			if (getkey(88) == key_click){
				return 0;
			}
			if (getkey(VK_SPACE) == key_click){
				lstate = 0;
				break;
			}
			//break;
		}
	}
		if (choice == 1 && t1 >= 0)
		{
			std::ifstream fin("a.dat", std::ios::binary);
			fin.read((char*)&life, sizeof(int));
			for (int i = 0; i < 25; i++)
			{
				fin.read((char*)&atc[i].ifopen , sizeof(int));
				fin.read((char*)&atc[i].total, sizeof(int));
			}
			slnum = 1;
			fin.close(); return 1;

		}if (choice == 2 && t2 >= 0)
		{
			std::ifstream fin("b.dat", std::ios::binary);
			fin.read((char*)&life, sizeof(int));
			for (int i = 0; i < 25; i++)
			{
				fin.read((char*)&atc[i].ifopen, sizeof(int));
				fin.read((char*)&atc[i].total, sizeof(int));
			}
			slnum = 2;
			fin.close(); return 1;

		}
		if (getkey(88) == key_click){
			return 0;
		}

	}

	

/********************************   致谢名单。     ****************************************************************/

void loadcre() //致谢名单。
{

}

/*****************************  主界面函数        *******************************************************************/

short portalm = 0;//1_outside,2_home,3_collection,4_sl,5_exit
short stagem = 1;//1_outside,2_home,3_collection,4_sl,5_exit

void ifripe();

void loadmain()
{
	system("color F0\n");
	//text UImain = { ".\\pic\\UI\\ASCII-UImain.txt", { 0, 0 } };

	int choice = 0;
	show_day_main(life, 246, 44, UI_out.filename);
	while (1)
	{
		
	
		if (choice == 0)
		{
			if (getkey(VK_DOWN) == key_click) {// MyCls(buffer);
				choice = 1; show_day_main(life, 246, 44, UI_home.filename);
			}
			if (getkey(VK_SPACE) == key_click) { life++;
			outside(); remap(); clrbag(); ifripe();  write(); show_day_main(life, 246, 44, UI_out.filename);
			}

		}
		else if (choice == 1){
			if (getkey(VK_UP) == key_click) { //MyCls(buffer); 
				choice = 0; show_day_main(life, 246, 44, UI_out.filename);
			}
			if (getkey(VK_DOWN) == key_click) {// MyCls(buffer);
				choice = 2; show_day_main(life, 246, 44, UI_ware.filename);
			}
			if (getkey(VK_SPACE) == key_click) {
				home();
				show_day_main(life, 246, 44, UI_home.filename);
			}
		}
		else if (choice == 2){
			if (getkey(VK_UP) == key_click) { //MyCls(buffer);
				choice = 1; show_day_main(life, 246, 44, UI_home.filename);
			}
			if (getkey(VK_SPACE) == key_click) {
				colle();
				show_day_main(life, 246, 44, UI_ware.filename);
			}
		}

	}
	//judgescene(staget);



}

/****************************     调用外出探险函数        ********************************************************************/
int pre = -1;	//为了避免随时到同一个地图。
void show_map(int &ostate)
{
	srand((unsigned)time(NULL));
	int t=0;
	while(t == pre)
	{
		t = rand() % 5;
		}
	int i = t;
	pre = i;
	
	
	int x = 0; int y = 0;
	
	int xdistant = 25, ydistant = 20;
	map[i].show_main_map(0, 0);
	int bagn=0;//背包里面物品的数量。
	while (1){


		if (_kbhit())
		{
			for (int j = 0; j <= bagn; j++)
			{
				if (bag[j].judge == 1)
				{
					show_screen(buffer, bag[j].smallpic, 50 * j, 274);
				}

			}

			if (getkey(VK_UP) == key_click && (y - ydistant) >= 0){ y = y - ydistant; map[i].show_main_map(x, y); }
			if (getkey(VK_DOWN) == key_click && (y + ydistant) <= 300){ y = y + ydistant; map[i].show_main_map(x, y); }
			if (getkey(VK_LEFT) == key_click && (x - xdistant) >= 0){ x = x - xdistant; map[i].show_main_map(x, y); }

			if (getkey(VK_RIGHT) == key_click && (x + xdistant) <= 800){ x = x + xdistant;  map[i].show_main_map(x, y); }
			//if (getkey(88) == key_click){ ostate = 0; return; }
			if (getkey(VK_SPACE) == key_click)
			{

				map[i].cg(x, y,bagn);
				if ((x >80 && x <= 160 && y >= 247 && y <= 260))//换图函数。
				{
					while (t == pre)
					{
						t = rand() % 5;
					}
					i = t;
					pre = i;
					map[i].show_main_map(x, y);
				}
				if ((x >= 0 && x <= 80 && y >= 247 && y <= 260)){
					ostate = 0; return;
				}
				
			}
		}
	}

}

void outside()
{
	int ostate = 1;
	while (ostate){
		show_map(ostate);
	}; 
	return;

}
int xx = 17, yy = 35;
/*****************************     基地显示函数         *******************************************************************/
void hdelete(int y)//删除种植物。
{
	int i;
	i = (35 - y) / 50;
	hplant[i].judge = 0;
}

int hstate = 1;
void show_home(int j )//输出什么，移动。
{
	
	xx ; yy = yy + j;
	show_screen(buffer, ".\\pic\\home\\plant.txt", 0, 0);

	
	
		for (int i = 0; i < 5; i++)
		{
			if ((yy + i * 50 )>= 0 && (yy + i * 50)<=235 && hplant[i].judge&&hplant[i].num >= 0 && hplant[i].num<10)//judge为1才输出
			{
				show_screen(buffer, hplant[i].name, xx, yy + i * 50);
				show_num(hplant[i].birthday, 290, yy + i * 50 + 15);
			}
		}
		//xx = 17; yy = 35;
}
void show_home2(int j)
{

	xx; yy = yy + j;
	show_screen(buffer, ".\\pic\\home\\animal.txt", 0, 0);

	for (int i = 0; i < 5; i++)
	{
		if ((yy + i * 50) >= 0 && (yy + i * 50) <= 235 && hplant[i].judge&&hplant[i].num >= 10 && hplant[i].num<15)
		{
			show_screen(buffer, hplant[i].name, xx, yy + i * 50);
			show_num(hplant[i].birthday, 290, yy + i * 50 + 15);
		}
	}
}
void show_plant()
{
	while (1){

		if (getkey(VK_UP) == key_click){
			show_home(-50);
		}
		if (getkey(VK_DOWN) == key_click){
			show_home(50);
		}
		if (getkey(VK_SPACE) == key_click){
			hdelete(yy); show_home(0);
		}
		if (getkey(88) == key_click){ hstate = 0; return; }
		if (getkey(VK_RIGHT) == key_click){
			show_screen(buffer, ".\\pic\\home\\animal.txt", 0, 0);
			xx = 17; yy = 35;
			return;
		}
		if (getkey(VK_LEFT) == key_click){
		}
	}
	xx = 17; yy = 35;
}
void show_annimal()
{
	while (1){

		if (getkey(VK_UP) == key_click){
			show_home2(-50);
		}
		if (getkey(VK_DOWN) == key_click){
			show_home2(50);
		}
		if (getkey(VK_SPACE) == key_click){
			hdelete(yy); show_home2(0);
		}
		if (getkey(88) == key_click){ hstate = 0; return; }
		
		
		if (getkey(VK_LEFT) == key_click){
			xx = 17; yy = 35;
			return;
		}
	}
	xx = 17; yy = 35;
}
void clrbag()
{
	for (int i = 0; i < 4; i++)
	{
		if (bag[i].num >= 15 && bag[i].num <= 24)
		{
			for (int j = 15; j<25; j++){
				if (bag[i].num == atc[j].num)
				{
					atc[j].ifopen = 1; atc[j].total++;
					bag[i].judge = 0; break;
				}
			}
		}
	}
	for (int j = 0; j < 4; j++)//把背包里面的东西给养殖库。
	{
		for (int i = 0; i < 5; i++)
		{
			if (hplant[i].judge == 0 && bag[j].judge == 1)//如果养殖库里面没有东西。
			{
				//bag[j].judge = 1; 
				hplant[i] = bag[j]; bag[j].judge = 0;
			}
		}
	}


}
void home()
{
	while (hstate){
		if (hstate)
		{
			show_home(0);
			show_plant();
		}
		if (hstate)
		{
			show_home2(0);
			show_annimal();
		}

	}
	hstate = 1; xx = 17; yy = 35;
	return;
}
/******************************     展示图鉴函数        ******************************************************************/
void ifripe()
{
	for (int i = 0; i < 5; i++)
	if (hplant[i].judge == 1)//如果家里的东西有东西。
	{
		hplant[i].birthday++;
	}
	for (int i = 0; i < 5; i++)
	{
		if (hplant[i].birthday >= hplant[i].ripe_day && hplant[i].judge == 1){
			for (int j = 0; j < 25; j++)
			{
				if (hplant[i].num == atc[j].num)
				{
					atc[j].ifopen = 1;
					atc[j].total++;
					hplant[i] = emp;
					hplant[i].judge = 0;//表示此时不指向。
					
				}
			}
		}

	}
}

void show_colle(int i)
{
	show_screen(buffer, ".\\pic\\colle\\plant.txt", 0, 0);
	show_num(i, 624, 58);
	if (atc[i-1].ifopen == 1)
	{
		show_screen(buffer, atc[i-1].intropc, 0, 0);
		show_num(atc[i - 1].total, 585, 132);
	}
	return;
}
void show_colle2(int i)
{
	show_screen(buffer, ".\\pic\\colle\\animal.txt", 0, 0);
	show_num(i, 624, 58);
	if (atc[i-1].ifopen == 1)
	{
		show_screen(buffer, atc[i-1].intropc, 0, 0);
		show_num(atc[i - 1].total, 585, 132);
	}
	return;
}
void show_colle3(int i)
{
	show_screen(buffer, ".\\pic\\colle\\gem.txt", 0, 0);
	show_num(i, 624, 58);
	if (atc[i-1].ifopen == 1)
	{
		show_screen(buffer, atc[i-1].intropc, 0, 0);
		show_num(atc[i - 1].total, 585, 132);
	}
	return;
}
void plantpic(int&cstate)//atc,0-9;
{
	int ptr = 1;

	while (1){
		if (getkey(VK_LEFT) == key_click){
			ptr++; 
			if (ptr > 10)ptr = 1;
			if (ptr <= 0)ptr = 10;
			show_colle(ptr);
		}
		if (getkey(VK_RIGHT) == key_click&&(ptr-1) >= 0){
			ptr--; 
			if (ptr > 10)ptr = 1;
			if (ptr <= 0)ptr = 10; 
			show_colle(ptr);
		}
		if (getkey(VK_UP) == key_click){
			show_colle2(11);
			return;
		}
		if (getkey(VK_DOWN) == key_click){
			show_colle3(16);
			return;
		}
		if (getkey(88) == key_click){
			cstate = 0; return;
		}

	}
}
void animalpic(int&cstate)//atc,10-14
{
	int ptr = 11;
	while (1){
		if (getkey(VK_LEFT) == key_click){
			ptr++; if (ptr > 15)ptr = 11; if (ptr < 11)ptr = 15;
			show_colle2(ptr);
		}
		if (getkey(VK_RIGHT) == key_click&&(ptr-1) >= 0){
			ptr--; if (ptr > 15)ptr = 11; if (ptr < 11)ptr = 15; show_colle2(ptr);
		}
		if (getkey(VK_UP) == key_click){
			show_colle3(16);
			return;
		}
		if (getkey(VK_DOWN) == key_click){
			show_colle(1);
			return;
		}
		if (getkey(88) == key_click){
			cstate = 0; return;
		}

	}
}

void gempic(int&cstate)//atc,15-24;
{
	int ptr = 16;
	while (1){
		if (getkey(VK_LEFT) == key_click){
			ptr++; if (ptr > 25)ptr = 16; if (ptr < 16)ptr = 25;
			show_colle3(ptr);
		}
		if (getkey(VK_RIGHT) == key_click&&(ptr-1) >= 0){
			ptr--;  if (ptr < 16)ptr = 25; if (ptr < 16)ptr = 25;
			show_colle3(ptr);
		}
		if (getkey(VK_UP) == key_click){
			show_colle(1);
			return;
		}
		if (getkey(VK_DOWN) == key_click){
			show_colle2(11);
			return;
		}
		if (getkey(88) == key_click){
			cstate = 0; return;
		}

	}
}
void colle()
{
	int cstate = 1;
	int ptr = 1;
	show_colle(ptr);
	//show_screen(buffer, atc[0].name, 0, 0);
	while (cstate){
		
		if (cstate){
			plantpic(cstate);
		}
		if (cstate){
			animalpic(cstate);
		}
		if (cstate){
			gempic(cstate);
		}
	}
}

