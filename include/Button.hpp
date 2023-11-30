#ifndef BUTTON_H
#define BUTTON_H

#include <glm/vec2.hpp>
#include "./Entity.hpp"

class Button
{
public:
	Button(std::string id, std::string text, glm::vec2 position, glm::vec2 size, sf::Color idleColor, sf::Color hoverColor);
	void Update(sf::RenderWindow& window, float deltaTime);
	void Render(sf::RenderWindow& window);

	bool isPressed();

protected:
	sf::RectangleShape m_shape;
	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	bool m_isHovered;

	sf::Font m_font;
	sf::Text m_titleTxt;
};

#endif // !BUTTON_H
