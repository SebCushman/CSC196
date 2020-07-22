#include "core.h"
#include "Math/Math.h"
#include "Math/Random.h"
#include "Math/Transform.h"
#include "Graphics/Shape.h"
#include "Object/Actor.h"
#include "Actors/Player.h"
#include "Actors/Enemy.h"
#include "Object/Scene.h"
#include <iostream>
#include <string>
#include <direct.h>

//nc::Player player;
//nc::Enemy enemy;
nc::Scene scene;

float spawnTimer{ 0 };

bool Update(float dt){

	/*player.Update(dt);
	enemy.Update(dt);*/
	scene.Update(dt);

	spawnTimer += dt;
	/*if (spawnTimer >= 3.0f) {
		spawnTimer = 0;

		nc::Enemy* enemy = new nc::Enemy;
		enemy->Load("enemy.txt");
		enemy->SetTarget(scene.GetActor<nc::Player>());

		enemy->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0, 600) };
		scene.AddActor(enemy);
	}*/

	bool quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);
	return quit;
}

void Draw(Core::Graphics& graphics){
	
	/*player.Draw(graphics);
	enemy.Draw(graphics);*/
	scene.Draw(graphics);
}

int main(){
	
	/*player.Load("Player.txt");
	enemy.Load("enemy.txt");

	enemy.SetTarget(&player);*/

	scene.Startup();

	nc::Player* player = new nc::Player;
	player->Load("player.txt");
	scene.AddActor(player);

	for (size_t i = 0; i < 10; i++) {
		nc::Enemy* actor = new nc::Enemy;
		actor->Load("enemy.txt");

		nc::Enemy* enemy = dynamic_cast<nc::Enemy*>(actor);
		enemy->SetTarget(player);
		
		actor->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0, 600) };
		scene.AddActor(enemy);
	}

	char name[] = "CSC196";
	Core::Init(name, 800, 600);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);

	Core::GameLoop();
	Core::Shutdown();

	scene.Shutdown();
}
