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
	sf::Texture m_texture;
	Transform* m_transform;
public:
	Entity(std::string id, std::string texture, const glm::vec2& pos);
	virtual ~Entity();

	std::string GetID();

	virtual void Update(sf::RenderWindow& window, float deltaTime);
	virtual void Render(sf::RenderWindow& window);

	Transform* GetTransform() const;
};

#endif // !ENTITY_H

