#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include "BombMgr.h"

class Alien
{
private:
	Sprite alien;
	bool hit;
	Vector2f initialPos;

public:
	Alien(Vector2f pos, Texture &text)
	{
		alien.setPosition(pos);
		alien.setTexture(text);
		initialPos = pos;
		alien.setScale(0.050, 0.050);
	}

	/**************
	returnHit
	- return hit value
	Params: none
	Returns: bool
	*************/
	bool returnHit()
	{
		return hit;
	}

	/**************
	makeHit
	- If alien and missile collide, set missile and alien as hit
	Params: missile position, missile
	Returns: None
	*************/
	void makeHit(Vector2f pos, Missile &mis)
	{
		if (alien.getGlobalBounds().contains(pos))
		{
 			hit = true;
 			mis.setCollision(true);
		}
	}

	/**************
	getPosition
	- Return aliens position
	Params: None
	Returns: position (Vector2f)
	*************/
	Vector2f getPosition()
	{
		return alien.getPosition();
	}

	/**************
	draw
	- Draw alien
	Params: None
	Returns: None
	*************/
	void draw(RenderWindow &win)
	{
		win.draw(alien);
		alien.move(0, 1);
	}

	/**************
	dropBomb
	- Create new bomb and add it to the list of bombs
	Params: texture, bomb manager
	Returns: None
	*************/
	void dropBomb(Texture &text, BombMgr &list)
	{
		Bomb* bomb = new Bomb(alien.getPosition(), text);
		list.addBomb(*bomb);
	}

	/**************
	returnInitialPos
	- return aliens original position
	Params: None
	returns: position (Vector2f)
	*************/
	Vector2f returnInitialPos()
	{
		return initialPos;
	}
	void setPosition(Vector2f pos)
	{
		alien.setPosition(pos);
	}
};
