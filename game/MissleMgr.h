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

	void addMissile(Missile m)
	{
		missileList.push_back(m);
	}

	void drawMissiles(RenderWindow &win)
	{
		list<Missile>::iterator iter;

		for (iter = missileList.begin(); iter != missileList.end(); iter++)
		{
			iter->draw(win);
		}
		
	}

	void removeMissile(Sprite background)
	{
		list<Missile>::iterator iter;
		for (iter = missileList.begin(); iter != missileList.end(); )
		{
			if (!background.getGlobalBounds().contains(iter->getPosition()) || iter->getCollision() == true)
			{
				iter = missileList.erase(iter);
				cout << "worked";
			}
			else
				iter++;
		}

	}

	list<Missile> returnMissileList()
	{
		return missileList;
	}

};
