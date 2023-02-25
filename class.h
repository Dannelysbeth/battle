#pragma once
/** @file*/
#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



/**@param the Button class allows you to activate or deactivate buttons. Extended version of sf :: RectangleShape*/
class Button;

/**@param class Creature is a visual representation of objects of class Character and it's subclasses */
class Creature;


/**@param class GameProgress holds information about current state of game*/
class GameProgress;

/**@param GameView is the most important class of the projects it's main purpose is to render and update the game's interface */
class GameView;


/**@param parent class to Villain and Hero*/
class Character;

/**@param parent class to villain types classes such as Assassin, Sorcerer etc., also subclass to Character*/
class Villain;

/**@param parent class to hero types classes such as Wizard, Elf etc., also subclass to Character*/
class Hero;

/**@param subclass of Villain - inherits all attributes and methods*/
class Assassin;

/**@param subclass of Villain - inherits all attributes and methods*/
class DarkElf;

/**@param subclass of Villain - inherits all attributes and methods*/
class Dragon;

/**@param subclass of Villain - inherits all attributes and methods*/
class Orc;

/**@param subclass of Villain - inherits all attributes and methods*/
class Sorcerer;


/**@param subclass of Hero - inherits all attributes and methods*/
class Elf;

/**@param subclass of Hero - inherits all attributes and methods*/
class Wizard;

/**@param subclass of Hero - inherits all attributes and methods*/
class Thief;

/**@param subclass of Hero - inherits all attributes and methods*/
class Paladin;

/**@param subclass of Hero - inherits all attributes and methods*/
class Warrior;





