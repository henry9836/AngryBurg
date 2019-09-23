#include "GameManager.h"

AudioSystem* audio;
Input input;

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
	* [ GLOBAL SCENE ]
	* ==================
	*/

	this->gameObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/background.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, -0.9f), glm::vec3(0, 0, 0), glm::vec3(1000.0f, 1000.0f, 1.0f)), "BackDrop"));

	/*
	* ==================
	* [ MAINMENU SCENE ]
	* ==================
	*/

	this->mainObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/logo.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(250.0f, 250.0f, 1.0f)), "Test Obj"));

	for (int i = 0; i < physicsWorld->Walls.size(); i++)
	{
		this->mainObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/stone.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Test Wall", new WallPhysics(physicsWorld->m_world, physicsWorld->Walls.at(i)->m_middlepos, physicsWorld->Walls.at(i)->m_hx, physicsWorld->Walls.at(i)->m_hy, physicsWorld->Walls.at(i)->m_angle)));
	}
	
	/*
	* ==============
	* [ LVL1 SCENE ]
	* ==============
	*/

	this->lvlOneObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/sling.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(-450.0f, -200.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(50.0f, 50.0f, 1.0f)), "Slingshot"));
	sling = lvlOneObjects.back();
	this->lvlOneObjects.push_back(new PigObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/pig.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(300.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(20.0f, 20.0f, 1.0f)), "Pig", new WallPhysics(physicsWorld->m_world, physicsWorld->Walls.at(1)->m_middlepos, physicsWorld->Walls.at(1)->m_hx, physicsWorld->Walls.at(1)->m_hy, physicsWorld->Walls.at(1)->m_angle), this));

	/*
	* ==============
	* [ LVL2 SCENE ]
	* ==============
	*/

	this->lvlTwoObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/sling.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(-450.0f, -200.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(50.0f, 50.0f, 1.0f)), "Slingshot"));

	/*
	* ==================
	* [ MAINMENU TEXT ]
	* ==================
	*/

	this->mainObjects.push_back(new BasicObject(new RenderText(new CTextLabel("Press Space To Continue", "Resources/Fonts/angrybirds.ttf", glm::vec2(-600.0f, -350.0f), glm::vec3(0.0f, 0.0f, 0.0f), 0.7f, this, "Press Space To Continue")), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(100.0f, 100.0f, 100.0f)), "Press Space To Continue"));
	this->mainObjects.push_back(new BasicObject(new RenderText(new CTextLabel("Angry Birbs", "Resources/Fonts/angrybirds.ttf", glm::vec2(-130.0f, 300.0f), glm::vec3(1.0f, 0.0f, 0.0f), 1.0f, this, "Title Text")), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(100.0f, 100.0f, 100.0f)), "Title Text"));

	/*
	* ==============
	* [ LVL1 TEXT ]
	* ==============
	*/



	/*
	* ==============
	* [ LVL2 TEXT ]
	* ==============
	*/

}

float findDistance(glm::vec2 p1, glm::vec2 p2) {
	float result = (sqrt((pow((p2.x-p1.x), 2)) + (pow(p2.y - p1.y , 2))));
	if (result < 0) {
		result *= -1;
	}
	return result;
}

void Exit() {

	//free up memory here

	glutLeaveMainLoop();
	exit(0);
}

//Update Loop For Game
void Game::Tick(float deltaTime)
{
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		gameObjects.at(i)->Tick(deltaTime, gameObjects.at(i));
	}

	//Input System

	if (input.CheckKeyDown(27)) { //esc
		Console_OutputLog(L"QUIT", LOGINFO);
		Exit();
	}

	if (currentScene == SCENE_MAIN) {
		if (input.CheckKeyDown(32)) { //space
			Console_OutputLog(L"User Started Game", LOGINFO);
			currentScene = SCENE_LVL1;
		}
	}
	else if (currentScene == SCENE_LVL1) {
		if (playerBird == nullptr) {
			lvlOneObjects.push_back(new BirdObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/bird.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(sling->transform.position, glm::vec3(0, 0, 0), glm::vec3(20.0f, 20.0f, 1.0f)), "Angry Bird", new WallPhysics(physicsWorld->m_world, physicsWorld->Walls.at(0)->m_middlepos, physicsWorld->Walls.at(0)->m_hx, physicsWorld->Walls.at(0)->m_hy, physicsWorld->Walls.at(0)->m_angle), BirdObject::DEFAULT, this));
			playerBird = lvlOneObjects.back();
		}

		if (mouseDown) {
			if (findDistance(MousePosition, glm::vec2(sling->transform.position.x, sling->transform.position.y)) < 125) {
				playerBird->transform.position = glm::vec3(MousePosition.x, MousePosition.y ,0.5);
			}
			else {
				wcout << L"Not in range: " << findDistance(MousePosition, glm::vec2(sling->transform.position.x, sling->transform.position.y)) << endl;
			}
			Console_OutputLog(L"Clicked", LOGINFO);
		}
	}


}

void Game::Initalize(Physics* _physicsWorld)
{
	Console_OutputLog(L"Initalizing Game...", LOGINFO);

	audio = new AudioSystem();

	audio->AudioInit();

	audio->Play(AudioSystem::BACK);

	Console_OutputLog(L"Initalizing Input System...", LOGINFO);

	glutKeyboardFunc(Input::KeyboardDown);
	glutKeyboardUpFunc(Input::KeyboardUp);

	glutSpecialFunc(Input::specialCharDown);
	glutSpecialUpFunc(Input::specialCharUp);

	physicsWorld = _physicsWorld;

	populateObjects();

	Console_OutputLog(L"Done.", LOGINFO);
}

