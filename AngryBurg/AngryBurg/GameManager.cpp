#include "GameManager.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::switchScene(Scenes newScene)
{
	this->currentScene = newScene;
}

void Game::populateObjects()
{
	Console_OutputLog(L"Populating Gameobject Lists...", LOGINFO);

	/*
	* ==================
	* [ MAINMENU SCENE ]
	* ==================
	*/

	/*
	* ==============
	* [ LVL1 SCENE ]
	* ==============
	*/

	/*
	* ==============
	* [ LVL2 SCENE ]
	* ==============
	*/

}

void Game::Initalize()
{
	Console_OutputLog(L"Initalizing Game...", LOGINFO);

	populateObjects();

	Console_OutputLog(L"Done.", LOGINFO);
}

