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
	* ===========
	* [ PHYSICS ]
	* ===========
	*/

	for (unsigned int i = 0; i < physicsWorld->Walls.size(); i++)
	{

		if (physicsWorld->Walls.at(i)->wallType == PHYSICSTAG::DEFAULT) {
			this->gameObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/wood.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new TickWall, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Default Physics Object", physicsWorld->Walls.at(i)));
		}
		else if (physicsWorld->Walls.at(i)->wallType == PHYSICSTAG::BIRD) {
			this->gameObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/bird.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new TickWall, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Bird Physics Object", physicsWorld->Walls.at(i)));
			if (firstBird == nullptr) {
				firstBird = gameObjects.back();
				playerBird = firstBird;
			}
			else {
				secondBird = gameObjects.back();
			}
		}
		else if (physicsWorld->Walls.at(i)->wallType == PHYSICSTAG::PIG) {
			this->gameObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/pig.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new TickWall, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Pig Physics Object", physicsWorld->Walls.at(i)));
		}
		else if (physicsWorld->Walls.at(i)->wallType == PHYSICSTAG::STRONGWALL) {
			this->gameObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/stone.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new TickWall, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Stone Physics Object", physicsWorld->Walls.at(i)));
		}
		else if (physicsWorld->Walls.at(i)->wallType == PHYSICSTAG::GROUND) {
			this->gameObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/ground.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new TickWall, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Ground Physics Object", physicsWorld->Walls.at(i)));
		}
		else {
			this->gameObjects.push_back(new WallObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/wood.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new TickWall, Transform(glm::vec3(150.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(10.0f, 100.0f, 100.0f)), "Unknown Physics Object", physicsWorld->Walls.at(i)));
		}

	}
	
	/*
	* ==================
	* [ MAINMENU SCENE ]
	* ==================
	*/
	//this->gameObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/logo.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(300.0f, 300.0f, 300.0f)), "Test Obj"));

	this->mainObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/logo.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(250.0f, 250.0f, 1.0f)), "Test Obj"));



	/*
	* ==============
	* [ LVL1 SCENE ]
	* ==============
	*/

	this->lvlOneObjects.push_back(new BasicObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/sling.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(-450.0f, -200.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(50.0f, 50.0f, 1.0f)), "Slingshot"));
	sling = lvlOneObjects.back();
	// this->lvlOneObjects.push_back(new PigObject(new RenderObject(MeshManager::GetMesh(Object_Attributes::SPRITE), MeshManager::SetTexture("Resources/Textures/pig.png"), this, MeshManager::GetShaderProgram(Shader_Attributes::BASIC_SHADER)), new IdleTick, Transform(glm::vec3(300.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(20.0f, 20.0f, 1.0f)), "Pig", physicsWorld->Walls.at(1), this));

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

	this->gameoverText = new BasicObject(new RenderText(new CTextLabel("Gameover\n\n\n\n Press R To Retry", "Resources/Fonts/angrybirds.ttf", glm::vec2(-130.0f, 300.0f), glm::vec3(1.0f, 0.0f, 0.0f), 1.0f, this, "Title Text")), new IdleTick, Transform(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec3(100.0f, 100.0f, 100.0f)), "GameOver Text");


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

void Game::Reset() {
	birdsRemaining = 3;
	spawnTimer = 0.0f;
	gameover = false;
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects.at(i)->wall != nullptr) {
			if (gameObjects.at(i)->wall->m_type != b2_staticBody) {
				gameObjects.at(i)->wall->m_body->SetActive(true);
				gameObjects.at(i)->wall->Reset();
			}
		}
	}
}

bool Game::AllPigDead() {
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects.at(i)->wall != nullptr) {
			if (gameObjects.at(i)->wall->assignedScene == currentScene) {
				if (gameObjects.at(i)->wall->m_body->GetID() == PHYSICSTAG::PIG) {
					if (!gameObjects.at(i)->wall->m_body->GetMark()) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

//Update Loop For Game
void Game::Tick(float deltaTime)
{
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		gameObjects.at(i)->Tick(deltaTime, gameObjects.at(i));
		if (gameObjects.at(i)->wall != nullptr) {
			
		}
	}

	spawnTimer += deltaTime/60;

	//Physics
	if (currentScene == SCENE_LVL1) {
		physicsWorld->m_world->Step(1 / 60.0f, 6, 2);
	}
	else if (currentScene == SCENE_LVL2) {
		physicsWorld->m_world2->Step(1 / 60.0f, 6, 2);
	}
	//Input System

	if (input.CheckKeyDown(27)) { //esc
		Console_OutputLog(L"QUIT", LOGINFO);
		Exit();
	}

	if (input.CheckKeyDown(114)) { //r
		Reset();
	}

	if (currentScene == SCENE_MAIN) {
		if (input.CheckKeyDown(32)) { //space
			Console_OutputLog(L"User Started Game", LOGINFO);
			currentScene = SCENE_LVL1;
			Reset();
		}
	}
	else if (currentScene == SCENE_LVL1 || currentScene == SCENE_LVL2) {

		if (mouseDown && (spawnTimer > spawnTimerThreshold) && (birdsRemaining > 0)) {
			if ((findDistance(MousePosition, glm::vec2(sling->transform.position.x, sling->transform.position.y)) < 135) && (findDistance(MousePosition, glm::vec2(sling->transform.position.x, sling->transform.position.y)) > 20)) {
				float scaler = (1.0f / 64.0f);
				playerBird->wall->m_body->SetTransform(b2Vec2(MousePosition.x * scaler, MousePosition.y * scaler), playerBird->wall->m_body->GetAngle());
				Console_OutputLog(L"Clicked", LOGINFO);
				holdingBird = true;

			}
		}
		else if (holdingBird){
			holdingBird = false;
			birdsRemaining--;


			playerBird->wall->m_body->SetLinearVelocity(b2Vec2_zero);
			playerBird->wall->m_body->SetAngularVelocity(float32(0));
			glm::vec2 launchDir = glm::vec2((sling->transform.position.x - playerBird->transform.position.x),(sling->transform.position.y - playerBird->transform.position.y)) * 0.75f;

			playerBird->wall->m_body->ApplyLinearImpulse(b2Vec2(launchDir.x, launchDir.y), playerBird->wall->m_body->GetWorldCenter(), true);
		}
	}

	//Check for GameOver

	if (AllPigDead() || (birdsRemaining <= 0)) {
		
		if (currentScene == SCENE_LVL1) {
			if (AllPigDead()) {
				Console_OutputLog(L"GAMEOVER", LOGINFO);
				currentScene = SCENE_LVL2;
				playerBird = secondBird;
				Reset();
			}
			else {
				Console_OutputLog(L"GAMEOVER", LOGINFO);
				gameover = true;
			}
		}
		else if (currentScene == SCENE_LVL2) {
			if (AllPigDead()) {
				Console_OutputLog(L"GAMEOVER", LOGINFO);
				currentScene = SCENE_MAIN;
				playerBird = firstBird;
				Reset();
			}
			else {
				Console_OutputLog(L"GAMEOVER", LOGINFO);
				gameover = true;
			}
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

