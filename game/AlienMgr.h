#pragma once
#include "Alien.h"
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Player.h"

class AlienMgr
{
private:
	list<Alien> alienList;
	list<Alien>::iterator iter;

public:
	AlienMgr()
	{
		Vector2f pos;
		pos.y = 20;
		pos.x = 0;
		for (int i = 0; i < 10; i++)
		{
			pos.x += 65;
			addAlien(pos);
		}
	}

	void addAlien(Vector2f pos)
	{
		Alien *alien = new Alien(pos);
		alienList.push_back(*alien);
	}

	void removeAlien(Player &p)
	{
		list<Alien>::iterator iter;
		for (iter = alienList.begin(); iter != alienList.end(); )
		{
			if (iter->returnHit() == true)
			{
				iter = alienList.erase(iter);
				p.deleteLife();
			}
			else
				iter++;
		}
	}

	void draw(RenderWindow &win)
	{
		list<Alien>::iterator iter;

		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			iter->draw(win);
		}
	}

	void setHit(MissileMgr mgr)
	{
		list<Alien>::iterator iter;
		list<Missile>::iterator it;
		list<Missile> missilelist = mgr.returnMissileList();

		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			for (it = missilelist.begin(); it != missilelist.end(); it++)
			{
				iter->sethit(it->getPosition(), *it);
			}
		}
	}



};
