#include<iostream>
#include"controller.h"
#include<conio.h>
#include<string>
using namespace std;
/// <summary>
/// �Ե���������²���
/// </summary>
/// <param name="gamedata"></param>
void Controller::operate(GameData& gamedata)
{
	//1.�����¼��������̵��û��������λ�ñ仯��
	if (_kbhit())
	{
		char key = _getch();
		if ((key == 'w' || key == 'W') && gamedata.paddle1_y >= gamedata.paddle1_vec)	//(���� / ��λ)
		{
			gamedata.paddle1_y -= gamedata.paddle1_vec;
		}
		else if ((key == 's' || key == 'S') && gamedata.paddle1_y + gamedata.paddle1_vec <= gamedata.Height - gamedata.paddle_h)
		{
			gamedata.paddle1_y += gamedata.paddle1_vec;
		}
		else if (key == 72 && gamedata.paddle2_y >= gamedata.paddle2_vec)				//(���� / ��λ)
		{
			gamedata.paddle2_y -= gamedata.paddle2_vec;
		}
		else if (key == 80 && gamedata.paddle2_y + gamedata.paddle2_vec <= gamedata.Height - gamedata.paddle_h)
		{
			gamedata.paddle2_y += gamedata.paddle2_vec;
		}
	}
}
/// <summary>
/// ������Ϸ����
/// </summary>
/// <param name="gamedata"></param>
void Controller::update(GameData &gamedata) 
{
	//2.�������ݡ������λ��
	gamedata.ball_x += gamedata.ball_vec_x;
	gamedata.ball_y += gamedata.ball_vec_y;
	//�����컨��͵ذ壬y�ٶȷ���
	if (gamedata.ball_y < 0 || gamedata.ball_y > gamedata.Height)
	{
		gamedata.ball_vec_y *= -1;
	}
	//��������
	if (gamedata.ball_x == gamedata.paddle1_x + gamedata.paddle_w &&
		gamedata.ball_y >= gamedata.paddle1_y &&
		gamedata.ball_y <= gamedata.paddle1_y + gamedata.paddle_h)
	{
		gamedata.ball_vec_x *= -1; //x������
		gamedata.score1++;
	}
	else if (gamedata.ball_x == gamedata.paddle2_x &&
		gamedata.ball_y >= gamedata.paddle2_y &&
		gamedata.ball_y <= gamedata.paddle2_y + gamedata.paddle_h)
	{
		gamedata.ball_vec_x *= -1;
		gamedata.score2++;
	}
	//���Ƴɼ�
	gamedata.s1 = std::to_string(gamedata.score1), gamedata.s2 = std::to_string(gamedata.score2);
	//�жϽ���
	bool is_out{ false };
	if (gamedata.ball_x > gamedata.Weight || gamedata.ball_x < 0)
	{
		is_out = true;
	}
	if (is_out)
	{
		gamedata.ball_x = gamedata.Weight / 2;
		gamedata.ball_y = gamedata.Height / 2;
		gamedata.score1 = 0;
		gamedata.score2 = 0;
	}
}
/// <summary>
/// ������Ϸ��ʱ��״̬ͼ
/// </summary>
/// <param name="gamedata"></param>
void Controller::draw(GameData& gamedata)
{
	//3.1���컨��
	for (auto x{ 0 }; x < gamedata.Weight; x++)
	{
		std::cout << "=";
	}
	std::cout << endl;
	//3.2���������ߡ��򡢵���
	for (auto y{ 0 }; y < gamedata.Height; y++)
	{
		for (auto x{ 0 }; x <= gamedata.Weight; x++)
		{
			if (x == gamedata.ball_x && y == gamedata.ball_y)
			{
				std::cout << '0';
			}
			else if (x >= gamedata.paddle1_x &&
				x <= gamedata.paddle1_x + gamedata.paddle_w &&
				y >= gamedata.paddle1_y && y <= gamedata.paddle1_y + gamedata.paddle_h)
			{
				std::cout << 'z';
			}
			else if (x >= gamedata.paddle2_x &&
				x <= gamedata.paddle2_x + gamedata.paddle_w &&
				y >= gamedata.paddle2_y &&
				y <= gamedata.paddle2_y + gamedata.paddle_h)
			{
				std::cout << 'z';
			}
			else if (x == gamedata.score1_x && y == gamedata.score1_y)
			{
				std::cout << gamedata.s1;
				if (gamedata.s1.size() > 1)
				{
					x++;
				}
			}
			else if (x == gamedata.score2_x && y == gamedata.score2_y)
			{
				std::cout << gamedata.s2;
				if (gamedata.s2.size() > 1)
				{
					x++;
				}
			}
			else if (x == 0 || x == gamedata.Weight / 2 || x == gamedata.Weight)
			{
				std::cout << '|';
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << endl;
	}
	//3.3���ذ�
	for (auto x{ 0 }; x < gamedata.Weight; x++)
	{
		std::cout << "=";
	}
	std::cout << endl;
}