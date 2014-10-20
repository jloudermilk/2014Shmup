#pragma once
#include "Entity.h"
class Enviroment :
	public Entity
{
public:
	Enviroment();
	~Enviroment();
	void Update();
	void Draw();
};

