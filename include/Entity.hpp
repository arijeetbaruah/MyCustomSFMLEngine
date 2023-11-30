#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>
#include "./Transform.hpp"

class Entity
{
protected:
	std::string m_id;
	sf::Sprite m_sprite;
	Transform* m_transform;
public:
	Entity(std::string id, const sf::Texture& texture, const glm::vec2& pos);
	virtual ~Entity();

	std::string GetID();

	virtual void Update(sf::RenderWindow& window, float deltaTime) = 0;
	virtual void Render(sf::RenderWindow& window);
};

#endif // !ENTITY_H

