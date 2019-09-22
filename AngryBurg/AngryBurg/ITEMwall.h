#pragma once
#include "Physics.h"

class WallPhysics {
public:
	//class member variables
	b2Body* m_body;
	b2Vec2 m_middlepos;
	float32 m_hx;
	float32 m_hy;
	float32 m_angle;


	WallPhysics(b2World* world, b2Vec2 middlepos, float32 hx, float32 hy, float32 angle)
	{
		m_body = NULL;
		m_middlepos = middlepos;
		m_hx = hx;
		m_hy = hy;
		m_angle = angle;


		b2BodyDef myBodyDef;
		myBodyDef.type = b2_staticBody;
		myBodyDef.position.Set(0, 0);
		b2Body* staticBody = world->CreateBody(&myBodyDef);


		b2PolygonShape polygonShape;

		b2FixtureDef myFixtureDef;
		myFixtureDef.shape = &polygonShape;

		polygonShape.SetAsBox(m_hx, m_hy, m_middlepos, 0);//ground
		staticBody->CreateFixture(&myFixtureDef);

	};
	~WallPhysics() {};

};