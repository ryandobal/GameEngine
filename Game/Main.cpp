#include <SFML/Graphics.hpp>
#include "../GameEngine/include/Engine.h"


// GAME main
int main(int argc, char* args[]) {
	// Deeclare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Ryan's Game Engine");
	// Run the program as long as the window is open

	// Create the world for attaching entities and systems
	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* ent;

	// Add system to the engine
	gameEngine.AddSystem(new RenderingSystem());

	// Create and assign 250 entities to the world
	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			//Create entities in the world from the Game Engine
			ent = gameEngine.world->create();

			//Assign components to entities after creation
			ent->assign<Transfrom>(i * 32, j * 32); // Sprite dimensions
			ent->assign<Sprite>("../Debug/images/herosheet.png");
			ent->assign<Animator>(32, 32, 200.f);
			std::cout << ent->getEntityId() << " is the entity ID." << std::endl;
		}
	}

	// Pass window reference to engine and start
	gameEngine.Start(&window); // this later calls updates

	return 0;

}