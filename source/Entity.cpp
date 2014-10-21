#include "Entity.h"


Entity::Entity()
{
	pos.x = 0;
	pos.y = 0;
	width = height = 1;
	velocity = pos;
	speed = 1;
	alive = false;
	spriteID = 0;
}


Entity::~Entity()
{

}


