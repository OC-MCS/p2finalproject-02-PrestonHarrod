#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>

class Player
{
private:
	int numlives;
	CircleShape life1;
	CircleShape life2;
	CircleShape life3;
	
public:
	Player()
	{
		numlives = 3;
	}
	int getlives()
	{
		return numlives;
	}
	void deleteLife()
	{
		numlives -= 1;
		if (numlives == 2)
		{
			life3.setFillColor(Color::Transparent);
		}
		else if (numlives == 1)
		{
			life2.setFillColor(Color::Transparent);
		}
		else if (numlives == 0)
		{
			life1.setFillColor(Color::Transparent);
			//endGame();
		}

	}

	void setLives(int x)
	{
		numlives = x;
	}

	void draw(RenderWindow & win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			cout << "couldn't load font";
		Text title("Lives", font, 20);
		Text lives;
		title.setPosition(30, 25);
		win.draw(title);

		Vector2f pos(100, 30);
		Vector2f pos2(125, 30);
		Vector2f pos3(150, 30);

		life1.setPosition(pos);
		life2.setPosition(pos2);
		life3.setPosition(pos3);

		life1.setRadius(5);
		life2.setRadius(5);
		life3.setRadius(5);

		life1.setFillColor(Color::Green);
		life2.setFillColor(Color::Green);
		life3.setFillColor(Color::Green);

		win.draw(life1);
		win.draw(life2);
		win.draw(life3);

	}

};
