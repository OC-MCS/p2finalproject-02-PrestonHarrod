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

	/***************
	getLevel
	- returns level
	Params: None
	Returns: level (int)
	*******************/
	int getLevel()
	{
		return level;
	}
	/***************
	getLives
	- return lives
	Params: none
	Returns: lives (int)
	*******************/
	int getLives()
	{
		return lives;
	}
	/***************
	getKills
	- returns players score
	params: none
	retuns: kills (int)
	*******************/
	int getKills()
	{
		
		return aliensKilled;
	}
	/***************
	setLevel
	- set players level
	Params: int
	Returns; none
	*******************/
	void setLevel(int x)
	{
		level = x;
	}
	/***************
	setLives
	- set players lives
	Params: int
	Returns: none
	*******************/
	void setLives(int x)
	{
		lives = x;
	}
	/***************
	setKills
	- set players kills
	Params: int
	Returns: none
	*******************/
	void setKills(int x)
	{
		aliensKilled = x;
	}
};