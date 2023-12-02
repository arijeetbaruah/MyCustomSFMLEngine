#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>

#include "./Player.hpp"

class PlayerFactory
{
public:
	PlayerFactory(std::string id);
	PlayerFactory* SetPosition(glm::vec2 position);
	PlayerFactory* SetTexture(std::string texture);
	PlayerFactory* SetOnDeath(std::function<void()> OnDeath);
	Player* Create();
protected:
	std::string m_id;
	glm::vec2 m_position;
	std::string m_texture;
	std::function<void()> m_OnDeath;
};

#endif // !PLAYERFACTORY_H
