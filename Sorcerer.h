#pragma once
#include "Villain.h"
/**@param subclass of Villain - inherits all attributes and methods*/
class Sorcerer :public Villain{
public:
	Sorcerer();
	Sorcerer(std::string fileName);
	/*destructor*/
	~Sorcerer();
	/*public methods*/
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

