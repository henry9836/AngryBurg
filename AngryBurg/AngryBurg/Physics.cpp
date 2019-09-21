#include "Physics.h"



void Physics::worldsetup()
{
	Console_OutputLog(L"box2d setup", LOGINFO);

	//creating a world
	b2Vec2 gravity(0.0f, -9.81f);
	b2World world(gravity);	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);	b2Body* groundBody = world.CreateBody(&groundBodyDef);	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
}
