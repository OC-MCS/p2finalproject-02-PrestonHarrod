#pragma once
#include "Player.h"
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class DrawUI
{
private:
	RectangleShape startBtn;
	Font font;


public:
	DrawUI()
	{
		Vector2f size;
		size.x = 70;
		size.y = 30;
		startBtn.setSize(size);
		startBtn.setPosition(400, 300);
		startBtn.setFillColor(Color::White);

		if (!font.loadFromFile("C://Windows//Fonts//arial.ttf"))
		{
			cout << ("couldn't load font");
		}

	}
	void drawStart(RenderWindow & win)
	{
		Text text("PLAY", font, 25);
		text.setPosition(startBtn.getPosition());
		text.setFillColor(Color::Black);
		win.draw(startBtn);
		win.draw(text);
	}
	void startinput(Vector2f mousepos, Player &p)
	{
		if (startBtn.getGlobalBounds().contains(mousepos))
		{
			p.setLevel(1);
		}
	}
	void drawKillAmount(RenderWindow & win, Player &p)
	{
		string displaykilled = "Score: " + to_string(p.getKills());
		Text numkilled(displaykilled, font, 25);
		numkilled.setPosition(0, 0);
		numkilled.setFillColor(Color::White);
		win.draw(numkilled);
	}
	void drawLevel(RenderWindow & win, Player &p)
	{
		string text = "Level:  " + to_string(p.getLevel());
		Text display(text, font, 25);
		display.setPosition(275, 0);
		display.setFillColor(Color::White);
		win.draw(display);
	}
	void drawEndGame(RenderWindow & win)
	{
		string text = "Game over. You Lost XD";
		Text display(text, font, 40);
		display.setPosition(100, 100);
		display.setFillColor(Color::White);
		win.draw(display);
	}
	void drawWinner(RenderWindow & win)
	{
		string text = "Congrats!! You win!!!";
		Text display(text, font, 40);
		display.setPosition(100, 100);
		display.setFillColor(Color::White);
		win.draw(display);
	}
	void drawLives(RenderWindow & win, Player p)
	{
		string text = "Lives:  " + to_string(p.getLives());
		Text display(text, font, 25);
		display.setPosition(400, 0);
		display.setFillColor(Color::White);
		win.draw(display);
	}
};
