#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include <stdlib.h>     
#include <time.h> 
#include "Player.h"

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
	void removeBomb(Sprite &s, Player p)
	{
		list<Bomb>::iterator iter;
		for (iter = bombList.begin(); iter != bombList.end(); )
		{
			if (iter->returnHit() == true)
			{
				iter = bombList.erase(iter);
				int life = p.getLives();
				p.setLives(life--);
				cout << "LIFE REMOVED ";
			}
			else if (iter->getPosition().y > s.getPosition().y + 50)
			{
				iter = bombList.erase(iter);
			}
			else
				iter++;
		}

	}
	void draw(RenderWindow &win)
	{
		list<Bomb>::iterator iter;
		for (iter = bombList.begin(); iter != bombList.end(); iter++)
		{
			iter->draw(win);
		}
	}

};
