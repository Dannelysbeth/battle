#include "Dragon.h"

Dragon::Dragon() :Villain("Sources/Villains/dragon.txt", 0 ){}

Dragon::Dragon(std::string fileName) :Villain(fileName, 0){}

Dragon::~Dragon() 
{
	Villain::~Villain();
}

bool Dragon::getAttitude()
{
	bool good = Villain::getAttitude();
	return good;
}

int Dragon::getType()
{
	int type = Villain::getType();
	return type;
}

int Dragon::getHp()
{
	int hp = Villain::getHp();
	return hp;
}

int Dragon::getStrength()
{
	int strength = Villain::getStrength();
	return strength;
}

int Dragon::getMp()
{
	int mp = Villain::getMp();
	return mp;
}

int Dragon::getDefense()
{
	int defense = Villain::getDefense();
	return defense;
}

int Dragon::getSpeed()
{
	int speed = Villain::getSpeed();
	return speed;
}

int Dragon::getSpellDefense()
{
	int spellDefense = Villain::getSpellDefense();
	return spellDefense;
}

void Dragon::looseHp(int lost)
{
	Villain::looseHp(lost);
}

bool Dragon::isAlive()
{
	bool alive = Villain::isAlive();
	return alive;
}

int Dragon::attack()
{
	int attackinPoints = Villain::attack();
	return attackinPoints;
}

bool Dragon::isASpell()
{
	bool spell = Villain::isASpell();
	return spell;
}

void Dragon::defend(bool isMagical, int howStrong, Hero hero)
{
	Villain::defend(isMagical, howStrong, hero);
}
