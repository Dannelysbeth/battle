#pragma once
#include<string>
#include "Character.h"
#include "Villain.h"
class Hero :public Character
{
public:
	Hero();
	Hero(std::string fileName, int t);
	/*destructor*/
	~Hero();
	/*public methods*/
	/*changes hero*/
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
	virtual void defend(bool isMagical, int howStrong, Villain villain);
};

