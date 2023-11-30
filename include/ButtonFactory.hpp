#ifndef BUTTONFACTORY_H
#define BUTTONFACTORY_H

#include <glm/vec2.hpp>
#include "./Button.hpp"

class ButtonFactory
{
public:
	ButtonFactory(std::string id, std::string text);

	ButtonFactory* SetPosition(glm::vec2 position);
	ButtonFactory* SetSize(glm::vec2 size);
	ButtonFactory* SetIdleColor(sf::Color idleColor);
	ButtonFactory* SetHoverColor(sf::Color hoverColor);

	Button* Create();
protected:
	std::string m_id;
	std::string m_text;
	glm::vec2 m_position;
	glm::vec2 m_size;
	sf::Color m_idleColor;
	sf::Color m_hoverColor;
};

#endif // !BUTTONFACTORY_H
