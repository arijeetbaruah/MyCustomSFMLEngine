#ifndef BASEENTITY_H
#define BASEENTITY_H

#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>

class Transform;
class Game;

class BaseEntity
{
protected:
	Game* m_game;

public:
	void SetGame(Game* game)
	{
		m_game = game;
	}

	virtual std::string GetID() = 0;

	virtual void Update(sf::RenderWindow& window, float deltaTime) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;
	virtual void OnCollision(BaseEntity* other) = 0;

	virtual sf::FloatRect GetBounds() = 0;

	virtual Transform* GetTransform() const = 0;
};

#endif // !BASEENTITY_H

