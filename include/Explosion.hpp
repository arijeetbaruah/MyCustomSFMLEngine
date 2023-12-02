#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>
#include <glm/vec2.hpp>
#include "./Transform.hpp"
#include "./BaseEntity.hpp"

class Explosion : public BaseEntity
{
protected:
	std::string m_id;
	sf::Sprite m_sprite;
	sf::IntRect m_frame;
	sf::Texture m_texture;
	Transform* m_transform;

	float m_timer;
	float m_timer_counter;
public:
	Explosion(std::string id, std::string texture, const glm::vec2& pos);
	~Explosion();

	std::string GetID();

	virtual void Update(sf::RenderWindow& window, float deltaTime);
	virtual void Render(sf::RenderWindow& window);
	virtual void OnCollision(BaseEntity* other) {}

	sf::FloatRect GetBounds();
	float GetTimerCounter() const
	{
		return m_timer_counter;
	}

	Transform* GetTransform() const;
};

#endif // !EXPLOSION_H

