#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include <stdlib.h>     
#include <time.h> 

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
		bomb.move(0, 1.0f);
	}
	
};