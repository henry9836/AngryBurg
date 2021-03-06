#pragma once
#include "Physics.h"
#include "Util.h"

class WallPhysics {
public:

	//class member variables
	b2Body* m_body = nullptr;
	b2Vec2 m_middlepos;
	float32 m_hx;
	float32 m_hy;
	float32 m_angle;
	b2BodyType m_type;
	b2World m_b2world = b2World(b2Vec2 (0.0f, 0.0f));
	Scenes assignedScene = GLOBAL;
	PHYSICSTAG wallType = DEFAULT;

	b2Vec2 startPos = b2Vec2(0,0);
	float32 startAngle = 0;

	WallPhysics(b2World* world, b2Vec2 middlepos, float32 hx, float32 hy, float32 angle, b2BodyType type, Scenes _scene, PHYSICSTAG _wallType)
	{
		assignedScene = _scene;
		wallType = _wallType;
		startAngle = angle;

		if (type == b2_staticBody) //static
		{
			m_body = NULL;
			m_middlepos = (1 / 64.0f) * middlepos;
			m_hx = hx / 64.0f;
			m_hy = hy / 64.0f;
			m_angle = angle;
			m_type = type;
			m_b2world = *world;
			startPos = m_middlepos;

			b2BodyDef myBodyDef;
			myBodyDef.type = type;
			myBodyDef.position.Set(m_middlepos.x, m_middlepos.y);
			m_body = world->CreateBody(&myBodyDef);


			b2PolygonShape polygonShape;
			polygonShape.SetAsBox(m_hx, m_hy);//, m_middlepos, 0);//ground


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
			startPos = m_middlepos;

			b2BodyDef myBodyDef;
			myBodyDef.type = type;
			myBodyDef.position.Set(m_middlepos.x, m_middlepos.y);
			m_body = world->CreateBody(&myBodyDef);


			b2PolygonShape polygonShape;
			float32 scaler = 1 / 64.0f;
			polygonShape.SetAsBox(m_hx, m_hy);// , m_middlepos, 0);


			b2FixtureDef myFixtureDef;
			myFixtureDef.shape = &polygonShape;
			myFixtureDef.density = 1;

			m_body->CreateFixture(&myFixtureDef);


		}
		m_body->SetID(_wallType);

	};

	void Reset();

};

