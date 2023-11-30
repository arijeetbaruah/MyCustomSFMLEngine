#include "../include/ButtonFactory.hpp"

ButtonFactory::ButtonFactory(std::string id, std::string text)
	: m_id(id), m_text(text), m_position(0, 0), m_size(1, 1)
{
}

ButtonFactory* ButtonFactory::SetPosition(glm::vec2 position)
{
	m_position = position;

	return this;
}

ButtonFactory* ButtonFactory::SetSize(glm::vec2 size)
{
	m_size = size;

	return this;
}

ButtonFactory* ButtonFactory::SetIdleColor(sf::Color idleColor)
{
	m_idleColor = idleColor;

	return this;
}

ButtonFactory* ButtonFactory::SetHoverColor(sf::Color hoverColor)
{
	m_hoverColor = hoverColor;

	return this;
}

Button* ButtonFactory::Create()
{
	return new Button(m_id, m_text, m_position, m_size, m_idleColor, m_hoverColor);
}
