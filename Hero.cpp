#include "Hero.h"

Hero::Hero() :Character(true){}

Hero::Hero(std::string fileName, int t) : Character(fileName, t, true) {}

Hero::~Hero()
{
	Character::~Character();
}
void Hero::change(int i)
{
	Character::change(i, true);
}
bool Hero::getAttitude()
{
	int good = Character::getAttitude();
	return good;
}

int Hero::getType()
{
	int t = Character::getType();
	return t;
}

int Hero::getHp()
{
	int hp = Character::getHp();
	return hp;
}

int Hero::getStrength()
{
	int strength = Character::getStrength();
	return strength;
}

int Hero::getMp()
{
	int mp = Character::getMp();
	return mp;
}

int Hero::getDefense()
{
	int defense = Character::getDefense();
	return defense;
}

int Hero::getSpeed()
{
	int speed = Character::getSpeed();
	return speed;
}

int Hero::getSpellDefense()
{
	int spellDefense = Character::getSpellDefense();
	return spellDefense;
}

void Hero::changeType(int t)
{
	Character::changeType(t);
}


void Hero::looseHp(int lost)
{
	Character::looseHp(lost);
}

bool Hero::isAlive()
{
	bool alive = Character::isAlive();
	return alive;
}

int Hero::attack()
{
	int attackPower = Character::attack();
	return attackPower;
}

bool Hero::isASpell()
{
	bool spell = Character::isASpell();
	return spell;
}

void Hero::defend(bool isMagical, int howStrong, Villain villain)
{
	Character::defend(isMagical, howStrong, villain);
}
