#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include <fstream> 
#include <stdexcept>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include "GameView.h"


//Private functions
//getting captions from file

void GameView::initVariables()
{
	this->window = nullptr;
	this->menu = true;
	this->settings = false;
	this->chooseEnemy = false;
	this->chooseChampion = false;
	this->playGame = false;
	this->gameOver = false;
	this->musicPlaying = false;
	this->endGame = false;
	this->triedToBlock = false;
	this->ranking = false;
}


void GameView::initWindow()
{
	//window initiazation
	this->videoMode.height = 600;
	this->videoMode.width = 1000;
	
	this->window.reset(new sf::RenderWindow(this->videoMode,  "Heroes&Villains", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize));
	
	this->window->setFramerateLimit(144);

}
void GameView::initEnemy()
{
	enemy.changeAttitude(false);
	std::srand(std::time(0));
	int genType = std::rand() % 5;
	enemy.changeType(genType);
	enemySprite = enemy.getSprite();
	enemySprite.setScale(0.5, 0.5);
	int type = enemy.getType();
	enemySprite.setPosition(300 + (700 - 628) / 2, 5);
	enemy.swapSprite(enemySprite);
	villain.change(enemy.getType());
	GameProgress g1(villain, hero);
	game = g1;
}

void GameView::initChampion()
{
	champion.changeAttitude(true);
	championSprite = champion.getSprite();
	championSprite.setScale(0.5, 0.5);
	championSprite.setPosition(220, 100);
	champion.swapSprite(championSprite);
	hero.change(champion.getType());
	GameProgress g1(villain, hero);
	game = g1;
}

void GameView::initTexture()
{
	//adding texture from file
	try
	{
		if (!this->menuTexture.loadFromFile("Texture/startGame.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->titleTexture.loadFromFile("Texture/titleTexture.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->enemyChoiceTexture.loadFromFile("Texture/enemyChoice1.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->featureTexture.loadFromFile("Texture/papyrus.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->heroChoiceTexture.loadFromFile("Texture/heroChoice.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->musicOnTexture.loadFromFile("Texture/musicOn.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->musicOffTexture.loadFromFile("Texture/musicOff.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->playGameTexture.loadFromFile("Texture/gamePlay.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->victoryTexture.loadFromFile("Texture/victory1.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->defeatTexture.loadFromFile("Texture/defeat1.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}
	try
	{
		if (!this->rankingTexture.loadFromFile("Texture/rankingTexture2.png", sf::IntRect(videoMode.width, videoMode.width, videoMode.height, videoMode.height))) {
			throw 1;
		}
	}
	catch (int) {
		system("PAUSE");
		exit(0);
	}

	this->menuSprite.setTexture(menuTexture);
	this->titleSprite.setTexture(titleTexture);
	this->enemyChoiceSprite.setTexture(enemyChoiceTexture);
	this->featureSprite.setTexture(featureTexture);
	this->heroChoiceSprite.setTexture(heroChoiceTexture);
	this->gamePlaySprite.setTexture(playGameTexture);
	this->musicSprite.setTexture(musicOnTexture);
	this->rankingSprite.setTexture(rankingTexture);
	
}

void GameView::initButtons()
{
	//button settings
	std::vector<std::string> menuStrings = initMenuStrings();
	std::vector<std::string> enemyChoiceStrings = initEnemyChoiceStrings();
	std::vector<std::string> heroChoiceStrings = initHeroChoiceStrings();
	std::vector<std::string> gamePlayStrings = initGamePlayStrings();
	
	for (int i = 0; i < menuStrings.size(); i++) {
		this->b.setSize(sf::Vector2f(200.f, 50.f));
		this->b.setPosition((videoMode.width - b.getSize().x) / 2, videoMode.height - 100 - (100 * i));
		//this->b.setScale(sf::Vector2f(0.5f, 0.5f));
		this->b.setFillColor(sf::Color(255, 255, 255, 50));
		this->b.setOutlineColor(sf::Color::Black);
		this->b.setOutlineThickness(1.5f);
		button.swapButton(b);
		this->menuButtons.push_back(button);
	}
	for (int i = 0; i < enemyChoiceStrings.size(); i++) {
		this->b.setSize(sf::Vector2f(400.f, 100.f));
		this->b.setPosition(100, (videoMode.height - 100 - (100 * i)));
		this->b.setScale(sf::Vector2f(0.5f, 0.5f));
		this->b.setFillColor(sf::Color(255, 255, 255, 50));
		this->b.setOutlineColor(sf::Color::Black);
		this->b.setOutlineThickness(3.f);
		button.swapButton(b);
		this->chooseEnemyButtons.push_back(button);
	}
	for (int i = 0; i < heroChoiceStrings.size()-2; i++) {
		this->b.setSize(sf::Vector2f(400.f, 100.f));
		this->b.setPosition(700, (videoMode.height - 400 - (100 * i)));
		this->b.setScale(sf::Vector2f(0.5f, 0.5f));
		this->b.setFillColor(sf::Color(255, 255, 255, 50));
		this->b.setOutlineColor(sf::Color::Black);
		this->b.setOutlineThickness(3.f);
		button.swapButton(b);
		this->chooseChampionButtons.push_back(button);
	}
	for (int i = heroChoiceStrings.size() - 2; i < heroChoiceStrings.size(); i++) {
		this->b.setSize(sf::Vector2f(400.f, 100.f));
		this->b.setPosition(610-(i-(heroChoiceStrings.size()-2))*600, 500);
		this->b.setScale(sf::Vector2f(0.5f, 0.5f));
		this->b.setFillColor(sf::Color(255, 255, 255, 50));
		this->b.setOutlineColor(sf::Color::Black);
		this->b.setOutlineThickness(3.f);
		button.swapButton(b);
		this->chooseChampionButtons.push_back(button);
	}
	for (int i = 0; i < gamePlayStrings.size(); i++) {
		this->b.setScale(sf::Vector2f(1.f, 1.f));
		this->b.setSize(sf::Vector2f(200.f, 50.f));
		this->b.setPosition((videoMode.width - b.getSize().x) / 2, videoMode.height - 100 - (100 * i));
		this->b.setFillColor(sf::Color(255, 255, 255, 50));
		this->b.setOutlineColor(sf::Color::Black);
		this->b.setOutlineThickness(1.5f);
		button.swapButton(b);
		this->gamePlayButtons.push_back(button);
	}
	this->b.setScale(sf::Vector2f(1.f, 1.f));
	this->b.setSize(sf::Vector2f(200.f, 50.f));
	this->b.setPosition(300, 400);
	this->b.setFillColor(sf::Color(255, 255, 255, 50));
	this->b.setOutlineColor(sf::Color::Black);
	this->b.setOutlineThickness(1.5f);
	backToMenuButton.swapButton(b);
}

void GameView::initFonts()
{
	if (!this->font.loadFromFile("Fonts/OldEnglish.ttf")) {
		throw std::invalid_argument("Nie da sie pobrac czcionki\n");
	}
}

void GameView::initMusic()
{
	if (!this->music.openFromFile("Music/Divine.ogg") or !this->soundBuffer.loadFromFile("Music/click.wav")) {
		throw std::invalid_argument("Nie da sie pobrac muzyki\n");
	}
	else {
		this->clickMusic.setBuffer(soundBuffer);
		this->musicPlaying = true;
		music.play();
		music.setLoop(true);
	}	
}

void GameView::initText()
{
	std::vector<std::string>menuStrings = initMenuStrings();
	std::vector<std::string>enemyChoiceStrings = initEnemyChoiceStrings();
	std::vector<std::string> heroChoiceStrings = initHeroChoiceStrings();
	std::vector<std::string> gamePlayStrings = initGamePlayStrings();
	sf::Text t;
	for (int i = 0; i < menuStrings.size(); i++) {
		t = setCaptions(i, menuStrings[i]);
		menuTexts.push_back(t);
	}
	for (int i = 0; i < enemyChoiceStrings.size(); i++) {
		t = setCaptions(i, enemyChoiceStrings[i]);
		t.setPosition(100, (videoMode.height - 100 - (100 * i)));
		chooseEnemyTexts.push_back(t);
	}
	for (int i = 0; i < heroChoiceStrings.size()-2; i++) {
		t = setCaptions(i, heroChoiceStrings[i]);
		t.setPosition(700, (videoMode.height - 400 - (100 * i)));
		chooseHeroTexts.push_back(t);
	}
	for (int i = heroChoiceStrings.size() - 2; i < heroChoiceStrings.size(); i++) {
		t = setCaptions(i, heroChoiceStrings[i]);
		t.setPosition(610 - (i - (heroChoiceStrings.size() - 2)) * 600, 500);
		chooseHeroTexts.push_back(t);
	}
	for (int i = 0; i < gamePlayStrings.size(); i++) {
		t = setCaptions(i, gamePlayStrings[i]);
		gamePlayTexts.push_back(t);
	}
	this->rankingBackText.setString("back");
	this->rankingBackText.setPosition(400, 400);
	this->rankingBackText.setFont(this->font);
	this->rankingBackText.setCharacterSize(40);
	this->rankingBackText.setFillColor(sf::Color::Black);	
}

void GameView::getDataFromFile()
{
	std::string data;
	int i;
	std::ifstream stream("Data/ranking.txt");
	bool emptyFile = is_empty(stream);
	std::cout << emptyFile << std::endl;
	if(!emptyFile){
		while (!stream.eof()) {
			stream >> data;
			i = stoi(data);
			this->scores.push_back(i);
		}
		if (scores.empty() == false) {
			scores.pop_back();
			this->sortVector(scores);
		}
		for (int i = 0; i < scores.size(); i++)
			std::cout << scores[i] << std::endl;
	}
	

}
void GameView::sortVector(std::vector<int>& vec)
{
	int temp;
	for (std::vector<int>::iterator iter = vec.begin(); iter != prev(vec.end(), 1); iter++) {
		temp = *iter;
		for (std::vector<int>::iterator iter2 = next(iter, 1); iter2 != vec.end(); iter2++) {
			if (*iter < * iter2) {
				*iter = *iter2;
				*iter2 = temp;
				temp = *iter;
			}
		}
	}
}
GameView::GameView(std::string fileName)
{
	this->initMenuStrings();
	this->initEnemyChoiceStrings();
	this->initVariables();
	this->initEnemy();
	this->initChampion();
	this->initTexture();
	this->initWindow();
	this->initButtons();
	this->initFonts();
	this->initMusic();
	this->initText();
	this->getDataFromFile();
}

GameView::~GameView(){}
//Accessors
const bool GameView::running() const
{
	return this->window->isOpen();
}

bool GameView::is_empty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

std::vector<std::string> GameView::initMenuStrings()
{
	std::vector<std::string>strings = { "Exit", "Rankings", "New game" };
	return (strings);
}

std::vector<std::string> GameView::initEnemyChoiceStrings()
{
	std::vector<std::string>strings = { "Back", "Another Enemy", "Choose Hero" };
	return (strings);
}

std::vector<std::string> GameView::initHeroChoiceStrings()
{
	std::vector<std::string>strings = { "Back", "Play", "Next", "Previous" };
	return (strings);
}

std::vector<std::string> GameView::initGamePlayStrings()
{
	std::vector<std::string>strings = { "Exit", "Attack", "Block" };
	return (strings);
}

sf::Text GameView::setCaptions(int amount, std::string caption)
{
	this->text.setFont(this->font);
	this->text.setCharacterSize(40);
	float textWidth = this->text.getLocalBounds().width; 
	float textHeight = this->text.getLocalBounds().height / 2;
	this->text.setFillColor(sf::Color::Black);
	this->text.setString(caption);
	this->text.setPosition((videoMode.width - button.Deco().getSize().x / 2) / 2, (videoMode.height - 100 - (100 * amount)));
	return text;
}

void GameView::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			music.pause();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape) {
				this->window->close();
				music.pause();
			}	
			break;
		
		case sf::Event::MouseButtonPressed:
			if (sf::Event::MouseButtonReleased) {
				if (menuButtons[0].Deco().getGlobalBounds().contains(mousePosView) && menuButtons[0].isActive() == true){
					clickMusic.pause();
					if (endGame == true) {
						clickMusic.play();
					}
						
					window->close();
					music.pause();	
				}
				else if (musicSprite.getGlobalBounds().contains(mousePosView)) {
					clickMusic.pause();
					clickMusic.play();
					if (musicPlaying == true) {
						music.pause();
						musicPlaying = false;
						this->musicSprite.setTexture(musicOffTexture);
					}
					else {
						music.play();
						musicPlaying = true;
						this->musicSprite.setTexture(musicOnTexture);
					}
				}
				else if (menuButtons[1].Deco().getGlobalBounds().contains(mousePosView) && menuButtons[1].isActive() == true) {
					menu = false;
					endGame = false;
					ranking = true;
					clickMusic.pause();
					clickMusic.play();
				}
				else if (menuButtons[2].Deco().getGlobalBounds().contains(mousePosView) && menuButtons[2].isActive() == true) {
					menu = false;
					chooseEnemy = true;
					endGame = false;
					clickMusic.pause();
					clickMusic.play();
					initEnemy();
				}
				else if (backToMenuButton.Deco().getGlobalBounds().contains(mousePosView) && backToMenuButton.isActive() == true) {
					menu = true;
					ranking = false;
					clickMusic.pause();
					clickMusic.play();
				}
				else if (chooseEnemyButtons[0].Deco().getGlobalBounds().contains(mousePosView) && chooseEnemyButtons[0].isActive() == true) {
					menu = true;
					chooseEnemy = true;
					clickMusic.pause();
					clickMusic.play();
				}
				else if (chooseEnemyButtons[1].Deco().getGlobalBounds().contains(mousePosView) && chooseEnemyButtons[0].isActive() == true) {
					generateEnemy();
					clickMusic.pause();
					clickMusic.play();
				}
				else if (chooseEnemyButtons[2].Deco().getGlobalBounds().contains(mousePosView) && chooseEnemyButtons[0].isActive() == true) {
					chooseEnemy = false;
					chooseChampion = true;
					clickMusic.pause();
					clickMusic.play();
					initChampion();
				}
				else if (chooseChampionButtons[0].Deco().getGlobalBounds().contains(mousePosView) && chooseChampionButtons[0].isActive() == true) {
					chooseChampion = false;
					chooseEnemy = true;
					clickMusic.pause();
					clickMusic.play();
				}
				else if (chooseChampionButtons[1].Deco().getGlobalBounds().contains(mousePosView) && chooseChampionButtons[0].isActive() == true) {
					chooseChampion = false;
					playGame = true;
					clickMusic.pause();
					clickMusic.play();
				}
				else if (chooseChampionButtons[2].Deco().getGlobalBounds().contains(mousePosView) && chooseChampionButtons[0].isActive() == true) {
					changeChampion(true);
					clickMusic.pause();
					clickMusic.play();
				}
				else if (chooseChampionButtons[3].Deco().getGlobalBounds().contains(mousePosView) && chooseChampionButtons[0].isActive() == true) {
					changeChampion(false);
					clickMusic.pause();
					clickMusic.play();
				}
				else if (gamePlayButtons[0].Deco().getGlobalBounds().contains(mousePosView) && gamePlayButtons[0].isActive() == true) {
					window->close();
					music.pause();
					clickMusic.pause();
					clickMusic.play();
				}
				else if (gamePlayButtons[1].Deco().getGlobalBounds().contains(mousePosView) && gamePlayButtons[1].isActive() == true){
					double specialPoints = 3000 - this->timer.asMilliseconds();
					if (game.getTurn() == true)
						game.addToScore(specialPoints);
					game.generateAttack(this->villain, this->hero);
					if (this->game.isGameOver() == true) {
						int s = game.getScore();
						saveScore(s);
					}
					gameClock.restart();
					std::cout << "villain HP: " << villain.getHp() << std::endl;
				}
				else if (gamePlayButtons[2].Deco().getGlobalBounds().contains(mousePosView) && gamePlayButtons[2].isActive() == true) {
				double specialPoints = 3000 - this->timer.asMilliseconds();
					if (game.getTurn() == false)
						game.addToScore(specialPoints);
					game.generateDefence(this->villain, this->hero);
					if (this->game.isGameOver() == true) {
						int s = game.getScore();
						saveScore(s);
					}
					triedToBlock = true;
					gameClock.restart();
				}
			}
			break;
		}
		if (this->game.isGameOver() == true ) {
			if (this->game.victory() == true) {
				playGame = false;
				endGame = true;
				this->endGameSprite.setTexture(victoryTexture);
			}	
			else {
				playGame = false;
				endGame = true;
				this->endGameSprite.setTexture(defeatTexture);
			}	
		}
	}
}
void GameView::battle()
{
	int heroType = champion.getType();
	int villainType = enemy.getType();
	this->villain.change(villainType);
	this->hero.change(heroType);
	GameProgress g1(villain, hero);
	this->game = g1;


}
void GameView::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

//updating buttons
void GameView::updateButtons()
{
	for (int i = 0; i < menuButtons.size(); i++) {
		b = menuButtons[i].Deco();
		if (this->b.getGlobalBounds().contains(this->mousePosView)) {
			this->b.setFillColor(sf::Color(255, 255, 255, 100));
			this->menuButtons[i].swapButton(b);
		}
		else {
			this->b.setFillColor(sf::Color(255, 255, 255, 50));
			this->menuButtons[i].swapButton(b);
		}
	}
	for (int i = 0; i < chooseEnemyButtons.size(); i++) {
		b = chooseEnemyButtons[i].Deco();
		if (this->b.getGlobalBounds().contains(this->mousePosView)) {
			this->b.setFillColor(sf::Color(255, 255, 255, 100));
			this->chooseEnemyButtons[i].swapButton(b);
		}
		else {
			this->b.setFillColor(sf::Color(255, 255, 255, 50));
			this->chooseEnemyButtons[i].swapButton(b);
		}
	}
	for (int i = 0; i < chooseChampionButtons.size(); i++) {
		b = chooseChampionButtons[i].Deco();
		if (this->b.getGlobalBounds().contains(this->mousePosView)) {
			this->b.setFillColor(sf::Color(255, 255, 255, 100));
			this->chooseChampionButtons[i].swapButton(b);
		}
		else {
			this->b.setFillColor(sf::Color(255, 255, 255, 50));
			this->chooseChampionButtons[i].swapButton(b);
		}
	}
	for (int i = 0; i < gamePlayButtons.size(); i++) {
		b = gamePlayButtons[i].Deco();
		if (this->b.getGlobalBounds().contains(this->mousePosView)) {
			this->b.setFillColor(sf::Color(255, 255, 255, 100));
			this->gamePlayButtons[i].swapButton(b);
		}
		else {
			this->b.setFillColor(sf::Color(255, 255, 255, 50));
			this->gamePlayButtons[i].swapButton(b);
		}
	}
	b = backToMenuButton.Deco();
	if (this->b.getGlobalBounds().contains(this->mousePosView)) {
		this->b.setFillColor(sf::Color(255, 255, 255, 100));
		this->backToMenuButton.swapButton(b);
	}
	else {
		this->b.setFillColor(sf::Color(255, 255, 255, 50));
		this->backToMenuButton.swapButton(b);
	}

	if (playGame == true) 
	{
		for (int i = 1500; i < 3000; i++) 
		{
			if (timer.asMilliseconds() > 1500 and timer.asMilliseconds() < 3000 and(timer.asMilliseconds()%500<=250))
			{
				if (this->game.getTurn() == true) 
				{
					this->b = this->gamePlayButtons[1].Deco();
					b.setOutlineColor(sf::Color::Red);
					this->b.setOutlineThickness(5.f);
					gamePlayButtons[1].swapButton(b);

					this->b = this->gamePlayButtons[2].Deco();
					b.setOutlineColor(sf::Color::Black);
					this->b.setOutlineThickness(1.5f);
					gamePlayButtons[2].swapButton(b);
				}
				else {
					this->b = this->gamePlayButtons[2].Deco();
					b.setOutlineColor(sf::Color::Red);
					this->b.setOutlineThickness(5.f);
					gamePlayButtons[2].swapButton(b);

					this->b = this->gamePlayButtons[1].Deco();
					b.setOutlineColor(sf::Color::Black);
					this->b.setOutlineThickness(1.5f);
					gamePlayButtons[1].swapButton(b);
				}
			}
			else 
			{
				if (this->game.getTurn() == true) 
				{
					this->b = this->gamePlayButtons[1].Deco();
					b.setOutlineColor(sf::Color::Black);
					this->b.setOutlineThickness(1.5f);
					gamePlayButtons[1].swapButton(b);
				}
				else {
					this->b = this->gamePlayButtons[2].Deco();
					b.setOutlineColor(sf::Color::Black);
					this->b.setOutlineThickness(1.5f);
					gamePlayButtons[2].swapButton(b);
				}
			}
		}
	}
}
void GameView::updateTime()
{
	this->timer = this->gameClock.getElapsedTime();
	if (this->timer.asSeconds() > 3) {
		if (triedToBlock == false and game.getTurn() == false) {
			game.generateLoss(villain, hero);
			if (game.isGameOver() == true) {
				if (playGame == true) {
					saveScore(game.getScore());
				}
				playGame = false;
				endGame = true;
				this->endGameSprite.setTexture(defeatTexture);
				
			}
		}	
		this->gameClock.restart();
		this->game.changeTurn();
	}
	triedToBlock = false;
		
}
void GameView::update()
{
		this->pollEvents();
		this->updateMousePositions();
		this->updateButtons();
		if(playGame)
			this->updateTime();
}

void GameView::generateEnemy()
{
	std::srand(std::time(0)); 
	int genType = std::rand()%5;
	enemy.changeType(genType);
	int type = enemy.getType();
	enemy.swapSprite(enemySprite);
	this->battle();

}
void GameView::changeChampion(bool forward)
{
	int championId = champion.getType();
	if (forward == true) {
		if (championId == 4)
			championId = 0;
		else
			championId++;
	}
	else {
		if (championId == 0)
			championId = 4;
		else
			championId--;
	}
	champion.changeType(championId);
	this->battle();
}
void GameView::renderButtonsMenu(sf::RenderTarget& target)
{	
	for (int i = 0; i < menuButtons.size(); i++) {
		b = menuButtons[i].Deco();
		menuButtons[i].changeActivity(true);
		target.draw(this->b);
	}
}
void GameView::renderButtonsEnemyChoice(sf::RenderTarget& target)
{
	for (int i = 0; i < chooseEnemyButtons.size(); i++) {
		b = chooseEnemyButtons[i].Deco();
		chooseEnemyButtons[i].changeActivity(true);
		target.draw(this->b);
	}
}
void GameView::renderButtonsHeroChoice(sf::RenderTarget& target)
{
	for (int i = 0; i < chooseChampionButtons.size(); i++) {
		b = chooseChampionButtons[i].Deco();
		chooseChampionButtons[i].changeActivity(true);
		target.draw(this->b);
	}
}
void GameView::renderButtonsGamePlay(sf::RenderTarget& target)
{
	for (int i = 0; i < gamePlayButtons.size(); i++) {
		b = gamePlayButtons[i].Deco();
		gamePlayButtons[i].changeActivity(true);
		target.draw(this->b);
	}
}
void GameView::renderTextMenu(sf::RenderTarget& target)
{
	for(int i=0; i<menuTexts.size(); i++)
		target.draw(this->menuTexts[i]);
}
void GameView::renderTextEnemyChoice(sf::RenderTarget& target)
{
	for (int i = 0; i < chooseEnemyTexts.size(); i++)
		target.draw(this->chooseEnemyTexts[i]);
}
void GameView::renderTextHeroChoice(sf::RenderTarget& target)
{
	for (int i = 0; i < chooseHeroTexts.size(); i++)
		target.draw(this->chooseHeroTexts[i]);

}
void GameView::renderTextGamePlay(sf::RenderTarget& target)
{
	for (int i = 0; i < gamePlayTexts.size(); i++)
		target.draw(this->gamePlayTexts[i]);
}
void GameView::renderTextRanking(sf::RenderTarget& target)
{
	sf::Text t;
	std::string s;
	if (scores.empty() == true) {
		t.setFont(this->font);
		t.setCharacterSize(30);
		t.setPosition(10, 25);
		t.setFillColor(sf::Color::Black);
		t.setString("There are no scores yet.\nPlay a game to add scores");
		target.draw(t);
	}
	rankingTexts.clear();
	for (int i = 0; i < scores.size(); i++) {
		t.setFont(this->font);
		t.setCharacterSize(30);
		t.setPosition(10, 25*(i+1));
		t.setFillColor(sf::Color::Black);
		s = std::to_string(i + 1) + ". \t" + std::to_string(scores[i]);
		t.setString(s);
		rankingTexts.push_back(t);
	}
	for (int i=0; i < rankingTexts.size(); i++)
		target.draw(this->rankingTexts[i]);
}
void GameView::renderFeature(sf::RenderTarget& target, bool enemy)
{
	sf::Text t1, hpText, mpText, strengthText, spellDefText, defText, speedText, nameText;
	t1.setFont(this->font);
	t1.setFillColor(sf::Color::Black);
	t1.setPosition(100, 20);
	t1.setCharacterSize(20);
	hpText = t1;
	mpText = t1;
	strengthText = t1;
	spellDefText = t1;
	defText = t1;
	speedText = t1;
	nameText = t1;
	nameText.setCharacterSize(30);

	
	if (enemy == true) {
		hpText.setString("hp:\t"+std::to_string(villain.getHp()));
		mpText.setString("magic points:\t" + std::to_string(villain.getMp()));
		strengthText.setString("strength:\t" + std::to_string(villain.getStrength()));
		spellDefText.setString("spell shield:\t" + std::to_string(villain.getSpellDefense()));
		defText.setString("defense:\t" + std::to_string(villain.getDefense()));
		speedText.setString("speed:\t" + std::to_string(villain.getSpeed()));
		hpText.setPosition(100, 105);
		mpText.setPosition(100, 125);
		strengthText.setPosition(100, 145);
		spellDefText.setPosition(100, 165);
		defText.setPosition(100, 185);
		speedText.setPosition(100, 205);
		nameText.setFillColor(sf::Color::Red);
		nameText.setPosition(115, 60);
		nameText.setString(this->enemy.getName());
		this->featureSprite.setPosition(50, 0);
		
	}
	else {
		hpText.setString("hp:\t" + std::to_string(hero.getHp()));
		mpText.setString("magic points:\t" + std::to_string(hero.getMp()));
		strengthText.setString("strength:\t" + std::to_string(hero.getStrength()));
		spellDefText.setString("spell shield:\t" + std::to_string(hero.getSpellDefense()));
		defText.setString("defense:\t" + std::to_string(hero.getDefense()));
		speedText.setString("speed:\t" + std::to_string(hero.getSpeed()));
		hpText.setPosition(80, 85);
		mpText.setPosition(80, 105);
		strengthText.setPosition(80, 125);
		spellDefText.setPosition(80, 145);
		defText.setPosition(80, 165);
		speedText.setPosition(80, 185);
		nameText.setFillColor(sf::Color::White);
		nameText.setPosition(95, 60);
		nameText.setString(this->champion.getName());
		this->featureSprite.setPosition(20, 0);
	}
	
	target.draw(this->featureSprite);
	target.draw(hpText);
	target.draw(mpText);
	target.draw(strengthText);
	target.draw(spellDefText);
	target.draw(defText);
	target.draw(speedText);
	target.draw(nameText);
}
void GameView::renderEnemy(sf::RenderTarget& target)
{
	enemySprite = enemy.getSprite();
	target.draw(this->enemySprite);
}
void GameView::renderChampion(sf::RenderTarget& target)
{
	championSprite = champion.getSprite();
	target.draw(this->championSprite);
}
void GameView::renderHp(sf::RenderTarget& target)
{
	std::string villain_hp, hero_hp, score, whoseTurn;
	villain_hp = game.getVillainHpString();
	hero_hp = "hp: " + std::to_string(hero.getHp());
	score = game.getPointsString();
	if (game.getTurn() == true)
		whoseTurn = "Attack";
	else
		whoseTurn = "Block";
	sf::Text heroHp;
	sf::Text villainHp;
	sf::Text turnText;

	heroHp.setString(hero_hp);
	heroHp.setFont(this->font);
	heroHp.setPosition(170, 50);
	heroHp.setCharacterSize(30);
	heroHp.setFillColor(sf::Color::Red);

	villainHp.setString(villain_hp);
	villainHp.setFont(this->font);
	villainHp.setPosition(850, 20);
	villainHp.setCharacterSize(30);
	villainHp.setFillColor(sf::Color::Red);

	this->scoreText.setString(score);
	this->scoreText.setFont(this->font);
	this->scoreText.setPosition(350, 20);
	this->scoreText.setCharacterSize(50);
	this->scoreText.setFillColor(sf::Color::Yellow);

	turnText.setString(whoseTurn);
	turnText.setFont(this->font);
	turnText.setPosition(350, 80);
	turnText.setCharacterSize(30);
	turnText.setFillColor(sf::Color::Magenta);

	target.draw(heroHp);
	target.draw(villainHp);
	target.draw(this->scoreText);
	target.draw(turnText);

}
void GameView::renderTime(sf::RenderTarget& target)
{
	std::string timeString;
	timeString = "Time: " + std::to_string(3 - this->timer.asSeconds());
	
	this->timeText.setString(timeString);
	this->timeText.setFont(this->font);
	this->timeText.setPosition(10, 10);
	this->timeText.setCharacterSize(50);
	this->timeText.setFillColor(sf::Color::Red);
	target.draw(this->timeText);

}
void GameView::renderMenu()
{
	this->window->clear();
	this->window->draw(this->menuSprite);
	this->window->draw(this->titleSprite);
	this->renderButtonsMenu(*this->window);
	this->renderTextMenu(*this->window);

	for (int i = 0; i < chooseEnemyButtons.size(); i++) 
		chooseEnemyButtons[i].changeActivity(false);
	backToMenuButton.changeActivity(false);

	
}
void GameView::renderEnemyChoice()
{
	this->window->clear();
	this->window->draw(this->enemyChoiceSprite);
	this->renderButtonsEnemyChoice(*this->window);
	this->renderTextEnemyChoice(*this->window);
	this->renderEnemy(*this->window);
	this->renderFeature(*this->window, true);

	for (int i = 0; i < menuButtons.size(); i++)
		menuButtons[i].changeActivity(false);
	
	for (int i = 0; i < chooseChampionButtons.size(); i++) 
		chooseChampionButtons[i].changeActivity(false);
	
	

}
void GameView::renderHeroChoice()
{
	this->window->clear();
	this->window->draw(this->heroChoiceSprite);
	this->renderButtonsHeroChoice(*this->window);
	this->renderTextHeroChoice(*this->window);
	this->renderChampion(*this->window);
	this->renderFeature(*this->window, false);

	for (int i = 0; i < chooseEnemyButtons.size(); i++)
		chooseEnemyButtons[i].changeActivity(false);
}
void GameView::renderGamePlay()
{

	this->window->clear();
	this->window->draw(this->gamePlaySprite);

	this->renderButtonsGamePlay(*this->window);
	this->renderTextGamePlay(*this->window);

	sf::Sprite s = this->champion.getSprite();
	s.setPosition(10, 100);
	this->champion.swapSprite(s);
	this->renderChampion(*this->window);

	s = this->enemy.getSprite();
	s.setPosition(450, 5);
	this->enemy.swapSprite(s);
	this->renderEnemy(*this->window);
	
	this->renderHp(*this->window);

	this->renderTime(*this->window);

	for (int i = 0; i < chooseChampionButtons.size(); i++)
		chooseChampionButtons[i].changeActivity(false);
}
void GameView::renderEndGame()
{
	this->window->clear();
	this->window->draw(this->endGameSprite);
	
	this->renderButtonsMenu(*this->window);
	this->renderTextMenu(*this->window);

	scoreText.setString(game.getPointsString());
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setCharacterSize(50);
	scoreText.setPosition(450, 200);

	this->window->draw(this->scoreText);

	for (int i = 0; i < gamePlayButtons.size(); i++)
		gamePlayButtons[i].changeActivity(false);
}
void GameView::renderRanking()
{
	this->window->clear();
	this->window->draw(this->rankingSprite);
	this->renderTextRanking(*this->window);

	b = backToMenuButton.Deco();
	backToMenuButton.changeActivity(true);
	this->window->draw(this->b);

	this->window->draw(this->rankingBackText);

	for (int i = 0; i < menuButtons.size(); i++)
		menuButtons[i].changeActivity(false);
}
void GameView::render(std::string fileName)
{
	if (menu)
		renderMenu();
	else if (ranking)
		renderRanking();
	else if (chooseEnemy)
		renderEnemyChoice();
	else if (chooseChampion)
		renderHeroChoice();
	else if (playGame)
		renderGamePlay();
	else if (endGame)
		renderEndGame();
	
	else
		std::cout << "Nice day" << std::endl;
	this->window->draw(this->musicSprite);
	
	
this->window->display();
}

std::vector<int> GameView::getScores()
{
	return scores;
}

void GameView::saveScore(int s)
{
	scores.push_back(s);
	this->sortVector(scores);
	while (scores.size() > 20)
		scores.pop_back();
	saveDataToFile();
}

void GameView::saveDataToFile()
{
	std::ofstream fout("Data/ranking.txt");
	for (int i = 0; i < scores.size(); i++) {
		fout << scores[i] << std::endl;
	}
}




