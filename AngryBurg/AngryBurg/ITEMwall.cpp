#include "ITEMwall.h"

void WallPhysics::Reset()
{
	wcout << "RESET" << endl;

	m_body->SetAngularVelocity(0);
	m_body->SetLinearVelocity(b2Vec2(0, 0));

	m_body->SetTransform(startPos, startAngle);
}
