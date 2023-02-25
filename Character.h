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
class Character {
	std::string name;
	int type;
	bool good;
	int hp;
	int strength;
	int mp;
	int defense;
	int speed;
	int spellDefense;
	bool magicAttack;

	/*private methods*/
	/**@param private method of class Character - initializes character's features*/
	virtual void initFeatures();

	/**@param private method of class Character - initializes character's features from file*/
	virtual void initFeatures(std::string fileName);

	/**@param private method of class Character - initializes character's type*/
	virtual void initType(int t);

	/**@param private method of class Character - initializes character's attitude*/
	virtual void initAttitude(bool isGood);

	/**@param private method of class Character - changes hp after strike*/
	virtual void changeHp(int newHp);

public:
	/*constructors*/
	/**@param constructor of class Character without any variables*/
	Character();

	/**@param constructor of class Character with an attitude variable*/
	Character(bool isGood);

	/**@param constructor of class Character with an attitude, type and string variables*/
	Character(std::string fileName, int t, bool isGood);

	/**destructor of class Character*/
	~Character();

	/*public methods*/
	/**@param public method of class Character - changes character's type and attitude*/
	virtual void change(int i, bool isGood);

	/**@param public method of class Character - gets character's name
	@return name*/
	virtual std::string getName();

	/**@param public method of class Character - gets character's attitude
	@return good*/
	virtual bool getAttitude();

	/**@param public method of class Character - gets character's type
	@return type*/
	virtual int getType();

	/*gets features*/
	/**@param public method of class Character - gets character's hp
	@return hp*/
	virtual int getHp();

	/**@param public method of class Character - gets character's strength
	@return strength*/
	virtual int getStrength();

	/**@param public method of class Character - gets character's mp
	@return mp*/
	virtual int getMp();

	/**@param public method of class Character - gets character's defense
	@return defense*/
	virtual int getDefense();

	/**@param public method of class Character - gets character's speed
	@return speed*/
	virtual int getSpeed();

	/**@param public method of class Character - gets character's spell defense
	@return spellDefense*/
	virtual int getSpellDefense();


	/*changes type*/
	/**@param public method of class Character - changes character's attitude*/
	virtual void changeAttitude(bool isGood);

	/**@param public method of class Character - changes character's type*/
	virtual void changeType(int t);

	/**@param public method of class Character - decreases character's hp*/
	virtual void looseHp(int lost);

	/**@param public method of class Character - checks if character still has hp
	@return alive*/
	virtual bool isAlive();

	/**@param public method of class Character - generates attack*/
	virtual int attack();

	/**@param public method of class Character - checks if character attack is a spell or not
	@return magicAttack*/
	virtual bool isASpell();

	/**@param public method of class Character - generates defense*/
	virtual void defend(bool isMagical, int howStrong, Character character);

};
/*
//a class that inherits from the Character class and is a parent of various classes of enemy types
class Hero :public Character {

};

//a class that inherits from the Character class and is a parent of various classes of enemy types
class Villain :public Character;


class Paladin :public Hero {

};
class Wizard :public Hero {

};
class Warrior :public Hero {

};
class Light_Elf :public Hero {

};
class Thief :public Hero {

};

class Dragon :public Villain {

};
class Dark_Elf :public Villain {

};
class Sorcerer :public Villain {

};
class Assassin :public Villain {

};
class Troll :public Villain {

};
*/
