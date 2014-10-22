#pragma once
#include "Entity.h"
#include "BulletManager.h"
class Enemy :
	public Entity
{
public:
	Enemy();
	~Enemy();

	Enemy(const char* a_path, float a_width, float a_height);
	void Init(Vector2 a_pos, Vector2 speed, float radius, int health, ENEMYTYPE a_type);

	void Update(float a_deltaTime);
	void Draw();

	void MoveEnemy();
	void Shoot();

	int type;
	int health;
	float fireDelay;
	float fireTime;

	float lifeTime;
	float bulletSpeed;

	Vector2 direction;

};

