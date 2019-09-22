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
	b2World m_b2world = b2World(b2Vec2 (0.0f, 0.0f));


	WallPhysics(b2World* world, b2Vec2 middlepos, float32 hx, float32 hy, float32 angle, b2BodyType type)
	{
		if (type == b2_staticBody) //static
		{
			m_body = NULL;
			m_middlepos = middlepos;
			m_hx = hx;
			m_hy = hy;
			m_angle = angle;
			m_type = type;
			m_b2world = *world;
			


			b2BodyDef myBodyDef;
			myBodyDef.type = type;
			myBodyDef.position.Set(hx, hy);
			m_body = world->CreateBody(&myBodyDef);


			b2PolygonShape polygonShape;
			polygonShape.SetAsBox(m_hx, m_hy, m_middlepos, 0);//ground


			b2FixtureDef myFixtureDef;
			myFixtureDef.shape = &polygonShape;

			m_body->CreateFixture(&myFixtureDef);

		}

		if (type == b2_dynamicBody) // dynamic
		{
			m_body = NULL;
			m_middlepos = middlepos;
			m_hx = hx;
			m_hy = hy;
			m_angle = angle;
			m_type = type;
			m_b2world = *world;


			b2BodyDef myBodyDef;
			myBodyDef.type = type;
			myBodyDef.position.Set(hx, hy);
			m_body = world->CreateBody(&myBodyDef);


			b2PolygonShape polygonShape;
			polygonShape.SetAsBox(m_hx/2.5f, m_hy/2.5f, m_middlepos, 0);


			b2FixtureDef myFixtureDef;
			myFixtureDef.shape = &polygonShape;
			myFixtureDef.density = 1;

			m_body->CreateFixture(&myFixtureDef);
			m_body->SetLinearVelocity( b2Vec2(1.0f, 1.0f) );


		}


	};
	~WallPhysics() {};

};