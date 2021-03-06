#pragma once

#include "Util.h"
#include "GameObject.h"
#include "GameManager.h"
#include "Physics.h"


class GameObject;
class CTextLabel;

class RenderClass {
public:
	virtual void Render(Transform* _transform) = 0;
	virtual void SetTexture(GLuint _tex) = 0;
	virtual void SetShader(GLuint _shader) = 0;
};

class NoRender : public RenderClass {

};

class RenderObject : public RenderClass {
public:
	RenderObject();
	RenderObject(std::shared_ptr<MESH> _mesh, GLuint _texture, Game* _game, GLuint _shaderProgram) : VAO(_mesh->VAO), indiceCount(_mesh->IndicesCount), texture(_texture), game(_game), shaderProgram(_shaderProgram) {};
	~RenderObject();

	virtual void Render(Transform* _transform);
	virtual void SetTexture(GLuint _tex);
	virtual void SetShader(GLuint _shader);

	GLuint VAO;
	unsigned int indiceCount;
	GLuint texture;
	Game* game = nullptr;
	GLuint shaderProgram;

};

class RenderText : public RenderClass {
public:
	RenderText(CTextLabel* _text) : text(_text) {};
	~RenderText();

	virtual void Render(Transform* _transform);
	virtual void SetTexture(GLuint _tex) {};
	virtual void SetShader(GLuint _shader) {};

	CTextLabel* text;
};


class TickClass {
public:
	virtual void Tick(float deltaTime, GameObject* _gameObject) = 0;
};

class IdleTick : public TickClass {
public:
	virtual void Tick(float deltaTime, GameObject* _gameObject) { return; };
};

class TickObject : public TickClass {
public:
	virtual void Tick(float deltaTime, GameObject* _gameObject);
};



class GameObject {
public:

	GameObject();
	GameObject(RenderClass* r, TickClass* t, Transform _trans, string _name) : _r(r), _t(t), transform(_trans), name(_name) { Console_OutputLog(to_wstring("Creating GameObject: " + _name), LOGINFO); };

	virtual void Tick(float deltaTime, GameObject* _gameObject) { _t->Tick(deltaTime, _gameObject); };
	virtual void Render() { _r->Render(&transform); };

	virtual void SetTexture(GLuint _tex) { _r->SetTexture(_tex); };
	virtual void SetShader(GLuint _shader) { _r->SetTexture(_shader); };

	Transform& GetTransform() { return transform; };
	
	WallPhysics* wall = nullptr;


	bool deathMark = false;
	Transform transform;
	string name;
protected:
	
	RenderClass* _r = nullptr;
	TickClass* _t = nullptr;
	
};

class BasicObject : public GameObject {
public:
	BasicObject();
	BasicObject(RenderClass* r, TickClass* t, Transform _trans, string _name);
	~BasicObject();

	virtual void Tick(float deltaTime, GameObject* _gameObject) { _t->Tick(deltaTime, _gameObject); };
	virtual void Render() { _r->Render(&transform); };

	virtual void SetTexture(GLuint _tex) { _r->SetTexture(_tex); };
	virtual void SetShader(GLuint _shader) { _r->SetTexture(_shader); };

	
};

class WallObject : public GameObject {
public:
	WallObject();
	WallObject(RenderClass* r, TickClass* t, Transform _trans, string _name, WallPhysics* _wall);
	~WallObject();

	virtual void Tick(float deltaTime, GameObject* _gameObject) { _t->Tick(deltaTime, _gameObject); };
	virtual void Render() { _r->Render(&transform); };

	virtual void SetTexture(GLuint _tex) { _r->SetTexture(_tex); };
	virtual void SetShader(GLuint _shader) { _r->SetTexture(_shader); };
	
};


class TickWall : public TickClass {
public:
	virtual void Tick(float deltaTime, GameObject* _gameObject);
};

class BirdObject : public GameObject {
public:
	enum BIRDTYPE {
		DEFAULT
	};

	BirdObject();
	BirdObject(RenderClass* r, TickClass* t, Transform _trans, string _name, WallPhysics* _wall, BIRDTYPE _bird, Game* _game);
	~BirdObject();


	virtual void Tick(float deltaTime, GameObject* _gameObject) { _t->Tick(deltaTime, _gameObject); };
	virtual void Render() { _r->Render(&transform); };

	virtual void SetTexture(GLuint _tex) { _r->SetTexture(_tex); };
	virtual void SetShader(GLuint _shader) { _r->SetTexture(_shader); };
	WallPhysics* wall = nullptr;
	Game* game = nullptr;
	BIRDTYPE Birdtype = DEFAULT;
};

class TickBird : public TickClass {
public:
	virtual void Tick(float deltaTime, BirdObject* _gameObject);
};

class PigObject : public GameObject {
public:
	PigObject();
	PigObject(RenderClass* r, TickClass* t, Transform _trans, string _name, WallPhysics* _wall, Game* _game);
	~PigObject();

	virtual void Tick(float deltaTime, GameObject* _gameObject) { _t->Tick(deltaTime, _gameObject); };
	virtual void Render() { _r->Render(&transform); };

	virtual void SetTexture(GLuint _tex) { _r->SetTexture(_tex); };
	virtual void SetShader(GLuint _shader) { _r->SetTexture(_shader); };
	WallPhysics* wall = nullptr;
	Game* game = nullptr;
	float health = 10;
};

class TickPig : public TickClass {
public:
	virtual void Tick(float deltaTime, PigObject* _gameObject);
};



#include "TextManager.h"