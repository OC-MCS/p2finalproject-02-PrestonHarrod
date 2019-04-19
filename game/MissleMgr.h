#pragma once
#include "Missile.h"
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
class MissileMgr
{
private:
	list<Missile> missileList;
public:

	/***************
	addMissile
	-adds missile to list
	Params: missile
	Returns: none
	*******************/
	void addMissile(Missile m)
	{
		missileList.push_back(m);
	}

	/***************
	drawMissiles
	- draws missiles to screen
	Params: render window
	REturns: none
	*******************/
	void drawMissiles(RenderWindow &win)
	{
		list<Missile>::iterator iter;

		for (iter = missileList.begin(); iter != missileList.end(); iter++)
		{
			iter->draw(win);
		}
		
	}

	/***************
	removeMissile
	- removes missile if it has hit an alien or gone off screen
	Params: background sprite
	REturns: none
	*******************/
	void removeMissile(Sprite background)
	{
		list<Missile>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end(); )
		{
			if (!background.getGlobalBounds().contains(iter->getPosition()) || iter->getCollision() == true)
			{
				iter = missileList.erase(iter);
			}
			else
				iter++;
		}

	}

	/***************
	returnMissileList
	- returns list of missiles
	Params: none
	returns: list<Missile>
	*******************/
	list<Missile> returnMissileList()
	{
		return missileList;
	}

	/***************
	setList
	- set list to whatever is passed
	Params: list<Missile>
	Returns: None
	*******************/
	void setList(list<Missile> x)
	{
		missileList = x;
	}
};
