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



	//Wall* wall = new Wall(m_world, b2Vec2(0, 0), 20 , 1, 0); //ground
	//Walls.push_back(wall);
	//wall = new Wall(m_world, b2Vec2(0, 40), 20, 1, 0); //ceiling
	//Walls.push_back(wall);
	//wall = new Wall(m_world, b2Vec2(-20, 20), 1, 20, 0); //left wall
	//Walls.push_back(wall);
	//wall = new Wall(m_world, b2Vec2(20, 20), 1, 20, 0); //right wall
	//Walls.push_back(wall);

	Console_OutputLog(L"Box2D Setup Done.", LOGINFO);
}
