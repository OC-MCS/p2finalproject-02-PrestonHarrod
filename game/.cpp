include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Player.h"

Player::Player(Texture texture, Vector2f coord, int lives)
{
	player.setTexture(texture);
	player.setPosition(coord);
	numlives = lives;
}
void Player::move(int x, int y)
{
	player.move(x, y);
}
int Player::getlives()
{
	return numlives;
}
void Player::deleteLife()
{
	numlives = numlives - 1;
}
void Player::draw(RenderWindow & win)
{
	win.draw(player);
}
void Player::setPosition(Vector2f coord)
{
	player.setPosition(coord);
}
Vector2f Player::getPosition()
{
	return player.getPosition();
}