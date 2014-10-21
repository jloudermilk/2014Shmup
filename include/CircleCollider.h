#ifndef _Circle_Collider_H_
#define _Circle_Collider_H_
#include "Utility.h"
class CircleCollider
{
public:
	float radius;
	Vector2 center;
	CircleCollider();
	~CircleCollider();

	bool CheckCollision(CircleCollider &other);
};

#endif