#include "../include/Button.hpp"
#include "../include/ResourceManager.hpp"

Button::Button(std::string id, std::string text, glm::vec2 position, glm::vec2 size, sf::Color idleColor, sf::Color hoverColor)
	: m_isHovered(false), m_hoverColor(hoverColor), m_idleColor(idleColor)
{
	m_shape.setFillColor(idleColor);
	m_shape.setPosition(sf::Vector2f(position.x, position.y));
	m_shape.setSize(sf::Vector2f(size.x, size.y));
	if (ResourceManager::GetInstance()->LoadFont("Roboto-Black.ttf", m_font))
	{
		m_titleTxt.setFont(m_font);
		m_titleTxt.setStyle(sf::Text::Bold);
		m_titleTxt.setString(text);
		m_titleTxt.setCharacterSize(24);
		m_titleTxt.setFillColor(sf::Color::Black);
		glm::vec2 titleTxtPos = position + size / 4.f;
		m_titleTxt.setPosition(titleTxtPos.x, titleTxtPos.y);
	}
}

void Button::Update(sf::RenderWindow& window, float deltaTime)
{
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

	m_isHovered = m_shape.getGlobalBounds().contains(mousePos);

	if (m_isHovered)
	{
		m_shape.setFillColor(m_hoverColor);
		m_titleTxt.setFillColor(sf::Color::White);
	}
	else
	{
		m_shape.setFillColor(m_idleColor);
		m_titleTxt.setFillColor(sf::Color::Black);
	}
}

void Button::Render(sf::RenderWindow& window)
{
	window.draw(m_shape);
	window.draw(m_titleTxt);
}

bool Button::isPressed()
{
	return m_isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
