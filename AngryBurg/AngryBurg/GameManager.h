#pragma once
#include "Util.h"

#include "MeshManager.h"
#include "Physics.h"
#include "Audio.h"

class CMenu;
class GameObject;

class Game {
public:

	Game();
	~Game();

	Scenes currentScene;
	CMenu* StartMenu;

	//scenes
	vector<GameObject*> gameObjects; //global
	vector<GameObject*> mainObjects; //main menu
	vector<GameObject*> lvlOneObjects; //lvl1
	vector<GameObject*> lvlTwoObjects; //lvl2

	glm::vec2 ScreenSize = { 1280, 720 };
	glm::vec2 MousePosition;

	void switchScene(Scenes newScene);
	void Initalize(b2World* physicsWorld);
	void populateObjects(b2World* physicsWorld);

};

#include "GameObject.h"