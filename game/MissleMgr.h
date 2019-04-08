#pragma once
#include "Missile.h"

class MissileMgr
{
private:
	list<Missile> missileList;
public:

	void addMissile(Vector2f pos)
	{
		Missile *missile = new Missile(pos);
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

	void deleteMissile(Sprite s)
	{
		list<Missile>::iterator iter;

		for (iter = missileList.begin(); iter != missileList.end(); )
		{
			if (!s.getGlobalBounds().contains(iter->getPosition()))
			{
				iter = missileList.erase(iter);
			}
			else if (iter->getCollision() == true)
			{
				iter = missileList.erase(iter);
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
