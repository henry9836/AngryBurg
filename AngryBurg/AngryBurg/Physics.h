#pragma once
#include <iostream>
#include <windows.h>
#include <Box2D/Box2D.h>
#include "ConsoleController.h"
#include "Util.h"

class WallPhysics;

class Listner : public b2ContactListener
{

public:
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
	{
		if (contact)
		{
			float force = oldManifold->points[0].normalImpulse;
			if (force > 1.5f)
			{
				if (contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::BIRD && contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::PIG) {
					contact->GetFixtureB()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::BIRD && contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::PIG) {
					contact->GetFixtureA()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::DEFAULT && contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::PIG) {
					contact->GetFixtureA()->GetBody()->MarkForDeath(true);
					contact->GetFixtureB()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::DEFAULT && contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::PIG) {
					contact->GetFixtureA()->GetBody()->MarkForDeath(true);
					contact->GetFixtureB()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::DEFAULT && contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::BIRD) {
					contact->GetFixtureA()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::DEFAULT && contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::BIRD) {
					contact->GetFixtureB()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::DEFAULT && contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::DEFAULT) {
					contact->GetFixtureA()->GetBody()->MarkForDeath(true);
					contact->GetFixtureB()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::DEFAULT && contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::DEFAULT) {
					contact->GetFixtureB()->GetBody()->MarkForDeath(true);
					contact->GetFixtureA()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::PIG && contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::STRONGWALL) {
					contact->GetFixtureA()->GetBody()->MarkForDeath(true);
				}
				else if (contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::PIG && contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::STRONGWALL) {
					contact->GetFixtureB()->GetBody()->MarkForDeath(true);
				}
			}



		}


	};

};

class Physics
{
public:

	Physics();
	~Physics();

	void worldsetup();

	std::vector<WallPhysics*> Walls;
	std::vector<WallPhysics*> WallsCollide;
	b2World* m_world = nullptr;

	b2World* m_world2;
	
private:
	Listner* contactListner;
	
};

#include "ITEMwall.h"