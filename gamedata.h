#pragma once
#include<iostream>
#include<ctime>
using namespace std;
class GameData 
{
public:
	//�����ߴ�
	int Weight{ 90 }, Height{ 25 };
	//����
	int paddle_w{ 3 }, paddle_h{ 8 };											//�ߴ�
	int paddle1_vec{ 1 }, paddle2_vec{ 1 };										//�ٶ�
	int paddle1_x{ 0 }, paddle1_y{ Height / 2 - paddle_h / 2 };					//����
	int paddle2_x{ Weight - paddle_w }, paddle2_y{ Height / 2 - paddle_h / 2 };	//����
	int score1{ 0 }, score2{ 0 },
		score1_x{ Weight / 4 }, score1_y{ paddle_w + 3 },
		score2_x{ 3 * Weight / 4 }, score2_y{ paddle_w + 3 };
	//srand((unsigned)time(0));	//�������������
	//����һ�������������ʾx��y������ٶȵĴ�С
	//��ĳ�ʼ����
	int ball_x{ Weight / 2 }, ball_y{ Height / 2 };
	int ball_vec_x = 1;//rand() % 3 + 1;	//�������Χ��1 - 3
	int ball_vec_y = 1;//rand() % 3 + 1;
	//�ַ��ͳɼ��������жϳ��̣����Ʊ߽磩
	string s1, s2;

	//�ı����ʼ���ٶȷ���(0Ϊ+��1Ϊ-)
	void judgeVec();
	
};