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


	bool returnHit()
	{
		return hit;
	}

	void sethit(Vector2f missilePos)
	{
		if (alien.getGlobalBounds().contains(missilePos))
		{
 			hit = true;
		}
	}

	Vector2f getPosition()
	{
		return alien.getPosition();
	}

	void draw(RenderWindow &win)
	{
		win.draw(alien);
		alien.move(0, 1);
	}

	void dropbomb(Texture &text, BombMgr &list)
	{
		Bomb* bomb = new Bomb(alien.getPosition(), text);
		list.addBomb(*bomb);
	}

	Vector2f returnInitialPos()
	{
		return initialPos;
	}
	void setPosition(Vector2f pos)
	{
		alien.setPosition(pos);
	}
};
