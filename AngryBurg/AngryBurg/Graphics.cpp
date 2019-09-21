#include "Graphics.h"
#include "Physics.h"

Physics physics;
Game game;

void Render() {
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	for (size_t i = 0; i < game.gameObjects.size(); i++)
	{
		game.gameObjects.at(i)->Render();
	}

	glutSwapBuffers();
}

void Update() {
	Render();
}

void InitalizeOpenGL(int argc, char* argv[])
{
	game.Initalize();

	physics.worldsetup();

	Console_OutputLog(L"Initalizing OpenGL Service...", LOGINFO);

	//glut init

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize((int)game.ScreenSize.x, (int)game.ScreenSize.y);
	glutCreateWindow("Angry Burbs");

	if (glewInit() != GLEW_OK) {
		Console_OutputLog(L"Glew INIT FAILED! The program cannot recover from this error", LOGFATAL);
		system("pause");
		exit(0);
	}

	Console_OutputLog(L"Game Assets Initalised. Starting Game...", LOGINFO);

	glutDisplayFunc(Render);

	glutIdleFunc(Update);

	glutMainLoop();

}
