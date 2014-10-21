#ifndef _Bullet_Manager_H_
#define _Bullet_Manager_H_

#include "Bullet.h"
#include <vector>

class BulletManager
{
public:
	BulletManager()
	{
		

	};
	~BulletManager();
	static void Init()
	{
		for (int i = 0; i < 100; i++)
		{
			playerBullets.emplace_back(new Bullet("./images/BulletR3.png", 8, 8));
		}

	}

	static bool SetBullet(TYPE type, Vector2 a_pos, Vector2 a_velocity, float a_speed,int a_health)
	{

		std::vector<Bullet*> temp = GetBulletList(type);
		for each (Bullet* bullet in temp)
		{
			if (!bullet->alive)
			{
				bullet->Spawn(a_pos, a_velocity, a_speed, a_health);
				return true;
			}
		}
		return false;
	}
	static std::vector<Bullet*> GetBulletList(TYPE type)
	{
		if (type == PLAYER)
		{
			return playerBullets;
		}
		return enemyBullets;
	}
	static void Update(float a_deltaTime)
	{
		for each (Bullet* bullet in playerBullets)
		{
			if (bullet->alive){
				bullet->Update(a_deltaTime);
				bullet->Draw();
			}
		}
	}

	static std::vector<Bullet*> playerBullets;
	static std::vector<Bullet*> enemyBullets;

};



#endif