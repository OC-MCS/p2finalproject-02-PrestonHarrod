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

class Bomb
{
private:
	Sprite bomb;
	bool hit;

public:
	Bomb(Vector2f pos, Texture &text) 
	{
		hit = false;
		bomb.setPosition(pos);
		bomb.setTexture(text);
		bomb.setScale(0.10, 0.10);
	}

	/***************
	draw
	- draws bombs to screen and moves them
	Params: renderwindow
	Returns: none
	*******************/
	void draw(RenderWindow &win)
	{
		win.draw(bomb);
		bomb.move(0, 4.0f);
	}

	/***************
	returnHit
	- returns hit status
	Params: None
	Returns: hit (bool)
	*******************/
	bool returnHit()
	{
		return hit;
	}

	/***************
	getPosition
	- returns bombs position
	Params: None
	Returns: bombs position (vector2f)
	*******************/
	Vector2f getPosition()
	{
		return bomb.getPosition();
	}

	/***************
	sethit
	- set bombs hit to true if it hits the ship
	Params: ships position (vector2f)
	Returns: None
	*******************/
	void sethit(Vector2f shippos)
	{
		if (bomb.getGlobalBounds().contains(shippos))
		{
			cout << "ship was hit by bomb";
			hit = true;
		}
	}
	
};
