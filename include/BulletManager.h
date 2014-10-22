#ifndef _Bullet_Manager_H_
#define _Bullet_Manager_H_

#include "Bullet.h"
#include <vector>

class BulletManager
{
public:
	static int bulletListSize;
	BulletManager()
	{
		
	};
	~BulletManager()
	{
		for (int i = 0; i < playerBullets.size(); i++)
		{
			delete playerBullets[i];
		}
		for (int i = 0; i < enemyBullets.size(); i++)
		{
			delete enemyBullets[i];
		}
	}
	static void Init()
	{
		for (int i = 0; i < bulletListSize; i++)
		{
			playerBullets.emplace_back(new Bullet("./images/BulletR3.png", 4, 8));
		}
		for (int i = 0; i < bulletListSize; i++)
		{
			playerBullets.emplace_back(new Bullet("./images/BulletR2.png", 6, 8));
		}
		for (int i = 0; i < bulletListSize; i++)
		{
			enemyBullets.emplace_back(new Bullet("./images/EnemyBullet1.png", 8, 8));
		}
	
	

	}

	static bool SetBullet(TYPE type, Vector2 a_pos, Vector2 a_velocity, float a_speed,int a_health,int a_powerLevel)
	{

		Bullet* bullet;
		if (type == PLAYER){
			int length = playerBullets.size();
			if (a_powerLevel < 3){
				length -= bulletListSize;
				for (int i = 0; i < length; i++)
				{
					bullet = playerBullets[i];
					if (!bullet->alive)
					{
						bullet->Spawn(a_pos, a_velocity, a_speed, a_health);
					
						return true;
					}
				}
			}
			if (a_powerLevel >= 3){

				for (int i = bulletListSize; i < length; i++)
				{
					bullet = playerBullets[i];
					if (!bullet->alive)
					{
						bullet->Spawn(a_pos, a_velocity, a_speed, a_health);
						
						return true;
					}
				}
			}
		}
		else
		{
			int length = enemyBullets.size();
				for (int i = 0; i < length; i++)
				{
					bullet = enemyBullets[i];
					if (!bullet->alive)
					{
						bullet->Spawn(a_pos, a_velocity, a_speed, a_health);
					
						return true;
					}
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
		Bullet* bullet;
		int length = GetBulletList(PLAYER).size();
		for (int i = 0; i < length; i++)
		{
			bullet = GetBulletList(PLAYER)[i];
			if (bullet->alive){
				bullet->Update(a_deltaTime);
				bullet->Draw();
			}
	
		}
		length = GetBulletList(ENEMY).size();
		for (int i = 0; i < length; i++)
		{
			bullet = GetBulletList(ENEMY)[i];
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