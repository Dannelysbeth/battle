#include "Orc.h"

Orc::Orc() :Villain("Sources/Villains/orc.txt", 1) {}

Orc::Orc(std::string fileName) : Villain(fileName, 0) {}

Orc::~Orc()
{
	Villain::~Villain();
}

bool Orc::getAttitude()
{
	bool good = Villain::getAttitude();
	return good;
}

int Orc::getType()
{
	int type = Villain::getType();
	return type;
}

int Orc::getHp()
{
	int hp = Villain::getHp();
	return hp;
}

int Orc::getStrength()
{
	int strength = Villain::getStrength();
	return strength;
}

int Orc::getMp()
{
	int mp = Villain::getMp();
	return mp;
}

int Orc::getDefense()
{
	int defense = Villain::getDefense();
	return defense;
}

int Orc::getSpeed()
{
	int speed = Villain::getSpeed();
	return speed;
}

int Orc::getSpellDefense()
{
	int spellDefense = Villain::getSpellDefense();
	return spellDefense;
}

void Orc::looseHp(int lost)
{
	Villain::looseHp(lost);
}

bool Orc::isAlive()
{
	bool alive = Villain::isAlive();
	return alive;
}

int Orc::attack()
{
	int attackinPoints = Villain::attack();
	return attackinPoints;
}

bool Orc::isASpell()
{
	bool spell = Villain::isASpell();
	return spell;
}

void Orc::defend(bool isMagical, int howStrong, Hero hero)
{
	Villain::defend(isMagical, howStrong, hero);
}

