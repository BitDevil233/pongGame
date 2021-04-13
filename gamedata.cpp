
#include"gamedata.h"

void GameData::judgeVec() 
{
	if (rand() % 2 == 1) ball_vec_x *= -1;
	if (rand() % 2 == 1) ball_vec_y *= -1;
}