#pragma once
#include <iostream>
#include <windows.h>
#include <Box2D/Box2D.h>
#include "ConsoleController.h"
#include "ITEMwall.h"
#include "Util.h"

class Listner : public b2ContactListener
{

public:
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
	{
		if (contact)
		{
			std::wcout << contact->GetFixtureA()->GetBody()->GetID() << " " << contact->GetFixtureB()->GetBody()->GetID() << endl;

			if (contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::BIRD && contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::GROUND) {
				contact->GetFixtureA()->GetBody()->MarkForDeath(true);
				contact->GetFixtureB()->GetBody()->MarkForDeath(true);
			}
			else if (contact->GetFixtureB()->GetBody()->GetID() == PHYSICSTAG::BIRD && contact->GetFixtureA()->GetBody()->GetID() == PHYSICSTAG::GROUND) {
				contact->GetFixtureA()->GetBody()->MarkForDeath(true);
				contact->GetFixtureB()->GetBody()->MarkForDeath(true);
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
	std::vector<WallPhysics*>WallsCollide;
	b2World* m_world = nullptr;

	b2World* m_world2;
	
private:
	Listner* contactListner;
	
};
