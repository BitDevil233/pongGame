#include<windows.h>
#include"tools.h"

void gotoxy(int x, int y) //�����λ���ƶ������꣨x,y��
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hideCursor()		//���ع�� 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}