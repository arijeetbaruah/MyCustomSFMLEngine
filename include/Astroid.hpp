#ifndef ASTROID_H
#define ASTROID_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "./Entity.hpp"

class Astroid : public Entity
{
public:
	Astroid(std::string id, std::string texture, const glm::vec2& pos);
	void Update(sf::RenderWindow& window, float deltaTime);
	void Render(sf::RenderWindow& window);
	void OnCollision(Entity* other) override;
};

class AstroidFactory
{
public:
	AstroidFactory(std::string texture);
	AstroidFactory* SetPosition(glm::vec2 position);
	AstroidFactory* SetPosition(float posX, float posY);
	Astroid* Create(std::string id);
private:
	glm::vec2 m_position;
	std::string m_texture;
};

#endif // !ASTROID_H
