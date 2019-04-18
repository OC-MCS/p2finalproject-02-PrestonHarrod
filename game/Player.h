#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	int level;
	int lives;
	int aliensKilled;
	RectangleShape startBtn;
public:
	Player()
	{
		level = 0;
		lives = 3;
		aliensKilled = 0;
	}

	int getLevel()
	{
		return level;
	}
	int getLives()
	{
		return lives;
	}
	int getKills()
	{
		return aliensKilled;
	}
	void setLevel(int x)
	{
		level = x;
	}
	void setLives(int x)
	{
		lives = x;
	}
	void setKills(int x)
	{
		aliensKilled = x;
	}
};