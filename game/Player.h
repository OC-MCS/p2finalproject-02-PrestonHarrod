#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	int level;
	int lives;
	int aliensKilled;
	RectangleShape startBtn;
public:
	Player()
	{
		level = 0;
		lives = 3;
		aliensKilled = 0;
		Vector2f size;
		size.x = 67;
		size.y = 30;
		startBtn.setSize(size);
		startBtn.setPosition(366, 300);
		startBtn.setFillColor(Color::White);
	}
	
	void drawStart(RenderWindow & win)
	{
		Font font;
		if (!font.loadFromFile("C://Windows//Fonts//arial.ttf"))
		{
			cout << ("couldn't load font");
		}
		Text text("START", font, 25);
		text.setPosition(startBtn.getPosition());
		text.setFillColor(Color::Green);
		win.draw(startBtn);
		win.draw(text);
	}
	void startinput(Vector2f mousepos)
	{
		if (startBtn.getGlobalBounds().contains(mousepos))
		{
			level = 1;
		}
	}
	void drawKillAmount(RenderWindow & win)
	{
		Font font;
		if (!font.loadFromFile("C://Windows//Fonts//arial.ttf"))
		{
			cout << ("couldn't load font");
		}
		string displaykilled = "ALIENS DEFEATED: " + to_string(aliensKilled);
		Text numkilled(displaykilled, font, 25);
		numkilled.setPosition(0, 0);
		numkilled.setFillColor(Color::White);
		win.draw(numkilled);
	}
	void drawLevel(RenderWindow & win)
	{
		Font font;
		if (!font.loadFromFile("C://Windows//Fonts//arial.ttf"))
		{
			cout << ("couldn't load font");
		}
		string displaylevel = "LEVEL:  " + to_string(level);
		Text levelnum(displaylevel, font, 25);
		levelnum.setPosition(275, 0);
		levelnum.setFillColor(Color::White);
		win.draw(levelnum);
	}
	void drawEndGame(RenderWindow & win)
	{
		Font font;
		if (!font.loadFromFile("C://Windows//Fonts//arial.ttf"))
		{
			cout << ("couldn't load font");
		}
		string gameoverstring = "GAME OVER: THE ALIENS ARE VICTORIOUS!";
		Text gameoverdisplay(gameoverstring, font, 40);
		gameoverdisplay.setPosition(300, 400);
		gameoverdisplay.setFillColor(Color::White);
		win.draw(gameoverdisplay);
	}
	void drawWinner(RenderWindow & win)
	{
		Font font;
		if (!font.loadFromFile("C://Windows//Fonts//arial.ttf"))
		{
			cout << ("couldn't load font");
		}
		string youWinString = "YOU WIN: THE ALIENS HAVE BEEN DEFEATED!";
		Text windisplay(youWinString, font, 40);
		windisplay.setPosition(300, 400);
		windisplay.setFillColor(Color::White);
		win.draw(windisplay);
	}
	void drawLives(RenderWindow & win)
	{
		Font font;
		if (!font.loadFromFile("C://Windows//Fonts//arial.ttf"))
		{
			cout << ("couldn't load font");
		}
		string displaylives = "LIVES:  " + to_string(lives);
		Text livesnum(displaylives, font, 25);
		livesnum.setPosition(400, 0);
		livesnum.setFillColor(Color::White);
		win.draw(livesnum);
	}

	int getLevel()
	{
		return level;
	}
	int getLives()
	{
		return lives;
	}
	int getKills()
	{
		return aliensKilled;
	}
	void setLevel(int x)
	{
		level = x;
	}
	void setLives(int x)
	{
		lives = x;
	}
	void setKills(int x)
	{
		aliensKilled = x;
	}
};