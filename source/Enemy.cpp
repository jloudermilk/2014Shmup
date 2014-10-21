#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Enemy::Enemy(const char* a_path, float a_width, float a_height)
{
	spriteID = CreateSprite(a_path, a_width, a_height, true);
	width = a_width;
	height = a_height;
}
void Enemy::Init(Vector2 a_pos, Vector2 a_velocity, float a_radius, int a_health,ENEMYTYPE a_type)
{
	pos = a_pos;
	velocity = a_velocity;
	speed = 150;
	bulletSpeed = 500;
	col.radius = a_radius;
	health = a_health;
	type = a_type;
	fireDelay = 0;
	fireTime = 0;
	alive = true;
}

void Enemy::MoveEnemy()
{
	switch (type)
	{

	case DOWN:
		velocity = Vector2(0, -1);
		break;
	case DIAG:
		break;
	case LOOP:
		break;
	case WAVE:
		break;
	default:
		break;
	}
}
void Enemy::Shoot()
{
	
}
void Enemy::Update(float a_deltaTime)
{
	pos += velocity * speed * a_deltaTime;
	MoveSprite(spriteID, pos.x, pos.y);
	fireTime += a_deltaTime;

}
void Enemy::Draw()
{
	DrawSprite(spriteID);
}
