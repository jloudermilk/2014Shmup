#ifndef _Player_H_
#define _Player_H_
#include "Entity.h"
#include "BulletManager.h"
class Player :
	public Entity
{
public:
	Player();
	~Player();
	Player(const char* a_path, float a_width, float a_height);
	void Init(Vector2 a_pos, Vector2 speed, float radius, int health);

	virtual void Update(float a_deltaTime);
	virtual void Draw();
	void Input();
	void Shoot();

	
private:
	int health;
	float fireDelay;
	float fireTime;

};

#endif