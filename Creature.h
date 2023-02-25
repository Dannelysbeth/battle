#pragma once
/** @file*/
#include<iostream>
#include<vector>
#include <utility>
#include <memory>
#include<ctime>
#include<sstream>
#include <fstream>
#include <stdexcept>


#include <SFML/Graphics.hpp>
#include <SFML/Cursor.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Button.h"
#include "class.h"
#include "function.h"

class Creature {
	bool good;				//attitude
	int type;
	std::string name;
	sf::Texture texture;
	sf::Sprite sprite;

	/**@param private method of class Creature  - sets attitude*/
	void initAttitude(bool isGood);

	/**@param private method of class Creature  - sets type*/
	void initType(int t);

	/**@param private method of class Creature  - sets texture*/
	void initTexture();

	/**@param private method of class Creature  - sets sprite*/
	void initSprite();

	/**@param private method of class Creature  - sets names*/
	void setName();
public:
	/**@param constructor of class Creature without variables*/
	Creature();

	/**@param constructor of class Creature with an attitude variable*/
	Creature(bool isGood);

	/**@param constructor of class Creature with an attitude and type variables*/
	Creature(bool isGood, int subtype);

	/**@param destructor of class Creature*/
	~Creature();

	/*functions*/
	/**@param public method of class Creature - gets texture
	@return texture*/
	sf::Texture& getTexture();

	/**@param public method of class Creature - gets sprite
	@return sprite*/
	sf::Sprite& getSprite();

	/**@param public method of class Creature - gets type
	@return type*/
	int getType();

	/**@param public method of class Creature - gets attitude
	@return good*/
	bool getIfGood();

	/**@param public method of class Creature - gets name
	@return name*/
	const std::string& getName() const;

	/**@param public method of class Creature - changes creature's attitude*/
	void changeAttitude(bool isGood);

	/**@param public method of class Creature - changes creature's type*/
	void changeType(int num);

	/**@param public method of class Creature - changes creature's sprite*/
	void swapSprite(sf::Sprite s);

};
