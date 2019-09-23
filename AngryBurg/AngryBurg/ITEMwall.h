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
			m_middlepos = (1 / 64.0f) * middlepos;
			m_hx = hx / 64.0f;
			m_hy = hy / 64.0f;
			m_angle = angle;
			m_type = type;
			m_b2world = *world;
			


			b2BodyDef myBodyDef;
			myBodyDef.type = type;
			myBodyDef.position.Set(m_hx, m_hy);
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
			m_middlepos = (1 / 64.0f) * middlepos;
			m_hx = hx / 64.0f;
			m_hy = hy / 64.0f;
			m_angle = angle;
			m_type = type;
			m_b2world = *world;


			b2BodyDef myBodyDef;
			myBodyDef.type = type;
			myBodyDef.position.Set(m_hx, m_hy);
			m_body = world->CreateBody(&myBodyDef);


			b2PolygonShape polygonShape;
			float32 scaler = 1 / 64.0f;
			polygonShape.SetAsBox(m_hx*scaler, m_hy * scaler, m_middlepos, 0);


			b2FixtureDef myFixtureDef;
			myFixtureDef.shape = &polygonShape;
			myFixtureDef.density = 1;

			m_body->CreateFixture(&myFixtureDef);


		}


	};
	~WallPhysics() {};

};