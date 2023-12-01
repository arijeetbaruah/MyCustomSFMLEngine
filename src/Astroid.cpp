#include "../include/Astroid.hpp"

Astroid::Astroid(std::string id, std::string texture, const glm::vec2& pos) : Entity(id, texture, pos)
{
}


void Astroid::Update(sf::RenderWindow& window, float deltaTime)
{
	Entity::Update(window, deltaTime);
}

void Astroid::Render(sf::RenderWindow& window)
{
	Entity::Render(window);
}

AstroidFactory::AstroidFactory(std::string texture) : m_position(0, 0)
{
	m_texture = texture;
}

AstroidFactory* AstroidFactory::SetPosition(glm::vec2 position)
{
	m_position = position;
	return this;
}

AstroidFactory* AstroidFactory::SetPosition(float posX, float posY)
{
	m_position = glm::vec2(posX, posY);
	return this;
}

Astroid* AstroidFactory::Create(std::string id)
{
	return new Astroid(id, m_texture, m_position);
}
