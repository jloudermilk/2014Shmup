#ifndef _Entity_H_
#define _Entity_H_
#include "Maths.h"
#include "CircleCollider.h"
#include "AIE.h"
class Entity
{
public:
	Vector2 pos;
	float width, height;
	Vector2 velocity;
	float speed;
	bool alive;
	unsigned int spriteID;

	CircleCollider col; 

	

	Entity();
	~Entity();

	virtual void Update(float a_deltaTime) = 0;
	virtual void Draw() = 0;
	


};
#endif

