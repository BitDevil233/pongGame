#include<windows.h>
#include"tools.h"

void gotoxy(int x, int y) //将光标位置移动到坐标（x,y）
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor()		//隐藏光标 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}