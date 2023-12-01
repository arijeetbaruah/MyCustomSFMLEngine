#include "../include/Astroid.hpp"
#include <Logger.hpp>

const float ASTROID_SPEED = 500;

Astroid::Astroid(std::string id, std::string texture, const glm::vec2& pos) : Entity(id, texture, pos)
{
	int rotation = rand() % (360 + 1);
	GetTransform()->SetRotation(rotation);
}


void Astroid::Update(sf::RenderWindow& window, float deltaTime)
{
	GetTransform()->Move(glm::vec2(0, 1) * ASTROID_SPEED * deltaTime);

	Entity::Update(window, deltaTime);
}

void Astroid::Render(sf::RenderWindow& window)
{
	Entity::Render(window);
}

void Astroid::OnCollision(Entity* other)
{
	Logger::GetInstance()->log(LogLevel::INFO, "Collision: " + other->GetID());
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
