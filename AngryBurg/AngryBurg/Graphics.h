#pragma once
#include <iostream>
#include <glew.h>
#include <freeglut.h>
#include <SOIL.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "ConsoleController.h"

class Screen {
public:
	glm::vec2 screenSize = glm::vec2(1280, 720);
};

void InitalizeOpenGL(int argc, char* argv[]);