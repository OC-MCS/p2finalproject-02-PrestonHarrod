#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include <stdlib.h>     
#include <time.h> 

class BombMgr
{
private:
	list<Bomb> bombList;

public:
	BombMgr()
	{
		bombList = {};
	}
	void addBomb(Bomb a)
	{
		bombList.push_back(a);
	}
	void removeBomb();
	void draw(RenderWindow &win)
	{
		list<Bomb>::iterator iter;
		for (iter = bombList.begin(); iter != bombList.end(); iter++)
		{
			iter->draw(win);
		}
	}

};
