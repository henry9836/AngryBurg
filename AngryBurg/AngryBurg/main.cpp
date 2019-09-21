#include <iostream>
#include <windows.h>
#include <Box2D/Box2D.h>
#include "ConsoleController.h"
#include "Graphics.h"

using namespace std;

int main(int argc, char* argv[])
{
	Console_Initalize();
	InitalizeOpenGL(argc, argv);

	system("pause");
	return(0);
}