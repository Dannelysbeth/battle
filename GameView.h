#pragma once
/** @file*/
#include<iostream>
#include<vector>
#include <utility>
#include <memory>
#include<ctime>
#include<string>
#include<sstream>
#include <fstream>
#include <stdexcept>
#include <algorithm>


#include <SFML/Graphics.hpp>
#include <SFML/Cursor.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "class.h"
#include "Button.h"
#include "Creature.h"

#include "Villain.h"
#include "Hero.h"
#include "Dragon.h"
#include "Orc.h"
#include "Sorcerer.h"
#include "Assassin.h"
#include "DarkElf.h"
#include "Wizard.h"
#include "Elf.h"
#include "Thief.h"
#include "Paladin.h"
#include "Warrior.h"

#include "GameProgress.h"
#include "function.h"

const int SIZE = 20;

// Inteface class
class GameView {
private:
	//variables
	bool menu, settings, chooseEnemy, chooseChampion, playGame, gameOver, musicPlaying, endGame, ranking;
	bool is_enabled;
	bool triedToBlock;

	//sf::RenderWindow* window;
	std::unique_ptr<sf::RenderWindow> window;
	sf::VideoMode videoMode;
	sf::Event event;


	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Mouse cursor
	sf::Cursor cursor;

	//resources

		/*textures*/
	sf::Texture menuTexture;
	sf::Texture titleTexture;
	sf::Texture enemyChoiceTexture;
	sf::Texture featureTexture;
	sf::Texture heroChoiceTexture;
	sf::Texture playGameTexture;
	sf::Texture musicOnTexture;
	sf::Texture musicOffTexture;
	sf::Texture championTexture;
	sf::Texture victoryTexture;
	sf::Texture defeatTexture;
	sf::Texture rankingTexture;
		/*sprites*/
	sf::Sprite menuSprite;
	sf::Sprite titleSprite;
	sf::Sprite enemyChoiceSprite;
	sf::Sprite featureSprite;
	sf::Sprite heroChoiceSprite;
	sf::Sprite gamePlaySprite;
	sf::Sprite musicSprite;
	sf::Sprite championSprite;
	sf::Sprite endGameSprite;
	sf::Sprite rankingSprite;

		/*fonts*/
	sf::Font font;
		/*sounds*/
	sf::Music music;
	sf::SoundBuffer soundBuffer;
	sf::Sound clickMusic;
	sf::Sound death;
	sf::Sound attack;
	sf::Sound shield;

	//texts
	sf::Text timeText;
	sf::Text text;
	sf::Text championName;
	sf::Text scoreText;
	sf::Text rankingBackText;
	std::vector<sf::Text> menuTexts;
	std::vector<sf::Text> chooseEnemyTexts;
	std::vector<sf::Text> chooseHeroTexts;
	std::vector<sf::Text> gamePlayTexts;
	std::vector<sf::Text> rankingTexts;

	/*ranking*/
	std::vector<int> scores;

	//GameObjects
		/*Buttons*/
	sf::RectangleShape b;
	Button button;
	std::vector<Button> menuButtons;
	std::vector<Button> chooseEnemyButtons;
	std::vector<Button> chooseChampionButtons;
	std::vector<Button> gamePlayButtons;
	Button backToMenuButton;

		/*Enemies*/
	//std::shared_ptr<Enemy> enemy;
	Creature enemy;
	//enemy(isGood);
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	sf::Text enemyName;
	//Enemy enemy(sf::Vector2f(400, 100), 2);
		/*Characters*/
	Creature champion;


	/*villains and heroes*/
	Villain villain;
	Hero hero;
	GameProgress game;

	/*timers*/
	sf::Time timer;
	sf::Clock gameClock;


	//private functions
	/**@param private method of class GameView - initializes variables*/
	void initVariables();

	/**@param private method of class GameView - initializes window*/
	void initWindow();

	/**@param private method of class GameView - initializes enemy*/
	void initEnemy();

	/**@param private method of class GameView - initializes champion*/
	void initChampion();

	/**@param private method of class GameView - initializes textures*/
	void initTexture();

	/**@param private method of class GameView - initializes buttons*/
	void initButtons();

	/**@param private method of class GameView - initializes fonts*/
	void initFonts();

	/**@param private method of class GameView - initializes music tracks and sounds*/
	void initMusic();

	/**@param private method of class GameView - initializes texts*/
	void initText();

	/**@param private method of class GameView - gets previous best scores data from file*/
	void getDataFromFile();

	/**@param private method of class GameView - sorts score vector*/
	void sortVector(std::vector<int>& vec);

public:
	/**@param constructor of class GameView with variable as fileName*/
	GameView(std::string fileName);

	/**@param destructor of class GameView*/
	virtual ~GameView();


	/**@param operant of class GameView */
	const bool running() const;


	//public methods
	/**@param public method of class GameView - checks if file is empty
	@return pFile*/
	bool is_empty(std::ifstream& pFile);

	/**@param public method of class GameView - gets menu text strings
	@return menuStrings*/
	std::vector<std::string> initMenuStrings();

	/**@param public method of class GameView - gets enemy Choice text strings
	@return enemyChoiceStrings*/
	std::vector<std::string> initEnemyChoiceStrings();

	/**@param public method of class GameView - gets hero Choice text strings
	@return heroChoiceStrings*/
	std::vector<std::string>initHeroChoiceStrings();

	/**@param public method of class GameView - gets game play Choice text strings
	@return gamePlayStrings*/
	std::vector<std::string>initGamePlayStrings();

	/**@param public method of class GameView - gets captions
	@return text*/
	sf::Text setCaptions(int amount, std::string caption);

	/**@param public method of class GameView - polls events*/
	void pollEvents();

	/**@param public method of class GameView - generates battle*/
	void battle();

	/**@param public method of class GameView - updates mouse position*/
	void updateMousePositions();

	/**@param public method of class GameView - updates buttons */
	void updateButtons();

	/**@param public method of class GameView - updates game */
	void update();

	/**@param public method of class GameView - updates time */
	void updateTime();

	/**@param public method of class GameView - generates enemy */
	void generateEnemy();

	/**@param public method of class GameView - creates champion */
	void changeChampion(bool forward);

	/**@param public method of class GameView - renders menu Buttons */
	void renderButtonsMenu(sf::RenderTarget& target);

	/**@param public method of class GameView - renders enemy choice Buttons */
	void renderButtonsEnemyChoice(sf::RenderTarget& target);

	/**@param public method of class GameView - renders hero choice Buttons */
	void renderButtonsHeroChoice(sf::RenderTarget& target);

	/**@param public method of class GameView - renders play game  Buttons */
	void renderButtonsGamePlay(sf::RenderTarget& target);

	/**@param public method of class GameView - renders menu texts */
	void renderTextMenu(sf::RenderTarget& target);

	/**@param public method of class GameView - renders enemy choice texts */
	void renderTextEnemyChoice(sf::RenderTarget& target);

	/**@param public method of class GameView - renders hero choice texts */
	void renderTextHeroChoice(sf::RenderTarget& target);

	/**@param public method of class GameView - renders game play texts */
	void renderTextGamePlay(sf::RenderTarget& target);

	/**@param public method of class GameView - renders ranking texts */
	void renderTextRanking(sf::RenderTarget& target);

	/**@param public method of class GameView - renders features */
	void renderFeature(sf::RenderTarget& target, bool enemy);

	/**@param public method of class GameView - renders enemy */
	void renderEnemy(sf::RenderTarget& target);

	/**@param public method of class GameView - renders champion */
	void renderChampion(sf::RenderTarget& target);

	/**@param public method of class GameView - renders hp */
	void renderHp(sf::RenderTarget& target);

	/**@param public method of class GameView - renders time */
	void renderTime(sf::RenderTarget& target);

	/**@param public method of class GameView - renders menu mode */
	void renderMenu();

	/**@param public method of class GameView - renders enemy choice mode */
	void renderEnemyChoice();

	/**@param public method of class GameView - renders hero choice mode */
	void renderHeroChoice();

	/**@param public method of class GameView - renders play game mode */
	void renderGamePlay();

	/**@param public method of class GameView - renders end game mode */
	void renderEndGame();

	/**@param public method of class GameView - renders ranking mode */
	void renderRanking();

	/**@param public method of class GameView - renders game */
	void render(std::string fileName);

	/**@param public method of class GameView - gets the score vector
	@return scoreVector */
	std::vector<int> getScores();

	/**@param public method of class GameView - adds score to vector */
	void saveScore(int s);

	/**@param public method of class GameView - saves score to vector */
	void saveDataToFile();

};
