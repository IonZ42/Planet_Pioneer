#include<iostream>
#include<windows.h>
#include<cstring>
#include<fstream>
using namespace std;

//char scene[600][800];
const int scr_width = 801, scr_height = 301;
char screen[scr_height][scr_width];
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE buffer;

int key_up = 0, key_click = 1, key_down = 2;
CONSOLE_SCREEN_BUFFER_INFO bi;


void Gotoxy(int x, int y, HANDLE& handle)//�������Լ�����ĸı����λ��
{
	COORD c = { x, y };//�ṹ���¼�������ꡣ�ṹ�嶨����һ������
	SetConsoleCursorPosition(handle, c);//�������ù��λ�ã���������������ꡣ
}

void SetFontSize(int FontSizeX, int FontSizeY, HANDLE& hOut)//���Դ��������ʲô������
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.X = FontSizeX;
	info.dwFontSize.Y = FontSizeY;
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);//�����������չ��Ϣ��
}

void hide_cursor(HANDLE&handle) 
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = 0;
	cursor.dwSize = 1;
	SetConsoleCursorInfo(handle, &cursor);
}

void set_console(HANDLE&handle)
{	//���������С
	SetFontSize(1, 1, handle);

	//������Ļ��С
	system("mode con cols=801 lines=301");


	//���û������Ĵ�С
	COORD buffer_size = { scr_width, scr_height };
	SetConsoleScreenBufferSize(handle, buffer_size);

	//���ù�������
	void hide_cursor(HANDLE&handle);
}

void show_screen(HANDLE&buffer, const string &filename, COORD cursor)
{
	//��Ҫ��ʾ���ַ�����������
	ifstream get;
	get.open(filename);
	if (!get.good())exit(0);
	for (int i = 0; i < scr_height; i++)
	{
		get.getline(screen[i], scr_width);
		if (!screen[i][0])
		{
			break;
		}
	}
	get.close();

	//����д��������
	for (int i = 0; i <scr_height; i++)
	{
		Gotoxy(cursor.X, cursor.Y + i, buffer);
		WriteConsole(buffer, screen[i], strlen(screen[i]), NULL, NULL);
		if (!screen[i + 1][0])
			break;
	}

	//�������
	SetConsoleActiveScreenBuffer(buffer);

}
void show_screen(HANDLE&buffer, const string &filename, int x,int y)
{
	//��Ҫ��ʾ���ַ�����������
	ifstream get;
	get.open(filename);
	if (!get.good())exit(0);
	for (int i = 0; i < scr_height; i++)
	{
		get.getline(screen[i], scr_width);
		if (!screen[i][0])
		{
			break;
		}
	}
	get.close();

	//����д��������
	for (int i = 0; i <scr_height; i++)
	{
		Gotoxy(x, y + i, buffer);
		WriteConsole(buffer, screen[i], strlen(screen[i]), NULL, NULL);
		if (!screen[i + 1][0])
			break;
	}

	//�������
	SetConsoleActiveScreenBuffer(buffer);

}

int getx(CONSOLE_SCREEN_BUFFER_INFO bi)
{
	return (int)bi.dwCursorPosition.X;
}
int gety(CONSOLE_SCREEN_BUFFER_INFO bi)
{
	return (int)bi.dwCursorPosition.Y;
}

int getkey(int virkey)
{
	static bool pre_key[256] = { 0 };
	if (GetKeyState(virkey) < 0)
	{
		pre_key[virkey] = 1;
		return key_down;
	}
	else
	{
		if (pre_key[virkey])
		{
			pre_key[virkey] = 0;
			return key_click;
		}
		return key_up;
	}
}

