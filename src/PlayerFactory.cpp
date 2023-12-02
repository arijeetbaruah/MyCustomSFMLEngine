#include "../include/PlayerFactory.hpp"

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

PlayerFactory* PlayerFactory::SetOnDeath(std::function<void()> OnDeath)
{
	m_OnDeath = OnDeath;
	return this;
}

Player* PlayerFactory::Create()
{
	Player* player = new Player(m_id, m_texture, m_position);
	player->SetOnDeath(m_OnDeath);

	return player;
}
