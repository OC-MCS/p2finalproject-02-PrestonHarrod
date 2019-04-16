#pragma once
#include "Alien.h"
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Player.h"
#include "Bomb.h"
#include "BombMgr.h"
#include <stdlib.h>    
#include <time.h> 

class AlienMgr
{
private:
	list<Alien> alienList;
	list<Alien>::iterator iter;

public:
	AlienMgr(Texture &text)
	{
		Vector2f pos;
		pos.y = 20;
		pos.x = 0;
		for (int i = 0; i < 10; i++)
		{
			pos.x += 65;
			addAlien(pos, text);
		}
		
	}

	void addAlien(Vector2f pos, Texture &text)
	{
		Alien *alien = new Alien(pos, text);
		alienList.push_back(*alien);
	}

	void removeAlien(Sprite &s)
	{
		list<Alien>::iterator iter;
		for (iter = alienList.begin(); iter != alienList.end(); )
		{
			if (iter->returnHit() == true | iter->getPosition().y >= s.getPosition().y)
			{
				iter = alienList.erase(iter);
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

	void setHit(MissileMgr &mgr)
	{
		bool x;
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

	Vector2f getRandomAlienPosition()
	{
		int counter = -1;
		int randomAlien;
		srand(time(NULL));
		randomAlien = rand() % 10 + 1;

		list<Alien>::iterator iter;
		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			counter++;
			if (counter == randomAlien)
			{
				return iter->getPosition();
			}
		}
	}



};
