#pragma once
#include "Entity.h"
class Bullet :
	public Entity
{
public:
	Bullet();
	~Bullet();
	void Update();
	void Draw();
};

