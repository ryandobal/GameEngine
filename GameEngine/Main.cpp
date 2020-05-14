#include <SFML/Graphics.hpp>
#include "Engine.h"

int main(int argc, char* args[])
{
	// Deeclare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Ryan's Game Engine");
	// Run the program as long as the window is open

	// Pass widnow reference to engine and start
	gameEngine.Start(&window); // this later calls updates

	return 0;
}
