#include "AIE.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

int main( int argc, char* argv[] )
{	
    Initialise(SCREENWIDTH, SCREEHEIGHT, false, "2014 Shmup");
	std::vector<Entity*> gameObjects;

    SetBackgroundColour(SColour(0, 0, 0, 255));
	Enemy* testy = new Enemy("./images/Enemy1.png", 32, 32);
	testy->Init(Vector2(SCREENWIDTH/2, 500), Vector2(0, 0), 10.f, 3,DOWN);
	Player* player = new Player("./images/Player.png", 32, 32);
	player->Init(Vector2(100.f, 100.f), Vector2(0, 0), 10.f, 1);
	BulletManager::Init();
	
	gameObjects.push_back(player);
	gameObjects.push_back(testy);

	float deltaTime;
    //Game Loop
    do
    {

		deltaTime = GetDeltaTime();
		BulletManager::Update(deltaTime);
		for each (Entity* entity in gameObjects)
		{
			if (entity->alive)
			{
			entity->Update(deltaTime);
			entity->Draw();
			}
		}
        ClearScreen();

    } while(!FrameworkUpdate());

	for  (int i = 0;  i < gameObjects.size();  i++)
	{
		delete gameObjects[i];
	}

    Shutdown();

    return 0;
}
