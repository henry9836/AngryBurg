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
	this->gameObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::CARD_ENTITY), MeshManager::SetTexture("Resources/Textures/missing.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new TickObject, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(100.0f, 100.0f, 100.0f)), "Test Obj"));

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

