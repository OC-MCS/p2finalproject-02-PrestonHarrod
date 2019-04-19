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
	/*********
	addAlien
	- dynamically allocates new alien and adds it to list of aliens
	Params: aliens position, texture
	Returns: None
	*********/
	void addAlien(Vector2f pos, Texture &text)
	{
		Alien *alien = new Alien(pos, text);
		alienList.push_back(*alien);
	}

	/**********
	removeAlien
	- Goes through list of aliens and checks if alien has been hit or is past ship
	- If either is true, the alien is erased from the list
	Params: Ship sprite, player
	Returns: none
	*********/
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
				int life = p.getLives();
				life--;
				p.setLives(life);
				
			}
			else 
			{
				iter++;
			}
				
		}
	}
	/********
	draw
	- Draws each alien to screen
	Prams: window
	Returns: None
	********/
	void draw(RenderWindow &win)
	{
		list<Alien>::iterator iter;

		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			iter->draw(win);
		}
	}
	/*******
	setHit
	- Goes through each alien and missile and checks if they have collided
	Prams: missile manager
	Returns: None
	*****/
	void setHit(MissileMgr &mgr)
	{
		list<Alien>::iterator iter;
		list<Missile>::iterator it;
		list<Missile> missilelist = mgr.returnMissileList();

		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			for (it = missilelist.begin(); it != missilelist.end(); it++)
			{
				iter->makeHit(it->getPosition(), *it);
			}
		}
		mgr.setList(missilelist);
	}

	/*************
	dropBombs
	- Selects random alien and drops a bomb
	Prams: texture, bomb manager
	Returns: None
	***********/
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
				iter->dropBomb(text, bombMgr);
				shoot = false;
			}
		}
	}

	/************
	returnAlienCount
	- returns amount of aliens left in the list
	Params: None
	Returns: size of alien list (int)
	**************/
	int returnAlienCount()
	{
		return alienList.size();
	}

	/***********
	deleteList
	- Deletes list of aliens
	Params: None
	Returns: None
	**************/
	void deleteList()
	{
		list<Alien>::iterator iter;

		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			iter = alienList.erase(iter);
		}
	}

	/**************
	remakeList
	- Remake the list of aliens
	Params: texture
	Returns: None
	*************/
	void remakeList(Texture &text)
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
};
