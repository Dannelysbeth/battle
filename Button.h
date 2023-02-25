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


#include "class.h"
#include "function.h"

class Button {
	bool active;
	sf::RectangleShape rec;
public:
	/**@param class Button's constructor*/
	Button();
	/**@param class Button's destructor*/
	~Button();
	/**@param public method of Button - gets rectangleShape attribute rec
	@return rec*/
	sf::RectangleShape Deco();
	/**@param public method of Button - changes rectangleShape attribute rec*/
	void swapButton(sf::RectangleShape button);
	/**@param public method of Button - checks whether button is active
	@return active*/
	bool isActive();
	/**@param public method of Button - changes button activity*/
	void changeActivity(bool activity);

};
