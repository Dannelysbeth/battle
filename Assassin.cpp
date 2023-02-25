#include "Assassin.h"

Assassin::Assassin() :Villain("Sources/Villains/assassin.txt", 3) {}

Assassin::Assassin(std::string fileName) : Villain(fileName, 3) {}

Assassin::~Assassin()
{
	Villain::~Villain();
}

bool Assassin::getAttitude()
{
	bool good = Villain::getAttitude();
	return good;
}

int Assassin::getType()
{
	int type = Villain::getType();
	return type;
}

int Assassin::getHp()
{
	int hp = Villain::getHp();
	return hp;
}

int Assassin::getStrength()
{
	int strength = Villain::getStrength();
	return strength;
}

int Assassin::getMp()
{
	int mp = Villain::getMp();
	return mp;
}

int Assassin::getDefense()
{
	int defense = Villain::getDefense();
	return defense;
}

int Assassin::getSpeed()
{
	int speed = Villain::getSpeed();
	return speed;
}

int Assassin::getSpellDefense()
{
	int spellDefense = Villain::getSpellDefense();
	return spellDefense;
}

void Assassin::looseHp(int lost)
{
	Villain::looseHp(lost);
}

bool Assassin::isAlive()
{
	bool alive = Villain::isAlive();
	return alive;
}

int Assassin::attack()
{
	int attackinPoints = Villain::attack();
	return attackinPoints;
}

bool Assassin::isASpell()
{
	bool spell = Villain::isASpell();
	return spell;
}

void Assassin::defend(bool isMagical, int howStrong, Hero hero)
{
	Villain::defend(isMagical, howStrong, hero);
}

