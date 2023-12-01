#ifndef PLAYER_H
#define PLAYER_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "./Entity.hpp"

class Player : public Entity
{
public:
	Player(std::string id, std::string texture, const glm::vec2& pos);
	void Update(sf::RenderWindow& window, float deltaTime);
	void Render(sf::RenderWindow& window);

private:
	bool m_boosting;
};

class PlayerFactory
{
public:
	PlayerFactory(std::string id);
	PlayerFactory* SetPosition(glm::vec2 position);
	PlayerFactory* SetTexture(std::string texture);
	Player* Create();
protected:
	std::string m_id;
	glm::vec2 m_position;
	std::string m_texture;
};

#endif // !PLAYER_H
