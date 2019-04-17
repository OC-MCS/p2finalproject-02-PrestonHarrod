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

public:
	Alien(Vector2f pos, Texture &text)
	{
		alien.setPosition(pos);
		alien.setTexture(text);
		alien.setScale(0.025, 0.025);
	}


	bool returnHit()
	{
		return hit;
	}

	void sethit(Vector2f missilePos, Missile mis)
	{
		if (alien.getGlobalBounds().contains(missilePos))
		{
 			hit = true;
			mis.setCollision(true);
		}
	}

	Vector2f getPosition()
	{
		return alien.getPosition();
	}

	void draw(RenderWindow &win)
	{
		win.draw(alien);
		alien.move(0, 0.5f);
	}

	void dropbomb(Texture &text, BombMgr &list)
	{
		Bomb* bomb = new Bomb(alien.getPosition());
		list.addBomb(*bomb);
	}

};
