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

	void draw(RenderWindow &win)
	{
		win.draw(bomb);
		bomb.move(0, 4.0f);
	}

	bool returnHit()
	{
		return hit;
	}

	Vector2f getPosition()
	{
		return bomb.getPosition();
	}

	void sethit(Vector2f shippos)
	{
		if (bomb.getGlobalBounds().contains(shippos))
		{
			cout << "ship was hit by bomb";
			hit = true;
		}
	}
	
};
