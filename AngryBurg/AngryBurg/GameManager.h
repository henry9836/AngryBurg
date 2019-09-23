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
	CMenu* StartMenu;

	//scenes
	vector<GameObject*> gameObjects; //global
	vector<GameObject*> mainObjects; //main menu
	vector<GameObject*> lvlOneObjects; //lvl1
	vector<GameObject*> lvlTwoObjects; //lvl2

	GameObject* playerBird;
	GameObject* sling;

	Physics* physicsWorld;
	 
	glm::vec2 ScreenSize = { 1280, 720 };
	glm::vec2 MousePosition;

	bool mouseDown = false;

	void switchScene(Scenes newScene);
	void Initalize(Physics* _physicsWorld);
	void populateObjects();

	void Tick(float deltaTime);

};

#include "GameObject.h"
#include "TextManager.h"