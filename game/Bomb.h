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
	Bomb(Vector2f pos) 
	{
		hit = false;
		bomb.setPosition(pos);
		Texture bombTexture;
		if (!bombTexture.loadFromFile("bomb.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}
		bomb.setTexture(bombTexture);
		bomb.setScale(0.025, 0.025);
	}

	void draw(RenderWindow &win)
	{
		win.draw(bomb);
		bomb.move(0, 1.3f);
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
			cout << "SHIP HIT";
			hit = true;
		}
	}
	
};
