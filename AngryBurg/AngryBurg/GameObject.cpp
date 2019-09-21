#include "GameObject.h"

GameObject::GameObject()
{
}

RenderObject::RenderObject()
{
}

void RenderObject::Render(Transform* _transform)
{
}

void RenderObject::SetTexture(GLuint _tex)
{
}

void RenderObject::SetShader(GLuint _shader)
{
}

void TickObject::Tick(float deltaTime, GameObject* _gameObject)
{
}

BasicObject::BasicObject()
{
}

BasicObject::BasicObject(RenderClass* r, TickClass* t, Transform _trans, string _name)
{
}

BasicObject::~BasicObject()
{
}
