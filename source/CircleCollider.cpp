#include "CircleCollider.h"



CircleCollider::CircleCollider()
{
	radius = 0;
	center.x = 0;
	center.y = 0;
}


CircleCollider::~CircleCollider()
{
}

bool CircleCollider::CheckCollision(CircleCollider &other)
{
	if (center.Distance(other.center) < radius)
	{
		return true;
	}
	return false;
}
