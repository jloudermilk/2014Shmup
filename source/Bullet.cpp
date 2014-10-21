#include "Bullet.h"



Bullet::Bullet()
{
}
Bullet::~Bullet()
{
}
Bullet::Bullet(const char* a_path, float a_width, float a_height)
{
	spriteID = CreateSprite(a_path, a_width, a_height, true);
	width = a_width;
	height = a_height;
	Init(Vector2(0, 0), Vector2(0, 0), 200, 4, 1);
}


void Bullet::Init(Vector2 a_pos, Vector2 a_vel, float a_speed, float a_radius, int a_health)
{
	pos = a_pos;
	velocity = a_vel;
	speed = a_speed;
	col.radius = a_radius;
	health = a_health;
}

void Bullet::Spawn(Vector2 a_pos, Vector2 a_vel, float a_speed, int a_health)
{
	pos = a_pos;
	velocity = a_vel;
	speed = a_speed;

	health = a_health;
	alive = true;
}

void Bullet::Update(float a_deltaTime)
{
	pos += velocity * speed * a_deltaTime;
	MoveSprite(spriteID, pos.x, pos.y);

	if (pos.y > SCREEHEIGHT||pos.y <0||pos.x > SCREENWIDTH||pos.x < 0)
		alive = false;
}
void Bullet::Draw()
{
	DrawSprite(spriteID);
}