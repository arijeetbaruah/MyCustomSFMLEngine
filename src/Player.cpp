#include "../include/Player.hpp"
#include "../include/Logger.hpp"
#include "../include/ResourceManager.hpp"

Player::Player(std::string id, const sf::Texture& texture, const glm::vec2& pos) : Entity(id, texture, pos)
{
}

void Player::Update(sf::RenderWindow& window, float deltaTime)
{
	
}

void Player::Render(sf::RenderWindow& window)
{
	Entity::Render(window);
}

PlayerFactory::PlayerFactory(std::string id) : m_id(id), m_position(0, 0)
{
}

PlayerFactory* PlayerFactory::SetPosition(glm::vec2 position)
{
	m_position = position;
	return this;
}

Player* PlayerFactory::Create()
{
	sf::Texture texture;
	if (!ResourceManager::GetInstance()->GetTexture("player.png", texture))
	{
		Logger::GetInstance()->log(LogLevel::ERROR, "Can't find Sprite: player.png");
		return nullptr;
	}

	return new Player(m_id, texture, m_position);
}
