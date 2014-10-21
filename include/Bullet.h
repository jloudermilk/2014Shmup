#ifndef _Bullet_H_
#define _Bullet_H_
#include "Entity.h"
class Bullet :
	public Entity
{
public:
	

	Bullet(const char* a_path, float a_width, float a_height);
	~Bullet();

	int health;
	int layer;

	void Update(float a_deltaTime);
	void Draw();
	void Init(Vector2 a_pos, Vector2 a_vel, float a_speed,float a_radius, int a_health);
	void Spawn(Vector2 a_pos, Vector2 a_vel, float a_speed, int a_health);

};

#endif 