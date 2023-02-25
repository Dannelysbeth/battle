#include "Character.h"

void Character::initFeatures()
{
	name = "no character";
	type = 0;
	good = false;
	hp = 0;
	strength = 0;
	mp = 0;
	defense = 0;
	speed = 0;
	spellDefense = 0;
}

void Character::initFeatures(std::string fileName)
{
	initFeatures();
	std::string dataType, f1, f2, f3, f4, f5, f6;
	std::ifstream stream(fileName);
	getline(stream, dataType);
	while (!stream.eof()){
		stream >> dataType;
		if (dataType == "hp:"){
			stream >> f1;
			hp = stoi(f1);
		}
		else if (dataType == "strength:"){
			stream >> f2;
			strength = stoi(f2);
		}
		else if (dataType == "mp:"){
			stream >> f3;
			mp = stoi(f3);
		}
		else if (dataType == "defense:"){
			stream >> f4;
			defense = stoi(f4);
		}
		else if (dataType == "speed:"){
			stream >> f5;
			speed = stoi(f5);
		}
		else if (dataType == "spellDefense:"){
			stream >> f6;
			spellDefense = stoi(f6);
		}
	}
	stream.close();
}

void Character::initType(int t)
{
	type = t;
}

void Character::initAttitude(bool isGood)
{
	good = isGood;
}
void Character::changeHp(int newHp)
{
	if (newHp < 0)
		hp = 0;
	else
		hp = newHp;
}

Character::Character()
{
	initFeatures();
}

Character::Character(bool isGood)
{
	initAttitude(isGood);
	initFeatures();
	//setCreature(isGood, type);
}

Character::Character(std::string fileName, int t, bool isGood)
{
	initAttitude(isGood);
	initType(t);
	initFeatures(fileName);
	//setCreature(isGood, t);
}

Character::~Character(){}

void Character::change(int i, bool isGood)
{
	initAttitude(isGood);
	initType(i);
	if (isGood == true) {
		switch (i) {
		case 0:
			initFeatures("Sources/Heroes/wizard.txt");
			break;
		case 1:
			initFeatures("Sources/Heroes/elf.txt");
			break;
		case 2:
			initFeatures("Sources/Heroes/thief.txt");
			break;
		case 3:
			initFeatures("Sources/Heroes/paladin.txt");
			break;
		case 4:
			initFeatures("Sources/Heroes/warrior.txt");
			break;
		default:
			break;
		}
	}
	else {
		switch (i) {
		case 0:
			initFeatures("Sources/Villains/dragon.txt");
			break;
		case 1:
			initFeatures("Sources/Villains/orc.txt");
			break;
		case 2:
			initFeatures("Sources/Villains/sorcerer.txt");
			break;
		case 3:
			initFeatures("Sources/Villains/assassin.txt");
			break;
		case 4:
			initFeatures("Sources/Villains/darkElf.txt");
			break;
		default:
			break;
		}
	}
}

std::string Character::getName()
{
	return name;
}

bool Character::getAttitude()
{
	return good;
}

int Character::getType()
{
	return type;
}

int Character::getHp()
{
	return hp;
}

int Character::getStrength()
{
	return strength;
}

int Character::getMp()
{
	return mp;
}

int Character::getDefense()
{
	return defense;
}

int Character::getSpeed()
{
	return speed;
}

int Character::getSpellDefense()
{
	return spellDefense;
}

void Character::changeAttitude(bool isGood)
{
	good = isGood;
}

void Character::changeType(int t)
{
	type = t;
}

void Character::looseHp(int lost)
{
	hp = hp - lost;
	if (hp < 0)
	changeHp(hp);
}

bool Character::isAlive()
{
	if (hp > 0)
		return true;
	else
		return false;
}

int Character::attack()
{
	std::srand(std::time(0));
	int fullStrength = mp + strength;
	int chanceOfMagicalAttack, attack;
	if (fullStrength > 0)
		chanceOfMagicalAttack = std::rand() % fullStrength;		//generates if the attack should be a spell a normal attack (the more magic points a character has, the more likely it is that the attack will be a spell and vice versa)
	else
	{
		return 0;
	}
	if (chanceOfMagicalAttack < mp) {
		magicAttack = true;
		return mp;
	}
	else {
		magicAttack = false;
		return strength;
	}	
}

bool Character::isASpell()
{
	return magicAttack;
}

void Character::defend(bool isMagical, int howStrong, Character character)
{
	std::srand(std::time(0));
	int avoidAttack;
	double avoidAttackProbability;
	avoidAttack = rand() % 200;
	if (isMagical == true) {
		avoidAttackProbability = 1.4 * speed;
		if (avoidAttackProbability <= avoidAttack) {
			if (howStrong <= spellDefense / 4)									//checks wether spell defense is strong enough to lower the impact of the attack
				howStrong = 0;
			else {
				howStrong = howStrong - (1 - 0.25) * spellDefense;				//if the spell defense is strong enough, it reduces the impact of the attack
				if (howStrong < 0)
					howStrong = 0;												//the impact cannot be below zero (the enemy cannot gain hp from the attack)
			}
			hp = hp - howStrong;
		}
	}
	else {
		avoidAttackProbability = speed + (100-character.getSpeed());										
		if (avoidAttackProbability <= avoidAttack) {
			if (howStrong <= defense / 4)
				howStrong = 0;
			else {
				howStrong = howStrong - (1 - 0.25) * spellDefense;				//if the spell defense is strong enough, it reduces the impact of the attack
				if (howStrong < 0)
					howStrong = 0;												//the impact cannot be below zero (the enemy cannot gain hp from the attack)
			}
			hp = hp - howStrong;
		}
	}
	if (hp < 0)
		hp = 0;
}
