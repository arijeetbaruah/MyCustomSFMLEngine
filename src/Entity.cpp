#include "../include/Entity.hpp"

Entity::Entity(std::string id, const sf::Texture& texture, const glm::vec2& position) : m_id(id)
{
	m_sprite.setTexture(texture);

	m_transform = new Transform(position);

	auto size = texture.getSize();
	m_sprite.setOrigin(size.x / 2.f, size.y / 2.f);
	m_sprite.setPosition(position.x, position.y);
}

Entity::~Entity()
{
	delete m_transform;

	m_transform = nullptr;
}

std::string Entity::GetID()
{
	return m_id;
}

void Entity::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}