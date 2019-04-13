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
	Missile(Vector2f pos, Texture &text)
	{
		collide = false;
		missile.setPosition(pos);
		missile.setTexture(text);
		
	}

	bool getCollision()
	{
		return collide;
	}
	Sprite returnSprite()
	{
		return missile;
	}
	void setCollision(bool x)
	{
		collide = x;
	}

	void draw(RenderWindow &win)
	{
		win.draw(missile);
		missile.move(0, -5.0f);
	}

	Vector2f getPosition()
	{
		return missile.getPosition();
	}

};