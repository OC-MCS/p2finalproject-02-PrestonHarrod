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
	Font font2;


public:
	DrawUI()
	{
		Vector2f size(80, 30);
		startBtn.setSize(size);
		startBtn.setPosition(335, 300);
		startBtn.setFillColor(Color::White);

		if (!font.loadFromFile("C://Windows//Fonts//arial.ttf"))
		{
			cout << ("couldn't load font");
		}
		if (!font2.loadFromFile("C://Windows//Fonts//impact.ttf"))
		{
			cout << ("couldn't load font");
		}

	}

	/**************
	drawStart
	- draws start button
	Params: render window
	Returns: None
	*************/
	void drawStart(RenderWindow & win)
	{
		Text text("PLAY", font, 25);
		text.setPosition(startBtn.getPosition());
		text.setFillColor(Color::Black);
		win.draw(startBtn);
		win.draw(text);
	}

	/**************
	beginGame
	- Sets level to 1 if start button is clicked
	Params: mouse position, player
	Returns: None
	*************/
	void beginGame(Vector2f mousepos, Player &p)
	{
		if (startBtn.getGlobalBounds().contains(mousepos))
		{
			p.setLevel(1);
		}
	}

	/***************
	drawKillAmount
	- draw amount of kills
	Params: renderwindow, player
	Returns: None
	*******************/
	void drawKillAmount(RenderWindow & win, Player &p)
	{
		string displaykilled = "Score: " + to_string(p.getKills());
		Text numkilled(displaykilled, font, 25);
		numkilled.setPosition(0, 0);
		numkilled.setFillColor(Color::White);
		win.draw(numkilled);
	}

	/***************
	drawlevel
	- Draw current level to screen
	Params: renderwinow, player
	Returns; None
	*******************/
	void drawLevel(RenderWindow & win, Player &p)
	{
		string text = "Level:  " + to_string(p.getLevel());
		Text display(text, font, 25);
		display.setPosition(275, 0);
		display.setFillColor(Color::White);
		win.draw(display);
	}

	/***************
	drawEndGame
	- draw end message if player loses
	Params: renderwindow
	Returns: none
	*******************/
	void drawEndGame(RenderWindow & win)
	{
		string text = "Game over. You Lost XD";
		Text display(text, font, 40);
		display.setPosition(200, 100);
		display.setFillColor(Color::White);
		win.draw(display);
	}

	/***************
	drawWinner
	- Draw win message if player wins
	Params: renderwindow
	returns: None
	*******************/
	void drawWinner(RenderWindow & win)
	{
		string text = "Congrats!! You win!!!";
		Text display(text, font, 40);
		display.setPosition(200, 100);
		display.setFillColor(Color::White);
		win.draw(display);
	}

	/***************
	drawLives
	- draws current amount of lives
	Params: renderwindow, player
	Returns: None
	*******************/
	void drawLives(RenderWindow & win, Player p)
	{
		string text = "Lives:  " + to_string(p.getLives());
		Text display(text, font, 25);
		display.setPosition(400, 0);
		display.setFillColor(Color::White);
		win.draw(display);
	}
};
