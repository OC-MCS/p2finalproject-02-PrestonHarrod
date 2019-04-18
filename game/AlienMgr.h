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

	void removeAlien(Sprite &s, Player &p)
	{
		list<Alien>::iterator iter;
		for (iter = alienList.begin(); iter != alienList.end(); )
		{
			if (iter->returnHit() == true)
			{
				int kills = p.getKills();
				kills++;
				p.setKills(kills);
				iter = alienList.erase(iter);
			}
			else if (iter->getPosition().y > s.getPosition().y + 20)
			{
				Vector2f initial = iter->returnInitialPos();
				iter->setPosition(initial);
				cout << "alien deleted";
				int life = p.getLives();
				life--;
				p.setLives(life);
				
				cout << "delete life ";
			}
			else 
			{
				iter++;
			}
				
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
		list<Alien>::iterator iter;
		list<Missile>::iterator it;
		list<Missile> missilelist = mgr.returnMissileList();

		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			for (it = missilelist.begin(); it != missilelist.end(); it++)
			{
				iter->sethit(it->getPosition());
			}
		}
	}

	void dropBombs(Texture &text, BombMgr &bombMgr)
	{
		int x;
		list<Alien>::iterator iter;
		srand(time(0));

		bool shoot = true;
		for (iter = alienList.begin(); iter != alienList.end() && shoot == true; iter++)
		{
			x = (rand() % 10);
			if (x == 1)
			{
				iter->dropbomb(text, bombMgr);
				shoot = false;
			}
		}
	}

	int returnAlienCount()
	{
		return alienList.size();
	}
};
