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

	/***************
	addBomb
	- adds bomb to list
	Params: Bomb
	REturns: none
	*******************/
	void addBomb(Bomb a)
	{
		bombList.push_back(a);
	}

	/***************
	removeBomb
	- If bomb has hit ship or goes beyond ship, erase it and delete life
	Params: ship sprite, player
	Returns: none
	*******************/
	void removeBomb(Sprite &s, Player &p)
	{
		list<Bomb>::iterator iter;
		for (iter = bombList.begin(); iter != bombList.end(); )
		{
			if (iter->returnHit() == true)
			{
				iter = bombList.erase(iter);
				int life = p.getLives();
				life--;
				p.setLives(life);
				cout << "delete life ";
			}
			else if (iter->getPosition().y > s.getPosition().y + 20)
			{
				iter = bombList.erase(iter);
			}
			else
				iter++;
		}

	}
	/***************
	draw
	draws all bombs to the scree
	Params: renderwindow
	Returns: None
	*******************/
	void draw(RenderWindow &win)
	{
		list<Bomb>::iterator iter;
		for (iter = bombList.begin(); iter != bombList.end(); iter++)
		{
			iter->draw(win);
		}
	}

	/***************
	setHits
	- Check if any bomb has hit the ship
	Params: ship sprite
	Returns: None
	*******************/
	void setHits(Sprite &s)
	{
		list<Bomb>::iterator iter;
		for (iter = bombList.begin(); iter != bombList.end(); iter++)
		{
			iter->sethit(s.getPosition());
		}
	}

};
