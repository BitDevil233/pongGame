#pragma once
#include<iostream>
#include<ctime>
using namespace std;
class GameData 
{
public:
	//画布尺寸
	int Weight{ 90 }, Height{ 25 };
	//挡板
	int paddle_w{ 3 }, paddle_h{ 8 };											//尺寸
	int paddle1_vec{ 1 }, paddle2_vec{ 1 };										//速度
	int paddle1_x{ 0 }, paddle1_y{ Height / 2 - paddle_h / 2 };					//坐标
	int paddle2_x{ Weight - paddle_w }, paddle2_y{ Height / 2 - paddle_h / 2 };	//坐标
	int score1{ 0 }, score2{ 0 },
		score1_x{ Weight / 4 }, score1_y{ paddle_w + 3 },
		score2_x{ 3 * Weight / 4 }, score2_y{ paddle_w + 3 };
	//srand((unsigned)time(0));	//生成随机数种子
	//生成一个随机整数，表示x和y方向的速度的大小
	//球的初始坐标
	int ball_x{ Weight / 2 }, ball_y{ Height / 2 };
	int ball_vec_x = 1;//rand() % 3 + 1;	//随机数范围是1 - 3
	int ball_vec_y = 1;//rand() % 3 + 1;
	//字符型成绩（便于判断长短，控制边界）
	string s1, s2;

	//改变球初始的速度方向(0为+，1为-)
	void judgeVec();
	
};