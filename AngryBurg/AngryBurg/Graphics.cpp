#include "Graphics.h"
#include "Physics.h"

Physics physics;
Game* game;

float currentTime;
float deltaTime;
float pasttime;
bool goingup = true;
glm::vec3 backColor = glm::vec3(0.0, 0.0, 0.0);

void FlashRed(glm::vec3* inColor, float deltaTime) {
	float increase = 0.01f * deltaTime;
	if (goingup) {
		if (inColor->x >= 1) {
			goingup = !goingup;
		}
		else {
			inColor->x += increase;
		}
	}
	else {
		if (inColor->x <= 0) {
			goingup = !goingup;
		}
		else {
			inColor->x -= increase;
		}
	}
}

void Render() {
	glClearColor(backColor.x, backColor.y, backColor.z, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	for (size_t i = 0; i < game->gameObjects.size(); i++)
	{
		game->gameObjects.at(i)->Render();
	}

	if (game->currentScene == SCENE_MAIN) {
		for (size_t i = 0; i < game->mainObjects.size(); i++)
		{
			game->mainObjects.at(i)->Render();
		}
	}
	else if (game->currentScene == SCENE_LVL1) {
		for (size_t i = 0; i < game->lvlOneObjects.size(); i++)
		{
			game->lvlOneObjects.at(i)->Render();
		}
	}
	else if (game->currentScene == SCENE_LVL2) {
		for (size_t i = 0; i < game->lvlTwoObjects.size(); i++)
		{
			game->lvlTwoObjects.at(i)->Render();
		}
	}

	glutSwapBuffers();
}

void Update() {

	currentTime = static_cast<float>(glutGet(GLUT_ELAPSED_TIME));
	deltaTime = (currentTime - pasttime) * 0.1f;
	pasttime = currentTime;
	FlashRed(&backColor, deltaTime);

	game->Tick(deltaTime);

	Render();
}

void InitalizeOpenGL(int argc, char* argv[])
{
	game = new Game();

	physics.worldsetup();

	Console_OutputLog(L"Initalizing OpenGL Service...", LOGINFO);

	//glut init

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize((int)game->ScreenSize.x, (int)game->ScreenSize.y);
	glutCreateWindow("Angry Burbs");

	if (glewInit() != GLEW_OK) {
		Console_OutputLog(L"Glew INIT FAILED! The program cannot recover from this error", LOGFATAL);
		system("pause");
		exit(0);
	}

	glutSetOption(GLUT_MULTISAMPLE, 8);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearColor(backColor.x, backColor.y, backColor.z, 1.0);

	Console_OutputLog(L"OpenGL Service Initalized", LOGINFO);

	//Initalize Game After Glew is ready

	MeshManager::GetInstance();

	game->Initalize(&physics);

	glutDisplayFunc(Render);

	glutIdleFunc(Update);

	glutMainLoop();

}
