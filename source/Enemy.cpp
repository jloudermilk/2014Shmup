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
	fireDelay = 5;
	fireTime = 0;
	alive = true;
	direction = Vector2(0, -1);
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
	float angle = pos.Dot(playerPos );
	//angle *= 57.2957795;
	float x = cosf(angle);
	float y = sinf(angle);
	Vector2 dir = Vector2(x, y);
	dir *= direction;
 	BulletManager::SetBullet(ENEMY, pos, dir, 200, 1, 0);

}
void Enemy::Update(float a_deltaTime)
{
	pos += velocity * speed * a_deltaTime;
	MoveSprite(spriteID, pos.x, pos.y);
	fireTime += a_deltaTime;
	lifeTime += a_deltaTime;

	if (fireTime > fireDelay){
		Shoot();
		fireTime = 0;
	}
}
void Enemy::Draw()
{
	DrawSprite(spriteID);
}
