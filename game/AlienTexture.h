#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
class AlienTexture
{
private:
	Texture alienTexture;
public:
	AlienTexture()
	{
		Texture alien;
		if (!alien.loadFromFile("alien.png"))
		{
			cout << "Unable to load missile texture" << endl;
			exit(EXIT_FAILURE);
		}
		alienTexture = alien;
	}

};
