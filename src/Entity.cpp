#include "../include/Entity.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Constants.hpp"

Entity::Entity(std::string id, std::string texture, const glm::vec2& position) : BaseEntity(), m_id(id)
{
	m_transform = new Transform(position);
	if (ResourceManager::GetInstance()->GetTexture(texture, m_texture))
	{
		m_texture.setSmooth(true);
		m_sprite.setTexture(m_texture);

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
	if (!GetIsActive())
	{
		return;
	}

	auto pos = m_transform->GetPosition();
	auto size = m_transform->GetSize();

	if (pos.x < 0)
	{
		pos.x = window.getSize().x;
	}
	else
	{
		pos.x = std::fmodf(pos.x, window.getSize().x);
	}

	if (pos.y < 0)
	{
		pos.y = window.getSize().y;
	}
	else
	{
		pos.y = std::fmodf(pos.y, window.getSize().y);
	}

	m_transform->SetPosition(pos);

	m_sprite.setPosition(pos.x, pos.y);
	m_sprite.setRotation(m_transform->GetRotation());
	m_sprite.setScale(size.x, size.y);
}

void Entity::Render(sf::RenderWindow& window)
{
	if (!GetIsActive())
	{
		return;
	}

	window.draw(m_sprite);
}

sf::FloatRect Entity::GetBounds()
{
	sf::FloatRect rect = m_sprite.getGlobalBounds();

	rect.width *= m_transform->GetSize().x;
	rect.height *= m_transform->GetSize().y;

	return rect;
}

Transform* Entity::GetTransform() const
{
	return m_transform;
}
