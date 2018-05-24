#include<iostream>
#include<windows.h>
#include<cstring>
#include<fstream>
#include<ctime>

//#include"class.h"
#include"Functions.h"
#include"stage.h"
using namespace std;


int main()
{
	SetFontSize(1, 1, handle);
	buffer = CreateConsoleScreenBuffer
		(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CONSOLE_TEXTMODE_BUFFER, 0);//创建缓冲区。
	set_console(buffer);//设置缓冲区。

	/*srand(time(0));
	while (1){
		paintchoice();
		judgestage(staget);
		switch (portal)
		{
		case 1: loadintro(); break;
		case 2: {loadsl(); break; }
		case 3: {loadcre(); break; }
		case 4:{ return 0; }
		}
	}*/
	//system("color F0\n");
	//loadmain();
	loadtitle();
	system("pause");
	return 0;
}
