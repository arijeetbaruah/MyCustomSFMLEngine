#include <SFML/Graphics.hpp>
#include "../include/Game.hpp"
#include "../include/Logger.hpp"
#include "../include/SceneStateManager.hpp"
#include "../include/Constants.hpp"

int main()
{
	auto window = sf::RenderWindow{ { SCREEN_WIDTH, SCREEN_HEIGHT }, "CMake SFML Project" };
	window.setFramerateLimit(144);
	Game* game = Game::GetInstance();
	Logger::GetInstance()->setLogLevel(LogLevel::DEBUG);

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