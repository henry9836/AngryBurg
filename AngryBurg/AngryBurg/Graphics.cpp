#include "Graphics.h"
#include "Physics.h"

Physics physics;
Game* game;

float currentTime;
float deltaTime;
float pasttime;

void Render() {
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	for (size_t i = 0; i < game->gameObjects.size(); i++)
	{
		game->gameObjects.at(i)->Render();
	}

	glutSwapBuffers();
}

void Update() {

	currentTime = static_cast<float>(glutGet(GLUT_ELAPSED_TIME));
	deltaTime = (currentTime - pasttime) * 0.1f;
	pasttime = currentTime;

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
	glClearColor(1.0, 0.0, 0.0, 1.0);

	Console_OutputLog(L"OpenGL Service Initalized", LOGINFO);

	//Initalize Game After Glew is ready

	MeshManager::GetInstance();

	game->Initalize();



	glutDisplayFunc(Render);

	glutIdleFunc(Update);

	glutMainLoop();

}
