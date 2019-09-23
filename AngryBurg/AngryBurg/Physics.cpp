#include "Physics.h"



Physics::Physics()
{
}

Physics::~Physics()
{
}

void Physics::worldsetup()
{
	Console_OutputLog(L"Box2D Setup Start", LOGINFO);


	//creating a world
	b2Vec2 gravity(0.0f, -9.81f);
	m_world = new b2World(gravity);


	float32 thicknes = 640;

	WallPhysics* wall = new WallPhysics(m_world, b2Vec2(-100, -300), 500, 50, 45, b2_staticBody); //ground
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(0, 100), 50, 50, 10, b2_dynamicBody); //right wall
	Walls.push_back(wall);

	Console_OutputLog(L"Box2D Setup Done.", LOGINFO);
}
