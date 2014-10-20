#include "AIE.h"
#include "Player.h"
#include <iostream>
#include <vector>

int main( int argc, char* argv[] )
{	
    Initialise(800, 600, false, "2014 Shmup");
	std::vector<Entity*> gameObjects;

    SetBackgroundColour(SColour(0, 0, 0, 255));
	Player * player = new Player("./images/Player.png", 32, 32);
	player->Init(Vector2(100.f, 100.f), Vector2(0, 0), 10.f, 1);

	
	gameObjects.push_back(player);

	float deltaTime;
    //Game Loop
    do
    {
		deltaTime = GetDeltaTime();
		for each (Entity* var in gameObjects)
		{
			var->Update(deltaTime);
			var->Draw();
		}

        ClearScreen();

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}
