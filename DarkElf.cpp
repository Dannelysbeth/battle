#include "DarkElf.h"

DarkElf::DarkElf() :Villain("Sources/Villains/darkElf.txt", 4) {}

DarkElf::DarkElf(std::string fileName) : Villain(fileName, 4) {}

DarkElf::~DarkElf()
{
	Villain::~Villain();
}

bool DarkElf::getAttitude()
{
	bool good = Villain::getAttitude();
	return good;
}

int DarkElf::getType()
{
	int type = Villain::getType();
	return type;
}

int DarkElf::getHp()
{
	int hp = Villain::getHp();
	return hp;
}

int DarkElf::getStrength()
{
	int strength = Villain::getStrength();
	return strength;
}

int DarkElf::getMp()
{
	int mp = Villain::getMp();
	return mp;
}

int DarkElf::getDefense()
{
	int defense = Villain::getDefense();
	return defense;
}

int DarkElf::getSpeed()
{
	int speed = Villain::getSpeed();
	return speed;
}

int DarkElf::getSpellDefense()
{
	int spellDefense = Villain::getSpellDefense();
	return spellDefense;
}

void DarkElf::looseHp(int lost)
{
	Villain::looseHp(lost);
}

bool DarkElf::isAlive()
{
	bool alive = Villain::isAlive();
	return alive;
}

int DarkElf::attack()
{
	int attackinPoints = Villain::attack();
	return attackinPoints;
}

bool DarkElf::isASpell()
{
	bool spell = Villain::isASpell();
	return spell;
}

void DarkElf::defend(bool isMagical, int howStrong, Hero hero)
{
	Villain::defend(isMagical, howStrong, hero);
}

