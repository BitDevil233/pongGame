#include"tools.h"
#include"gamedata.h"
#include"controller.h"
using namespace std;

int main() 
{
	GameData gamedata;
	GameData().judgeVec();
	while (true) 
	{
		Controller::operate(gamedata);
		Controller::update(gamedata);

		gotoxy(0, 0);
		hideCursor();	//Òþ²Ø¹â±ê

		Controller::draw(gamedata);
		//²âÊÔGithub
	}

}