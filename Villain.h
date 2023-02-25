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
#include "Character.h"
#include "Hero.h"

class Villain :public Character {
public:
	/*constructors*/
	Villain();
	Villain(std::string fileName, int t);
	/*destructor*/
	~Villain();
	/*public methods*/
	/*changes villain*/
	virtual void change(int i);
	/*gets character's type*/
	virtual bool getAttitude();
	virtual int getType();
	/*gets features*/
	virtual int getHp();
	virtual int getStrength();
	virtual int getMp();
	virtual int getDefense();
	virtual int getSpeed();
	virtual int getSpellDefense();
	/*changes type*/
	virtual void changeType(int t);
	/*after lost*/
	virtual void looseHp(int lost);
	/*checks if character still has hp*/
	virtual bool isAlive();
	/*attacks*/
	virtual int attack();
	/*checks whether the attack is based on strength or magic*/
	virtual bool isASpell();
	/*defenses*/
	virtual void defend(bool isMagical, int howStrong, Hero hero);

};
