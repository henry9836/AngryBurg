#pragma once
#include "Util.h"

#include "MeshManager.h"
#include "Physics.h"
#include "Audio.h"
#include "Input.h"

class CMenu;
class GameObject;
class CTextLabel;

class Game {
public:

	Game();
	~Game();

	Scenes currentScene = SCENE_MAIN;
	CMenu* StartMenu = nullptr;

	//scenes
	vector<GameObject*> gameObjects; //global
	vector<GameObject*> mainObjects; //main menu
	vector<GameObject*> lvlOneObjects; //lvl1
	vector<GameObject*> lvlTwoObjects; //lvl2

	GameObject* playerBird = nullptr;
	GameObject* sling = nullptr;

	Physics* physicsWorld = nullptr;
	Physics* physicsWorld2 = nullptr;

	glm::vec2 ScreenSize = { 1280, 720 };
	glm::vec2 MousePosition;

	bool mouseDown = false;
	bool holdingBird = false;

	int birdsRemaining = 3;

	float spawnTimerThreshold = 5.0f;
	float spawnTimer = 0.0f;

	void switchScene(Scenes newScene);
	void Initalize(Physics* _physicsWorld);
	void populateObjects();

	void Reset();

	void Tick(float deltaTime);

};

#include "GameObject.h"
#include "TextManager.h"