#include "GameProgress.h"
//#include "Hero.h"

GameProgress::GameProgress()
{
	gameOver = false;
	myTurn = true;
	points = 0;
	heroHp = 0;
	villainHp = 0;
	std::string val = std::to_string(heroHp);
	heroHpString = "hp: " + val;
	val = std::to_string(villainHp);
	villainHpString = "hp: " + val;
	val = std::to_string(points);
	pointString = "points: " + val;

}

GameProgress::GameProgress(Villain villain, Hero hero)
{
	gameOver = false;
	myTurn = true;
	points = 0;
	heroHp = hero.getHp();
	villainHp = villain.getHp();
	std::string val = std::to_string(heroHp);
	heroHpString = "hp: " + val;
	val = std::to_string(villainHp);
	villainHpString = "hp: " + val;
	val = std::to_string(points);
	pointString = "score: " + val;
}

std::string GameProgress::getPointsString()
{
	return pointString;
}

void GameProgress::addToScore(int p)
{
	points = points + p;
	changeStrings();
}

void GameProgress::reduceScore(int r)
{
	points = points - r;
	if (points < 0)
		points = 0;
	changeStrings();
}

void GameProgress::changeStrings()
{
	std::string s;
	s = std::to_string(heroHp);
	heroHpString = "hp: " + s;
	s = std::to_string(villainHp);
	villainHpString = "hp: " + s;
	s = std::to_string(points);
	pointString = "score: " + s;
}

void GameProgress::changeTurn()
{
	if (myTurn)
		myTurn = false;
	else
		myTurn = true;
}

void GameProgress::generateAttack(Villain& villain, Hero& hero)
{
	if (myTurn and hero.isAlive()==true) {
		int attackPoints = hero.attack();
		bool magic = hero.isASpell();
		villain.defend(magic, attackPoints, hero);
		int newHp = villain.getHp();
		int hpLost = villainHp - newHp;
		double hpPartTaken = hpLost;
		addToScore(10 * hpPartTaken);											//adds points to score									
		villainHp = newHp;
		if (villain.isAlive() == false) {										//checks whether villain is still alive after attack
			gameOver = true;
			win = true;
		}
	}
	else {
		int attackPoints = villain.attack();
		hero.looseHp(attackPoints);
		reduceScore(attackPoints * 25);
		int newHp = hero.getHp();
		int hpLost = heroHp - newHp;
		if (points < 0)
			points = 0;
		heroHp = hero.getHp();
		if (hero.isAlive()==false) {												//checks whethet hero is hero
			//double hpPartTaken = hpLost;
			//points = points - 15 * hpPartTaken;								//takes away points
			/*if (points < 0)
				points = 0;			*/										//makes sure points are no less than zero
			gameOver = true;
			points = 0;
			win = false;
		}
	}
	
	villainHp = villain.getHp();
	changeStrings();
	changeTurn();
}

void GameProgress::generateDefence(Villain& villain, Hero& hero)
{
	if (myTurn == false) {
		int attackPoints = villain.attack();
		bool magic = villain.isASpell();
		hero.defend(magic, attackPoints, villain);
		int newHp = hero.getHp();
		int hpLost = heroHp - newHp;
		reduceScore(8 * hpLost);											//takes away points
		if (points < 0)
				points = 0;													//makes sure points are no less than zero
		heroHp = hero.getHp();
		if (hero.isAlive()==false) {												//checks whethet hero is alive
			gameOver = true;
			points = 0;
			win = false;						
															
		}
	}
	villainHp = villain.getHp();
	changeStrings();
	changeTurn();
}

void GameProgress::generateLoss(Villain& villain, Hero& hero)
{
	int attackPoints = villain.attack();
	hero.looseHp(attackPoints);
	reduceScore(25 * attackPoints);										//takes away points
	int newHp = hero.getHp();
	int hpLost = heroHp - newHp;
	if (points < 0)
		points = 0;														//makes sure points are no less than zero
	heroHp = hero.getHp();
	if (hero.isAlive() == false) {												//checks whethet hero is alive
		gameOver = true;
		points = 0;
		win = false;
	}
	//heroHp = hero.getHp();
	villainHp = villain.getHp();
	changeStrings();
	//changeTurn();
}

bool GameProgress::isGameOver()
{
	return gameOver;
}

bool GameProgress::victory()
{
	return win;
}

std::string GameProgress::getHeroHpString()
{
	return heroHpString;
}

std::string GameProgress::getVillainHpString()
{
	return villainHpString;
}

bool GameProgress::getTurn()
{
	return myTurn;
}

int GameProgress::getScore()
{
	return points;
}
