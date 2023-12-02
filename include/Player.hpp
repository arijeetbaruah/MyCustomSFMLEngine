#ifndef PLAYER_H
#define PLAYER_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "./Entity.hpp"
#include <functional>

class Player : public Entity
{
public:
	Player(std::string id, std::string texture, const glm::vec2& pos);
	void Update(sf::RenderWindow& window, float deltaTime);
	void Render(sf::RenderWindow& window);

	void OnCollision(BaseEntity* other) override;

	void SetOnDeath(std::function<void()> OnDeath);

private:
	bool m_boosting;
	std::function<void()> m_OnDeath;
};

#endif // !PLAYER_H
