//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
#include "Missile.h"
#include "MissleMgr.h"
#include "AlienMgr.h"
#include "Player.h"
#include "Bomb.h"
#include "BombMgr.h"
#include <stdlib.h>     
#include <time.h> 
using namespace sf; 

//============================================================
// Preston Harrod
// 4/19/19
// Final Project: Space Invaders
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen
void moveShip(Sprite& ship)
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
}



int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missleTexture;
	if (!missleTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture AlienTexture;
	if (!AlienTexture.loadFromFile("alien.png"))
	{
		cout << "unable to load alien texture" << endl;
		exit(EXIT_FAILURE);
	}
	Texture bombtexture;
	if (!bombtexture.loadFromFile("bomb.png"))
	{
		cout << "unable to load bomb texture" << endl;
		exit(EXIT_FAILURE);
	}



	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);
	
	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.2f;
	ship.setPosition(shipX, shipY);
	
	MissileMgr missileMgr;
	AlienMgr alienMgr(AlienTexture);
	AlienMgr level2Aliens(AlienTexture);
	BombMgr bombMgr;
	Player play;

	int randomNum;
	bool drop;

	int counter = 0;
	int kills;
	bool shoot;
	while (window.isOpen())
	{

		Event event;
		if (play.getLevel() == 0) // no level
		{

			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();


				else if (event.type == Event::MouseButtonReleased)
				{
					//userinput for settings
					Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
					play.startinput(mousePos);

				}

			}
			window.clear();
			window.draw(background);
			play.drawStart(window);
			window.display();
		}
		else if (play.getLevel() == 1 && play.getLives() > 0) //level 1
		{
			counter++;
			if ((counter % 15) == 14)
			{
				shoot = true;
			}
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();
				else if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Space && shoot == true)
					{
						// handle space bar
						Missile *missile = new Missile(ship.getPosition(), missleTexture);
						missileMgr.addMissile(*missile);
						shoot = false;
					}

				}
			}
			window.clear();
			window.draw(background);
			moveShip(ship);
			window.draw(ship);
			if (counter % 20 == 1)
			{
				drop = true;
			}
			randomNum = (rand() % 30);
			if (randomNum == 1 && drop == true)
			{
				alienMgr.dropBombs(bombtexture, bombMgr);
				drop = false;
			}

			play.drawKillAmount(window);
			play.setKills(counter);
			play.drawLives(window);
			play.drawLevel(window);

			alienMgr.setHit(missileMgr);
			alienMgr.removeAlien(background);
			alienMgr.draw(window);

			bombMgr.removeBomb(ship, play);
			bombMgr.draw(window);
			missileMgr.removeMissile(background);
			missileMgr.drawMissiles(window);
			if (alienMgr.returnAlienCount() == 0)
			{
				play.setLevel(2);
			}
			window.display();
		}
		else if (play.getLevel() == 2 && play.getLives() > 0) //notcleared == true && numlives > 0)
		{
			counter++;
			if ((counter % 15) == 14)
			{
				shoot = true;
			}
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();
				else if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Space && shoot == true)
					{
						// handle space bar
						Missile *missile = new Missile(ship.getPosition(), missleTexture);
						missileMgr.addMissile(*missile);
						shoot = false;
					}

				}
			}
			window.clear();
			window.draw(background);
			moveShip(ship);
			window.draw(ship);
			if (counter % 20 == 1)
			{
				drop = true;
			}
			randomNum = (rand() % 30);
			if (randomNum == 1 && drop == true)
			{
				level2Aliens.dropBombs(bombtexture, bombMgr);
				drop = false;
			}

			play.drawKillAmount(window);
			play.setKills(counter);
			play.drawLives(window);
			play.drawLevel(window);
			level2Aliens.setHit(missileMgr);
			level2Aliens.removeAlien(background);
			level2Aliens.draw(window);
			bombMgr.removeBomb(ship, play);
			bombMgr.draw(window);
			missileMgr.removeMissile(background);
			missileMgr.drawMissiles(window);

			window.display();
		}
		else if (play.getLives() == 0)
		{
			play.drawEndGame(window);
		}
		else
		{
			play.drawWinner(window);
		}


		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it




		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================


		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);





		//userint.drawNUMLEVEL(window);

		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)


		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}


