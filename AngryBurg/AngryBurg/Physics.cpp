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
	m_world2 = new b2World(gravity);

	float32 thicknes = 640;

	//LVL1

	WallPhysics* wall = new WallPhysics(m_world, b2Vec2(0, -950), 650, 650, 45, b2_staticBody, SCENE_LVL1, WallPhysics::GROUND); //ground
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(300, 100), 50, 50, 10, b2_dynamicBody, SCENE_LVL1, WallPhysics::BIRD); //birb
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(0, 100), 50, 50, 10, b2_dynamicBody, SCENE_LVL1, WallPhysics::PIG); //piig
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(-150, 0), 30, 200, 0, b2_dynamicBody, SCENE_LVL1, WallPhysics::DEFAULT);// obsicle1
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(-300, 0), 30, 200, 0, b2_dynamicBody, SCENE_LVL1, WallPhysics::STRONGWALL);// obsicle1
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(-150, 300), 200, 30, 0, b2_dynamicBody, SCENE_LVL1, WallPhysics::DEFAULT);// obsicle1
	Walls.push_back(wall);

	//LVL2

	wall = new WallPhysics(m_world2, b2Vec2(0, -950), 650, 650, 45, b2_staticBody, SCENE_LVL2, WallPhysics::GROUND); //ground
	Walls.push_back(wall);

	wall = new WallPhysics(m_world2, b2Vec2(150, 0), 30, 200, 0, b2_dynamicBody, SCENE_LVL2, WallPhysics::DEFAULT);// obsicle1
	Walls.push_back(wall);

	wall = new WallPhysics(m_world2, b2Vec2(-300, 0), 30, 200, 0, b2_dynamicBody, SCENE_LVL2, WallPhysics::STRONGWALL);// obsicle1
	Walls.push_back(wall);

	wall = new WallPhysics(m_world2, b2Vec2(-200, 300), 200, 30, 0, b2_dynamicBody, SCENE_LVL2, WallPhysics::DEFAULT);// obsicle1
	Walls.push_back(wall);

	Console_OutputLog(L"Box2D Setup Done.", LOGINFO);
}
