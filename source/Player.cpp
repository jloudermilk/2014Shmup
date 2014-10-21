#include "Player.h"


Player::Player()
{
}

Player::Player(const char* a_path, float a_width, float a_height)
{
	spriteID = CreateSprite(a_path, a_width, a_height, true);
	width = a_width;
	height = a_height;
	fireDelay = .1f;
	fireTime = 0;
	powerLevel = 0;
}

Player::~Player()
{
}

void Player::Init(Vector2 a_pos, Vector2 a_vel, float a_radius, int a_health)
{
	pos = a_pos;
	velocity = a_vel;
	speed = 150;
	bulletSpeed = 500;
	col.radius = a_radius;
	health = a_health;
	alive = true;
}
void Player::Input()
{
	velocity.Zero();

	if (IsKeyDown(GLFW_KEY_W))
	{
		velocity.y = 1;
	}
	if (IsKeyDown(GLFW_KEY_S))
	{
		velocity.y = -1;
	}
	if (IsKeyDown(GLFW_KEY_A))
	{
		velocity.x = -1;
	}
	if (IsKeyDown(GLFW_KEY_D))
	{
		velocity.x = 1;
	}
	if (IsKeyDown(GLFW_KEY_P))
	{
		if (fireTime >= fireDelay){
			Shoot();
			fireTime = 0;
		}
	}
	if (IsKeyDown(GLFW_KEY_1))
	{
		powerLevel = 0;
	}
	if (IsKeyDown(GLFW_KEY_2))
	{
		powerLevel = 1;
	}
	if (IsKeyDown(GLFW_KEY_3))
	{
		powerLevel = 2;
	}
	if (IsKeyDown(GLFW_KEY_4))
	{
		powerLevel = 3;
	}

}

void Player::Shoot()
{
	
		switch (powerLevel)
		{
		case 0:
			BulletManager::SetBullet(PLAYER, pos, Vector2(0, 1), bulletSpeed, 1, powerLevel);
			break;
		case 1:
			BulletManager::SetBullet(PLAYER, pos + Vector2(8, 0), Vector2(0, 1), bulletSpeed, 1, powerLevel);
			BulletManager::SetBullet(PLAYER, pos + Vector2(-8, 0), Vector2(0, 1), bulletSpeed, 1, powerLevel);
			break;
		case 2:
			BulletManager::SetBullet(PLAYER, pos + Vector2(8, 0), Vector2(0, 1), bulletSpeed, 1, powerLevel);
			BulletManager::SetBullet(PLAYER, pos + Vector2(-8, 0), Vector2(0, 1), bulletSpeed, 1, powerLevel);
			BulletManager::SetBullet(PLAYER, pos + Vector2(8, 0), Vector2(.174f, .985f), bulletSpeed, 1, powerLevel);
			BulletManager::SetBullet(PLAYER, pos + Vector2(-8, 0), Vector2(-.174f, .985f), bulletSpeed, 1, powerLevel);
			break;
		case 3:
			BulletManager::SetBullet(PLAYER, pos + Vector2(8, 0), Vector2(0, 1), bulletSpeed, 2, powerLevel);
			BulletManager::SetBullet(PLAYER, pos + Vector2(-8, 0), Vector2(0, 1), bulletSpeed, 2, powerLevel);
			BulletManager::SetBullet(PLAYER, pos + Vector2(8, 0), Vector2(.174f, .985f), bulletSpeed, 2, powerLevel);
			BulletManager::SetBullet(PLAYER, pos + Vector2(-8, 0), Vector2(-.174f, .985f), bulletSpeed, 2, powerLevel);
			break;
		default:
			break;
		}
	
}
void Player::PowerLevel(int a_powerLevel)
{
	powerLevel += a_powerLevel;
	if (powerLevel < 0)
		powerLevel = 0;
}
void Player::Update(float a_deltaTime)
{
	fireTime += a_deltaTime;
	Input();
	pos += velocity * speed * a_deltaTime;
	MoveSprite(spriteID, pos.x,pos.y);
	playerPos = pos;
}
void Player::Draw()
{
	DrawSprite(spriteID);
}