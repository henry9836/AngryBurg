#pragma once
#include <iostream>
#include <windows.h>
#include <Box2D/Box2D.h>
#include "ConsoleController.h"
#include "ITEMwall.h"
class Physics
{
public:

	Physics();
	~Physics();

	void worldsetup();

	std::vector<WallPhysics*> Walls;
	b2World* m_world;
};

