#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"
#include "Missile.h"


Alien::Alien(Texture texture, Vector2f coord)
{
	alien.setTexture(texture);
	alien.setPosition(coord);
	hit = false;
}
void Alien::move()
{
	alien.move(0, .3);
}

void Alien::draw(RenderWindow & win)
{
	win.draw(alien);
}

bool Alien::returnHit()
{
	return hit;
}
void Alien::isHit(Vector2f missilepos, Missile obj)
{
	if (alien.getGlobalBounds().contains(missilepos))
	{
		hit = true;
		obj.setUsed(true);
	}

}