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

	int thicknes = 30;

	WallPhysics* wall = new WallPhysics(m_world, b2Vec2(0, -360 + thicknes), 640 , thicknes, 0); //ground
	Walls.push_back(wall);
	wall = new WallPhysics(m_world, b2Vec2(0, 360 - thicknes), 640, thicknes, 0); //ceiling
	Walls.push_back(wall);
	wall = new WallPhysics(m_world, b2Vec2(-640 + thicknes, 0), thicknes, 400, 0); //left wall
	Walls.push_back(wall);
	wall = new WallPhysics(m_world, b2Vec2(640 - thicknes, 0), thicknes, 400, 0); //right wall
	Walls.push_back(wall);

	Console_OutputLog(L"Box2D Setup Done.", LOGINFO);
}
