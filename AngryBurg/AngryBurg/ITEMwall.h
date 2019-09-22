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
	b2BodyType m_type;


	WallPhysics(b2World* world, b2Vec2 middlepos, float32 hx, float32 hy, float32 angle, b2BodyType type)
	{
		if (type == b2_staticBody)
		{
			m_body = NULL;
			m_middlepos = middlepos;
			m_hx = hx;
			m_hy = hy;
			m_angle = angle;
			m_type = type;


			b2BodyDef myBodyDef;
			myBodyDef.type = type;
			myBodyDef.position.Set(0, 0);
			b2Body* staticBody = world->CreateBody(&myBodyDef);


			b2PolygonShape polygonShape;
			polygonShape.SetAsBox(m_hx, m_hy, m_middlepos, 0);//ground


			b2FixtureDef myFixtureDef;
			myFixtureDef.shape = &polygonShape;

			staticBody->CreateFixture(&myFixtureDef);

		}

		if (type == b2_dynamicBody)
		{
			m_body = NULL;
			m_middlepos = middlepos;
			m_hx = hx;
			m_hy = hy;
			m_angle = angle;
			m_type = type;


			b2BodyDef myBodyDef;
			myBodyDef.type = type;
			myBodyDef.position.Set(0, 0);
			b2Body* dynamicBody = world->CreateBody(&myBodyDef);


			b2PolygonShape polygonShape;
			polygonShape.SetAsBox(m_hx, m_hy, m_middlepos, 0);


			b2FixtureDef myFixtureDef;
			myFixtureDef.shape = &polygonShape;
			myFixtureDef.density = 1;

			dynamicBody->CreateFixture(&myFixtureDef);

			dynamicBody->SetAngularVelocity(-90 * 0.0174532925199432957f);

		}


	};
	~WallPhysics() {};

};