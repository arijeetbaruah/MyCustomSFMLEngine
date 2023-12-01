#include "../include/Player.hpp"
#include "../include/Logger.hpp"
#include "../include/ResourceManager.hpp"

const float PLAYER_SPEED = 2;
const float PLAYER_SPEED_MULTIPLER = 1.5f;
const float PLAYER_ROTATION_SPEED = 1;

Player::Player(std::string id, std::string texture, const glm::vec2& pos) : Entity(id, texture, pos), m_boosting(false)
{
}

void Player::Update(sf::RenderWindow& window, float deltaTime)
{
	Entity::Update(window, deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		GetTransform()->Rotate(-PLAYER_ROTATION_SPEED);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		GetTransform()->Rotate(PLAYER_ROTATION_SPEED);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		GetTransform()->Move(glm::vec2(0, -1) * PLAYER_SPEED * (m_boosting ? PLAYER_SPEED_MULTIPLER : 1) * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		GetTransform()->Move(glm::vec2(0, 1) * PLAYER_SPEED * (m_boosting ? PLAYER_SPEED_MULTIPLER : 1) * deltaTime);
	}

	m_boosting = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
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

PlayerFactory* PlayerFactory::SetTexture(std::string texture)
{
	m_texture = texture;
	return this;
}

Player* PlayerFactory::Create()
{
	return new Player(m_id, m_texture, m_position);
}
