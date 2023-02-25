#include "Villain.h"
#include "Character.h"

Villain::Villain() :Character(false){}

Villain::Villain(std::string fileName, int t)  :Character(fileName, t, false){}

Villain::~Villain()
{
	Character::~Character();
}

void Villain::change(int i)
{
	Character::change(i, false);
}

bool Villain::getAttitude()
{
	int good = Character::getAttitude();
	return good;
}

int Villain::getType()
{
	int t = Character::getType();
	return t;
}

int Villain::getHp()
{
	int hp = Character::getHp();
	return hp;
}

int Villain::getStrength()
{
	int strength = Character::getStrength();
	return strength;
}

int Villain::getMp()
{
	int mp = Character::getMp();
	return mp;
}

int Villain::getDefense()
{
	int defense = Character::getDefense();
	return defense;
}

int Villain::getSpeed()
{
	int speed = Character::getSpeed();
	return speed;
}

int Villain::getSpellDefense()
{
	int spellDefense = Character::getSpellDefense();
	return spellDefense;
}

void Villain::changeType(int t)
{
	Character::changeType(t);
}


void Villain::looseHp(int lost)
{
	Character::looseHp(lost);
}

bool Villain::isAlive()
{
	bool alive = Character::isAlive();
	return alive;
}

int Villain::attack()
{
	int attackPower = Character::attack();
	return attackPower;
}

bool Villain::isASpell()
{
	bool spell = Character::isASpell();
	return spell;
}

void Villain::defend(bool isMagical, int howStrong, Hero hero)
{
	Character::defend(isMagical, howStrong, hero);
}
