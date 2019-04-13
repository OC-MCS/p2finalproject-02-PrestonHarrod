#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class MissileTexture
{
private:
	Texture missiletexture;
public:
	MissileTexture()
	{
		Texture missileTexture;
		if (!missiletexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture" << endl;
			exit(EXIT_FAILURE);
		}
		missiletexture = missileTexture;
	}
	Texture getTexture()
	{
		return missiletexture;
	}
};
