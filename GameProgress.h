#pragma once
#include <iostream>
#include <string>

#include "class.h"
#include "Villain.h"
#include "Hero.h"
#include "Character.h"
class GameProgress
{
private:
	bool myTurn, gameOver, win;
	int points, heroHp, villainHp;
	std::string pointString, heroHpString, villainHpString;

public:
	/**@param constructor of class GameProgress without variables*/
	GameProgress();

	/**@param constructor of class GameProgress with Hero and villain variables*/
	GameProgress(Villain villain, Hero hero);

	/*methods*/
	/**@param public method of class GameProgress - gets points as a string
	@return pointString*/
	std::string getPointsString();

	/**@param public method of class GameProgress - changes score*/
	void addToScore(int p);

	/**@param public method of class GameProgress - reduces score*/
	void reduceScore(int r);

	/**@param public method of class GameProgress - changes string attributes*/
	void changeStrings();

	/**@param public method of class GameProgress - changes player turn*/
	void changeTurn();

	/**@param public method of class GameProgress - generates attack*/
	void generateAttack(Villain& villain, Hero& hero);

	/**@param public method of class GameProgress - generates defend mode*/
	void generateDefence(Villain& villain, Hero& hero);

	/**@param public method of class GameProgress - generates HP loss after freezing*/
	void generateLoss(Villain& villain, Hero& hero);

	/**@param public method of class GameProgress - checks whether game is over
	@return gameOver*/
	bool isGameOver();

	/**@param public method of class GameProgress - checks whether is it a win or lost
	@return win*/
	bool victory();

	/**@param public method of class GameProgress - gets hero's hp as a string*/
	std::string getHeroHpString();

	/**@param public method of class GameProgress - gets villain's hp as a string*/
	std::string getVillainHpString();

	/**@param public method of class GameProgress - get who's turn it is
	@return myTurn*/
	bool getTurn();

	/**@param public method of class GameProgress - gets score
	@return score*/
	int getScore();


};

