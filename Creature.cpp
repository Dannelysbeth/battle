#include "Creature.h"
#include "GameView.h"

void Creature::initAttitude(bool isGood)
{
	good = isGood;
}

void Creature::initType(int t)
{
	type = t;
}

void Creature::initTexture()
{
	
	if (good == false) {
		switch (type)
		{
		case 0:
			try
			{
				if (!texture.loadFromFile("Texture/dragon.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		case 1:
			try
			{
				if (!texture.loadFromFile("Texture/orc.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		case 2:
			try
			{
				if (!texture.loadFromFile("Texture/sorcerer.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		case 3:
			try
			{
				if (!texture.loadFromFile("Texture/assassin.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		case 4:
			try
			{
				if (!texture.loadFromFile("Texture/darkElf.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		default:
			break;
		}
	}
	else {
		switch (type)
		{
		case 0:
			try
			{
				if (!texture.loadFromFile("Texture/wizard2.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		case 1:
			try
			{
				if (!texture.loadFromFile("Texture/elf2.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		case 2:
			try
			{
				if (!texture.loadFromFile("Texture/thief.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		case 3:
			try
			{
				if (!texture.loadFromFile("Texture/paladin.png")) {
					throw 1;
				}
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		case 4:
			try
			{
				if (!texture.loadFromFile("Texture/warrior.png")) {
					throw 1;
				}
				
			}
			catch (int) {
				system("PAUSE");
				exit(0);
			}
			break;
		default:
			break;
		}
		this->sprite.setTexture(texture);
	}
	
}

void Creature::initSprite()
{		 				
	sprite.setTexture(this->texture);
}

void Creature::setName()
{
	if (good == false) {
		switch (type) {
		case 0:
			name = "Dragon";
			break;
		case 1:
			name = "Orc";
			break;
		case 2:
			name = "Sorcerer";
			break;
		case 3:
			name = "Assassin";
			break;
		case 4:
			name = "Dark Elf";
			break;
		default:
			break;
		}
	}
	else {
		switch (type) {
		case 0:
			name = "Wizard";
			break;
		case 1:
			name = "Elf";
			break;
		case 2:
			name = "Thief";
			break;
		case 3:
			name = "Paladin";
			break;
		case 4:
			name = "Warrior";
			break;
		default:
			break;
		}
	}
	
}
Creature::Creature()
{
	initAttitude(false);
	initType(0);
	initTexture();
	initSprite();
	setName();
}

Creature::Creature(bool isGood)
{
	good = isGood;
	type = 0;
	initTexture();
	initSprite();
	setName();
}

Creature::Creature(bool isGood, int subtype)
{
	good = isGood;
	type = subtype;
	initTexture();
	initSprite();
	setName();
}

Creature::~Creature(){}


sf::Texture& Creature::getTexture()
{
	return texture;
}

sf::Sprite& Creature::getSprite()
{
	return sprite;
}

int Creature::getType()
{
	return type;
}

bool Creature::getIfGood()
{
	return good;
}

const std::string& Creature::getName() const
{
	return name;
}

void Creature::changeAttitude(bool isGood)
{
	good = isGood;
	initTexture();
	initSprite();
	initType(type);
	setName();
}

void Creature::changeType(int num)
{
	type = num;
	initTexture();
	initSprite();
	setName();
}

void Creature::swapSprite(sf::Sprite s)
{
	sprite = s;
}

