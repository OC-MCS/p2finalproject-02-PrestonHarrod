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

	void addMissile(Vector2f pos, Texture &text)
	{
		Missile *missile = new Missile(pos, text);
		missileList.push_back(*missile);
	}

	void drawMissiles(RenderWindow &win)
	{
		list<Missile>::iterator iter;

		for (iter = missileList.begin(); iter != missileList.end(); iter++)
		{
			iter->draw(win);
		}
		
	}

	void deleteMissile(Sprite &s)
	{
		list<Missile>::iterator iter;

		for (iter = missileList.begin(); iter != missileList.end(); )
		{
			if (!s.getGlobalBounds().contains(iter->getPosition()))
			{
				iter = missileList.erase(iter);
				cout << "Missile hit bounds";
			}
			else if (iter->getCollision() == true)
			{
				iter = missileList.erase(iter);
				cout << "Missile hit alien";
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
