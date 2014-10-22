#ifndef _Player_H_
#define _Player_H_
#include "Entity.h"
#include "Utility.h"
#include "BulletManager.h"
class Player :
	public Entity
{
public:
	Player();
	~Player();
	Player(const char* a_path, float a_width, float a_height);
	void Init(Vector2 a_pos, Vector2 speed, float radius, int health);

	void Update(float a_deltaTime);
	void Draw();
	void Input();
	void Shoot();
	void PowerLevel(int a_powerLevel);
	

	
private:
	int health;
	int powerLevel;
	float fireDelay;
	float fireTime;
	float bulletSpeed;

};

#endif