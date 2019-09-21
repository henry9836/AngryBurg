#include "Physics.h"



void Physics::worldsetup()
{
	Console_OutputLog(L"box2d setup", LOGINFO);

	//creating a world
	b2Vec2 gravity(0.0f, -9.81f);
	b2World world(gravity);	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(0, 0);
	b2Body* staticBody = world->CreateBody(&myBodyDef);

	//shape definition
	b2PolygonShape polygonShape;

	//fixture definition
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &polygonShape;

	//add four walls to the static body
	polygonShape.SetAsBox(20, 1, b2Vec2(0, 0), 0);//ground
	staticBody->CreateFixture(&myFixtureDef);
	polygonShape.SetAsBox(20, 1, b2Vec2(0, 40), 0);//ceiling
	staticBody->CreateFixture(&myFixtureDef);
	polygonShape.SetAsBox(1, 20, b2Vec2(-20, 20), 0);//left wall
	staticBody->CreateFixture(&myFixtureDef);
	polygonShape.SetAsBox(1, 20, b2Vec2(20, 20), 0);//right wall
	staticBody->CreateFixture(&myFixtureDef);
}
