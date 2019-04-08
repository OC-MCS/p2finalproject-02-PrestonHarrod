#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>

class Alien
{
private:
	Sprite alien;
	bool hit;

public:
	Alien(Vector2f pos)
	{
		alien.setPosition(pos);

		Texture alienTexture;
		if (!alienTexture.loadFromFile("alien.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}
		alien.setTexture(alienTexture);
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
		alien.move(0, 0.3f);
	}

};
