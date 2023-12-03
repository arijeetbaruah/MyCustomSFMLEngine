#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "./BaseEntity.hpp"
#include "Singleton.hpp"

class SceneStateManager;

class Game : public Singleton<Game>
{
private:
	std::unordered_map<std::string, BaseEntity*> m_entities;
	SceneStateManager* m_sceneStateManager;
	std::vector<BaseEntity*> m_entityToDelete;
public:
	Game();

	void AddEntity(BaseEntity* entity);
	void RemoveEntity(BaseEntity* entity);
	void DestroyEntity(BaseEntity* entity);
	void Update(sf::RenderWindow& window, float deltaTime);
	void Draw(sf::RenderWindow& window);
};

#endif // !GAME_H
