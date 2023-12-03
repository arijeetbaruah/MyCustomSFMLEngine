#include "../include/Explosion.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Constants.hpp"
#include "../include/Game.hpp"

const int Duration = 2;

Explosion::Explosion(std::string id, std::string texture, const glm::vec2& position) : BaseEntity(), m_id(id), m_timer(0), m_timer_counter(0)
{
	m_transform = new Transform(position);
	if (ResourceManager::GetInstance()->GetTexture(texture, m_texture))
	{
		m_texture.setSmooth(true);

		auto rectSize = m_texture.getSize();
		m_frame = sf::IntRect(0, 0, rectSize.x / 8, rectSize.y / 4);

		m_sprite = sf::Sprite(m_texture, m_frame);

		auto size = m_texture.getSize();
		m_sprite.setOrigin(m_frame.width / 2.f, m_frame.height / 2.f);
		m_sprite.setPosition(position.x, position.y);
	}
}

Explosion::~Explosion()
{
	delete m_transform;

	m_transform = nullptr;
}

std::string Explosion::GetID()
{
	return m_id;
}

void Explosion::Update(sf::RenderWindow& window, float deltaTime)
{	
	if (m_timer >= 0.3f)
	{
		if (m_timer_counter == 8)
		{
			m_OnAnimation();
			m_game->DestroyEntity(this);
			return;
		}
		else
		{
			m_frame.left += m_frame.width;
			m_timer_counter++;
		}

		m_timer = 0;
	}

	m_timer += deltaTime;
	m_sprite.setTextureRect(m_frame);

	auto pos = m_transform->GetPosition();
	auto size = m_transform->GetSize();

	if (pos.x < 0)
	{
		pos.x = window.getSize().x;
	}
	else
	{
		pos.x = std::fmodf(pos.x, window.getSize().x);
	}

	if (pos.y < 0)
	{
		pos.y = window.getSize().y;
	}
	else
	{
		pos.y = std::fmodf(pos.y, window.getSize().y);
	}

	m_transform->SetPosition(pos);

	m_sprite.setPosition(pos.x, pos.y);
	m_sprite.setRotation(m_transform->GetRotation());
	m_sprite.setScale(size.x, size.y);
}

void Explosion::Render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

sf::FloatRect Explosion::GetBounds()
{
	sf::FloatRect rect = m_sprite.getGlobalBounds();

	rect.width *= m_frame.width;
	rect.height *= m_frame.height;

	return rect;
}

Transform* Explosion::GetTransform() const
{
	return m_transform;
}

void Explosion::SetOnAnimation(std::function<void()> OnAnimation)
{
	m_OnAnimation = OnAnimation;
}
