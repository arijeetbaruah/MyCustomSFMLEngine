#include <SFML/Graphics.hpp>
#include "../include/Game.hpp"
#include "../include/SceneStateManager.hpp"

int main()
{
	auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
	window.setFramerateLimit(144);
	Game* game = Game::GetInstance();

	sf::Clock clock;
	while (window.isOpen())
	{
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		game->Update(window, clock.getElapsedTime().asSeconds());

		window.clear();
		game->Draw(window);
		window.display();
	}

	delete game;
	game = nullptr;
}