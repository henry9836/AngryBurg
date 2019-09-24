#include "GameObject.h"

GameObject::GameObject()
{
}

RenderObject::RenderObject()
{
}

RenderObject::~RenderObject()
{
}

void RenderObject::Render(Transform* _transform)
{
	glUseProgram(this->shaderProgram);

	//Binding the array
	glBindVertexArray(this->VAO);

	//Setting back face culling
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);

	//Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Setting and binding the correct texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture);

	//Sending the texture to the GPU via uniform
	glUniform1i(glGetUniformLocation(this->shaderProgram, "tex"), 0);

	//Translating the cube (x,y,z)
	glm::mat4 TranslationMatrix = glm::translate(glm::mat4(), _transform->position);

	//Y Rotation
	glm::mat4 RotateY =
		glm::rotate(
			glm::mat4(),
			glm::radians(_transform->rotation.y),
			glm::vec3(0.0f, 1.0f, 0.0f)
		);

	//X Rotation
	glm::mat4 RotateX =
		glm::rotate(
			glm::mat4(),
			glm::radians(_transform->rotation.x),
			glm::vec3(1.0f, 0.0f, 0.0f)
		);
	//Z Rotation
	glm::mat4 RotateZ =
		glm::rotate(
			glm::mat4(),
			glm::radians(_transform->rotation.z),
			glm::vec3(0.0f, 0.0f, 1.0f)
		);

	glm::mat4 RotationMatrix = RotateX * RotateY * RotateZ;
	glm::mat4 ScaleMatrix = glm::scale(glm::mat4(), _transform->scale);

	glm::mat4 ModelMatrix = TranslationMatrix * RotationMatrix * ScaleMatrix;

	//glm::mat4 MVP = game->camera.getMVP(this->cardData.Pos, this->cardData.Scale, glm::mat4()) * cardData.ModelMatrix;
	//auto MVP = game->camera.getVP() * cardData.ModelMatrix;
	int halfw = (int)game->ScreenSize.x / 2;
	int halfh = (int)game->ScreenSize.y / 2;
	// auto MVP = glm::ortho<float>((float)-halfw, (float)halfw, (float)-halfh, (float)halfh, 0.1f, 1000.0f) * glm::translate(glm::mat4(), glm::vec3(0, 0, -1)) * ModelMatrix;
	auto MVP = glm::ortho<float>((float)-halfw, (float)halfw, (float)-halfh, (float)halfh, 0.1f, 1000.0f) * glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 2.0f), glm::vec3(0.0f, 1.0f, 0.0f)) * ModelMatrix;

	glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, "MVP"), 1, GL_FALSE, glm::value_ptr(MVP));
	glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));
	//Drawing the entity
	glDrawElements(GL_TRIANGLES, this->indiceCount, GL_UNSIGNED_INT, 0);

	//Disabling backface culling
	glDisable(GL_CULL_FACE);

	glDisable(GL_BLEND);

	//Clearing the vertex array
	glBindVertexArray(0);
	glUseProgram(0);
}

void RenderObject::SetTexture(GLuint _tex)
{
	this->texture = _tex;
}

void RenderObject::SetShader(GLuint _shader)
{
	this->shaderProgram = _shader;
}

void TickObject::Tick(float deltaTime, GameObject* _gameObject)
{

}

BasicObject::BasicObject()
{
}

BasicObject::BasicObject(RenderClass* r, TickClass* t, Transform _trans, string _name)
{
	Console_OutputLog(to_wstring("Creating Basic Object: " + _name), LOGINFO);
	_r = r;
	_t = t;
	transform = _trans;
	name = _name;
}

BasicObject::~BasicObject()
{
}

WallObject::WallObject()
{
}

WallObject::WallObject(RenderClass* r, TickClass* t, Transform _trans, string _name, WallPhysics* _wall)
{
	Console_OutputLog(to_wstring("Creating Wall Object: " + _name), LOGINFO);
	_r = r;
	_t = new TickWall();
	transform = _trans;
	name = _name;
	wall = _wall;
	transform.position = glm::vec3(wall->m_middlepos.x, wall->m_middlepos.y, 0.0f);
	transform.rotation = glm::vec3(0.0f,0.0f , wall->m_angle);
	transform.scale = glm::vec3(wall->m_hx, wall->m_hy, 0.0f);
}

WallObject::~WallObject()
{
}

void TickWall::Tick(float deltaTime, GameObject* _gameObject)
{

	WallPhysics* wall = _gameObject->wall;
	float32 scalar = 64.0f;

	if (wall->m_type == b2_dynamicBody)
	{

		//wall->m_body->ApplyLinearImpulse(b2Vec2(0.001f, 1.1f), wall->m_body->GetWorldCenter(), true);
		if (wall->wallType == WallPhysics::BIRD)
		{
			wall->m_body->SetAngularVelocity(10.0f);
		}

		float32 temprot =  wall->m_body->GetAngle();
		glm::vec3 temppos = glm::vec3(wall->m_body->GetPosition().x, wall->m_body->GetPosition().y, 0.1f);

		

		_gameObject->GetTransform().position = glm::vec3(temppos.x * scalar, temppos.y * scalar, 0.5f);
		_gameObject->GetTransform().rotation = glm::vec3(0.0f, 0.0f, glm::degrees(temprot));
		_gameObject->transform.scale = glm::vec3(wall->m_hx * scalar, wall->m_hy * scalar, 1.0f);

		//Console_OutputLog(to_wstring("Object " + _gameObject->name + ": ") + to_wstring(_gameObject->GetTransform().position.x) + L" " + to_wstring(_gameObject->GetTransform().position.y) + L"|" + to_wstring(wall->m_body->GetPosition().x) + L" " + to_wstring(wall->m_body->GetPosition().y), LOGINFO);

	}
	else if (wall->m_type == b2_staticBody)
	{
		float32 temprot = wall->m_body->GetAngle();
		glm::vec3 temppos = glm::vec3(wall->m_body->GetPosition().x, wall->m_body->GetPosition().y, 0.1f);

		_gameObject->GetTransform().position = glm::vec3(temppos.x * scalar, temppos.y * scalar, 0.5f);
		_gameObject->GetTransform().rotation = glm::vec3(0.0f, 0.0f, temprot);
		_gameObject->transform.scale = glm::vec3(wall->m_hx * scalar, wall->m_hy * scalar, 1.0f);
	}

}

RenderText::~RenderText()
{
}

void RenderText::Render(Transform* _transform)
{
	text->Render();
}

BirdObject::BirdObject()
{
}

BirdObject::BirdObject(RenderClass* r, TickClass* t, Transform _trans, string _name, WallPhysics* _wall, BIRDTYPE _bird, Game* _game)
{
	Console_OutputLog(to_wstring("Creating Bird Object: " + _name), LOGINFO);
	_r = r;
	_t = t;
	transform = _trans;
	name = _name;
	wall = _wall;
	transform.position = glm::vec3(wall->m_middlepos.x, wall->m_middlepos.y, 0.0f);
	transform.rotation = glm::vec3(0.0f, wall->m_angle, 0.0f);
	transform.scale = glm::vec3(wall->m_hx, wall->m_hy, 0.0f);
	Birdtype = _bird;
	game = _game;
}

BirdObject::~BirdObject()
{
	deathMark = true;
	//remove from all gameobject lists
	for (size_t i = 0; i < game->gameObjects.size(); i++)
	{
		if (game->gameObjects.at(i)->deathMark) {
			game->gameObjects.erase(game->gameObjects.begin() + i);
			i--;
		}
	}

	for (size_t i = 0; i < game->lvlOneObjects.size(); i++)
	{
		if (game->gameObjects.at(i)->deathMark) {
			game->gameObjects.erase(game->gameObjects.begin() + i);
			i--;
		}
	}

	for (size_t i = 0; i < game->lvlTwoObjects.size(); i++)
	{
		if (game->gameObjects.at(i)->deathMark) {
			game->gameObjects.erase(game->gameObjects.begin() + i);
			i--;
		}
	}

	//Delete references

	delete game;
	delete wall;

}

PigObject::PigObject()
{
}

PigObject::PigObject(RenderClass* r, TickClass* t, Transform _trans, string _name, WallPhysics* _wall, Game* _game)
{
	Console_OutputLog(to_wstring("Creating Pig Object: " + _name), LOGINFO);
	_r = r;
	_t = t;
	transform = _trans;
	name = _name;
	wall = _wall;
	transform.position = glm::vec3(wall->m_middlepos.x, wall->m_middlepos.y, 0.0f);
	transform.rotation = glm::vec3(0.0f, wall->m_angle, 0.0f);
	transform.scale = glm::vec3(wall->m_hx, wall->m_hy, 0.0f);
	game = _game;
}

PigObject::~PigObject()
{
	deathMark = true;
	//remove from all gameobject lists
	for (size_t i = 0; i < game->gameObjects.size(); i++)
	{
		if (game->gameObjects.at(i)->deathMark) {
			game->gameObjects.erase(game->gameObjects.begin() + i);
			i--;
		}
	}

	for (size_t i = 0; i < game->lvlOneObjects.size(); i++)
	{
		if (game->gameObjects.at(i)->deathMark) {
			game->gameObjects.erase(game->gameObjects.begin() + i);
			i--;
		}
	}

	for (size_t i = 0; i < game->lvlTwoObjects.size(); i++)
	{
		if (game->gameObjects.at(i)->deathMark) {
			game->gameObjects.erase(game->gameObjects.begin() + i);
			i--;
		}
	}

	//Delete references

	delete game;
	delete wall;
}

void TickBird::Tick(float deltaTime, BirdObject* _gameObject)
{

}

void TickPig::Tick(float deltaTime, PigObject* _gameObject)
{
	if (_gameObject->health <= 0) {
		_gameObject->~PigObject();
	}
}
