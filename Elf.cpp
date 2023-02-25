#include "Elf.h"

Elf::Elf() :Hero("Sources/Villains/elf.txt", 1) {}

Elf::Elf(std::string fileName) : Hero(fileName, 1) {}

Elf::~Elf()
{
	Hero::~Hero();
}

bool Elf::getAttitude()
{
	bool good = Hero::getAttitude();
	return good;
}

int Elf::getType()
{
	int type = Hero::getType();
	return type;
}

int Elf::getHp()
{
	int hp = Hero::getHp();
	return hp;
}

int Elf::getStrength()
{
	int strength = Hero::getStrength();
	return strength;
}

int Elf::getMp()
{
	int mp = Hero::getMp();
	return mp;
}

int Elf::getDefense()
{
	int defense = Hero::getDefense();
	return defense;
}

int Elf::getSpeed()
{
	int speed = Hero::getSpeed();
	return speed;
}

int Elf::getSpellDefense()
{
	int spellDefense = Hero::getSpellDefense();
	return spellDefense;
}

void Elf::looseHp(int lost)
{
	Hero::looseHp(lost);
}

bool Elf::isAlive()
{
	bool alive = Hero::isAlive();
	return alive;
}

int Elf::attack()
{
	int attackinPoints = Hero::attack();
	return attackinPoints;
}

bool Elf::isASpell()
{
	bool spell = Hero::isASpell();
	return spell;
}

void Elf::defend(bool isMagical, int howStrong, Villain villain)
{
	Hero::defend(isMagical, howStrong, villain);
}
