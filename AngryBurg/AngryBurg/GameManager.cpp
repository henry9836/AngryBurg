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
	this->gameObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::CARD_ENTITY), MeshManager::SetTexture("Resources/Textures/peter.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(100.0f, 100.0f, 100.0f)), "Test Obj"));
	this->gameObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::CARD_ENTITY), MeshManager::SetTexture("Resources/Textures/peter.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new TickWall, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Test Wall"));

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

