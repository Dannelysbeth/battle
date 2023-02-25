#include "Sorcerer.h"

Sorcerer::Sorcerer() :Villain("Sources/Villains/sorcerer.txt", 2) {}

Sorcerer::Sorcerer(std::string fileName) : Villain(fileName, 2) {}

Sorcerer::~Sorcerer()
{
	Villain::~Villain();
}

bool Sorcerer::getAttitude()
{
	bool good = Villain::getAttitude();
	return good;
}

int Sorcerer::getType()
{
	int type = Villain::getType();
	return type;
}

int Sorcerer::getHp()
{
	int hp = Villain::getHp();
	return hp;
}

int Sorcerer::getStrength()
{
	int strength = Villain::getStrength();
	return strength;
}

int Sorcerer::getMp()
{
	int mp = Villain::getMp();
	return mp;
}

int Sorcerer::getDefense()
{
	int defense = Villain::getDefense();
	return defense;
}

int Sorcerer::getSpeed()
{
	int speed = Villain::getSpeed();
	return speed;
}

int Sorcerer::getSpellDefense()
{
	int spellDefense = Villain::getSpellDefense();
	return spellDefense;
}

void Sorcerer::looseHp(int lost)
{
	Villain::looseHp(lost);
}

bool Sorcerer::isAlive()
{
	bool alive = Villain::isAlive();
	return alive;
}

int Sorcerer::attack()
{
	int attackinPoints = Villain::attack();
	return attackinPoints;
}

bool Sorcerer::isASpell()
{
	bool spell = Villain::isASpell();
	return spell;
}

void Sorcerer::defend(bool isMagical, int howStrong, Hero hero)
{
	Villain::defend(isMagical, howStrong, hero);
}

