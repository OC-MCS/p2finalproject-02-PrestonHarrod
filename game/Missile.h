#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>

class Missile
{
private:
	Sprite missile;
	bool collide;
public:
	Missile(Vector2f pos, const Texture & text)
	{
		missile.setPosition(pos);
		missile.setTexture(text);
		collide = false;
	}

	/***************
	getCollission
	- returns missiles hit status
	Params: None
	Returns: collide (bool)
	*******************/
	bool getCollision()
	{
		return collide;
	}

	/***************
	setCollision
	- set the missiles collision status
	Params: bool
	Returns: none
	*******************/
	void setCollision(bool x)
	{
		collide = x;
	}

	/***************
	draw
	- draw missile to screen and move it
	Params: renderwindow
	Returns: none
	*******************/
	void draw(RenderWindow &win)
	{
		win.draw(missile);
		missile.move(0, -10.0f);
	}

	/***************
	getPosition
	- returns missiles position
	Params: none
	Returns: missile position (vector2f)
	*******************/
	Vector2f getPosition()
	{
		return missile.getPosition();
	}

};