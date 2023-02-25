#include "Paladin.h"

Paladin::Paladin() :Hero("Sources/Villains/paladin.txt", 3) {}

Paladin::Paladin(std::string fileName) : Hero(fileName, 3) {}

Paladin::~Paladin()
{
	Hero::~Hero();
}

bool Paladin::getAttitude()
{
	bool good = Hero::getAttitude();
	return good;
}

int Paladin::getType()
{
	int type = Hero::getType();
	return type;
}

int Paladin::getHp()
{
	int hp = Hero::getHp();
	return hp;
}

int Paladin::getStrength()
{
	int strength = Hero::getStrength();
	return strength;
}

int Paladin::getMp()
{
	int mp = Hero::getMp();
	return mp;
}

int Paladin::getDefense()
{
	int defense = Hero::getDefense();
	return defense;
}

int Paladin::getSpeed()
{
	int speed = Hero::getSpeed();
	return speed;
}

int Paladin::getSpellDefense()
{
	int spellDefense = Hero::getSpellDefense();
	return spellDefense;
}

void Paladin::looseHp(int lost)
{
	Hero::looseHp(lost);
}

bool Paladin::isAlive()
{
	bool alive = Hero::isAlive();
	return alive;
}

int Paladin::attack()
{
	int attackinPoints = Hero::attack();
	return attackinPoints;
}

bool Paladin::isASpell()
{
	bool spell = Hero::isASpell();
	return spell;
}

void Paladin::defend(bool isMagical, int howStrong, Villain villain)
{
	Hero::defend(isMagical, howStrong, villain);
}
