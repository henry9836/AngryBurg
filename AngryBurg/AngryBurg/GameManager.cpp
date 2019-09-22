#include "GameManager.h"

AudioSystem* audio;

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

void Game::populateObjects(Physics* physicsWorld)
{
	Console_OutputLog(L"Populating Gameobject Lists...", LOGINFO);

	/*
	* ==================
	* [ MAINMENU SCENE ]
	* ==================
	*/
	this->gameObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/background.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, -0.9f), glm::vec3(0, 0, 0), glm::vec3(1000.0f, 1000.0f, 1000.0f)), "BackDrop"));
	this->gameObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/logo.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(300.0f, 300.0f, 300.0f)), "Test Obj"));

	//this->gameObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::CARD_ENTITY), MeshManager::SetTexture("Resources/Textures/peter.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(100.0f, 100.0f, 100.0f)), "Test Obj"));
	for (int i = 0; i < physicsWorld->Walls.size(); i++)
	{
		this->gameObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::CARD_ENTITY), MeshManager::SetTexture("Resources/Textures/peter.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Test Wall", new WallPhysics(physicsWorld->m_world, physicsWorld->Walls.at(i)->m_middlepos, physicsWorld->Walls.at(i)->m_hx, physicsWorld->Walls.at(i)->m_hy, physicsWorld->Walls.at(i)->m_angle)));
	}
	
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

void Game::Initalize(Physics* physicsWorld)
{
	Console_OutputLog(L"Initalizing Game...", LOGINFO);

	audio = new AudioSystem();

	audio->AudioInit();

	audio->Play(AudioSystem::BACK);

	populateObjects(physicsWorld);

	Console_OutputLog(L"Done.", LOGINFO);
}

