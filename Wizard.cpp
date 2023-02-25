#include "Wizard.h"

Wizard::Wizard() :Hero("Sources/Villains/wizard.txt", 0) {}

Wizard::Wizard(std::string fileName) : Hero(fileName, 0) {}

Wizard::~Wizard()
{
	Hero::~Hero();
}

bool Wizard::getAttitude()
{
	bool good = Hero::getAttitude();
	return good;
}

int Wizard::getType()
{
	int type = Hero::getType();
	return type;
}

int Wizard::getHp()
{
	int hp = Hero::getHp();
	return hp;
}

int Wizard::getStrength()
{
	int strength = Hero::getStrength();
	return strength;
}

int Wizard::getMp()
{
	int mp = Hero::getMp();
	return mp;
}

int Wizard::getDefense()
{
	int defense = Hero::getDefense();
	return defense;
}

int Wizard::getSpeed()
{
	int speed = Hero::getSpeed();
	return speed;
}

int Wizard::getSpellDefense()
{
	int spellDefense = Hero::getSpellDefense();
	return spellDefense;
}

void Wizard::looseHp(int lost)
{
	Hero::looseHp(lost);
}

bool Wizard::isAlive()
{
	bool alive = Hero::isAlive();
	return alive;
}

int Wizard::attack()
{
	int attackinPoints = Hero::attack();
	return attackinPoints;
}

bool Wizard::isASpell()
{
	bool spell = Hero::isASpell();
	return spell;
}

void Wizard::defend(bool isMagical, int howStrong, Villain villain)
{
	Hero::defend(isMagical, howStrong, villain);
}

