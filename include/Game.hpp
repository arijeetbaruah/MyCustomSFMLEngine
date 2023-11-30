#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "./Entity.hpp"
#include "Singleton.hpp"

class SceneStateManager;

class Game : public Singleton<Game>
{
private:
	std::unordered_map<std::string, Entity*> m_entities;
	SceneStateManager* m_sceneStateManager;
public:
	Game();

	void AddEntity(Entity* entity);
	void RemoveEntity(Entity* entity);
	void Update(sf::RenderWindow& window, float deltaTime);
	void Draw(sf::RenderWindow& window);
};

#endif // !GAME_H
