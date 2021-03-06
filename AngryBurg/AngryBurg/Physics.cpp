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

	contactListner = new Listner;

	m_world->SetContactListener(&*contactListner);
	m_world2->SetContactListener(&*contactListner);


	float32 thicknes = 640;

	//LVL1

	WallPhysics* wall = new WallPhysics(m_world, b2Vec2(0, -950), 650, 650, 45, b2_staticBody, SCENE_LVL1, PHYSICSTAG::GROUND); //ground
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(1000, 100), 50, 50, 10, b2_dynamicBody, GLOBAL, PHYSICSTAG::BIRD); //birb
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(0, 100), 50, 50, 10, b2_dynamicBody, SCENE_LVL1, PHYSICSTAG::PIG); //piig
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(-50, 0), 30, 200, 0, b2_dynamicBody, SCENE_LVL1, PHYSICSTAG::DEFAULT);// obsicle1
	Walls.push_back(wall);

	wall = new WallPhysics(m_world, b2Vec2(-300, 0), 30, 200, 0, b2_dynamicBody, SCENE_LVL1, PHYSICSTAG::STRONGWALL);// obsicle1
	Walls.push_back(wall);

	//LVL2

	wall = new WallPhysics(m_world2, b2Vec2(0, -950), 650, 650, 45, b2_staticBody, SCENE_LVL2, PHYSICSTAG::GROUND); //ground
	Walls.push_back(wall);

	wall = new WallPhysics(m_world2, b2Vec2(1000, 100), 50, 50, 10, b2_dynamicBody, GLOBAL, PHYSICSTAG::BIRD); //birb
	Walls.push_back(wall);

	wall = new WallPhysics(m_world2, b2Vec2(150, 50), 50, 50, 10, b2_dynamicBody, SCENE_LVL2, PHYSICSTAG::PIG); //piig
	Walls.push_back(wall);

	wall = new WallPhysics(m_world2, b2Vec2(50, 0), 30, 200, 0, b2_dynamicBody, SCENE_LVL2, PHYSICSTAG::DEFAULT);// obsicle1
	Walls.push_back(wall);

	wall = new WallPhysics(m_world2, b2Vec2(300, 0), 30, 200, 0, b2_dynamicBody, SCENE_LVL2, PHYSICSTAG::DEFAULT);// obsicle1
	Walls.push_back(wall);

	wall = new WallPhysics(m_world2, b2Vec2(150, 300), 200, 30, 0, b2_dynamicBody, SCENE_LVL2, PHYSICSTAG::STRONGWALL);// obsicle1
	Walls.push_back(wall);

	Console_OutputLog(L"Box2D Setup Done.", LOGINFO);
}
