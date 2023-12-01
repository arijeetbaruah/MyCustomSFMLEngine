#include "../include/Entity.hpp"
#include "../include/ResourceManager.hpp"

Entity::Entity(std::string id, std::string texture, const glm::vec2& position) : m_id(id)
{
	if (ResourceManager::GetInstance()->GetTexture(texture, m_texture))
	{
		m_sprite.setTexture(m_texture);

		m_transform = new Transform(position);

		auto size = m_texture.getSize();
		m_sprite.setOrigin(size.x / 2.f, size.y / 2.f);
		m_sprite.setPosition(position.x, position.y);
	}
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

void Entity::Update(sf::RenderWindow& window, float deltaTime)
{
	auto pos = m_transform->GetPosition();
	auto size = m_transform->GetSize();
	m_sprite.setPosition(pos.x, pos.y);
	m_sprite.setRotation(m_transform->GetRotation());
	m_sprite.setScale(size.x, size.y);
}

void Entity::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

Transform* Entity::GetTransform() const
{
	return m_transform;
}
