#pragma once
#include<iostream>
#include"gamedata.h"

class Controller 
{
public:
	Controller() {}
	static void operate(GameData& gamedata);
	static void update(GameData& gamedata);
	static void draw(GameData& gamedata);
private:

};