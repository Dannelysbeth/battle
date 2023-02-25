#include "Warrior.h"

Warrior::Warrior() :Hero("Sources/Villains/warrior.txt", 4) {}

Warrior::Warrior(std::string fileName) : Hero(fileName, 4) {}

Warrior::~Warrior()
{
	Hero::~Hero();
}

bool Warrior::getAttitude()
{
	bool good = Hero::getAttitude();
	return good;
}

int Warrior::getType()
{
	int type = Hero::getType();
	return type;
}

int Warrior::getHp()
{
	int hp = Hero::getHp();
	return hp;
}

int Warrior::getStrength()
{
	int strength = Hero::getStrength();
	return strength;
}

int Warrior::getMp()
{
	int mp = Hero::getMp();
	return mp;
}

int Warrior::getDefense()
{
	int defense = Hero::getDefense();
	return defense;
}

int Warrior::getSpeed()
{
	int speed = Hero::getSpeed();
	return speed;
}

int Warrior::getSpellDefense()
{
	int spellDefense = Hero::getSpellDefense();
	return spellDefense;
}

void Warrior::looseHp(int lost)
{
	Hero::looseHp(lost);
}

bool Warrior::isAlive()
{
	bool alive = Hero::isAlive();
	return alive;
}

int Warrior::attack()
{
	int attackinPoints = Hero::attack();
	return attackinPoints;
}

bool Warrior::isASpell()
{
	bool spell = Hero::isASpell();
	return spell;
}

void Warrior::defend(bool isMagical, int howStrong, Villain villain)
{
	Hero::defend(isMagical, howStrong, villain);
}