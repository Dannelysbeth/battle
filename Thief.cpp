#include "Thief.h"

Thief::Thief() :Hero("Sources/Villains/thief.txt", 2) {}

Thief::Thief(std::string fileName) : Hero(fileName, 2) {}

Thief::~Thief()
{
	Hero::~Hero();
}

bool Thief::getAttitude()
{
	bool good = Hero::getAttitude();
	return good;
}

int Thief::getType()
{
	int type = Hero::getType();
	return type;
}

int Thief::getHp()
{
	int hp = Hero::getHp();
	return hp;
}

int Thief::getStrength()
{
	int strength = Hero::getStrength();
	return strength;
}

int Thief::getMp()
{
	int mp = Hero::getMp();
	return mp;
}

int Thief::getDefense()
{
	int defense = Hero::getDefense();
	return defense;
}

int Thief::getSpeed()
{
	int speed = Hero::getSpeed();
	return speed;
}

int Thief::getSpellDefense()
{
	int spellDefense = Hero::getSpellDefense();
	return spellDefense;
}

void Thief::looseHp(int lost)
{
	Hero::looseHp(lost);
}

bool Thief::isAlive()
{
	bool alive = Hero::isAlive();
	return alive;
}

int Thief::attack()
{
	int attackinPoints = Hero::attack();
	return attackinPoints;
}

bool Thief::isASpell()
{
	bool spell = Hero::isASpell();
	return spell;
}

void Thief::defend(bool isMagical, int howStrong, Villain villain)
{
	Hero::defend(isMagical, howStrong, villain);
}
