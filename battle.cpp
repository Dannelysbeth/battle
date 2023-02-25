

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
//#include <Cursor.hpp>

#include "class.h"
#include "GameProgress.h"
#include "DarkElf.h"
#include "Dragon.h"
#include "Orc.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Assassin.h"
#include "GameView.h"
#include "function.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::string fileName = "Captions/menuButtonsCaptions.txt";
    //wywolanie obiektu klasy gameView
    GameView gameView(fileName);

    //game loop
    while (gameView.running()) {
        //event polling

        //Update
        gameView.update();

        //Render
        gameView.render(fileName);

    }
    system("PAUSE");
    return 0;
}

