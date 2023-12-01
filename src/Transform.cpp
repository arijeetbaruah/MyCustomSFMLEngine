#include "../include/Transform.hpp"

#include <glm/gtx/transform2.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

Transform::Transform(const glm::vec2& position) : m_position(position), m_size(1, 1), m_rotation(0)
{
}

void Transform::SetPosition(const glm::vec2 position)
{
	m_position = position;
}

glm::vec2 Transform::GetPosition() const
{
	return m_position;
}

void Transform::SetRotation(const float rotation)
{
	m_rotation = rotation;
}

float Transform::GetRotation() const
{
	return m_rotation;
}

void Transform::SetSize(const glm::vec2 size)
{
	m_size = size;
}

glm::vec2 Transform::GetSize() const
{
	return m_size;
}

void Transform::Move(const glm::vec2 movement)
{
	float speed = std::sqrt(movement.x * movement.x + movement.y * movement.y);

	float rotation = GetRotation();
	float angle = rotation == 0 ? 0 : (glm::pi<float>() / 180) * GetRotation();

	float cos = std::cos(angle);
	float sin = std::sin(angle);
	float newX = movement.x * cos - movement.y * sin;
	float newY = movement.x * sin + movement.y * cos;

	if (newX == newY && newX == 0)
	{
		return;
	}

	m_position += glm::normalize(glm::vec2(newX, newY)) * speed;
}

void Transform::Rotate(float rotation)
{
	m_rotation += rotation;
}

glm::vec2 Transform::GetForward() const
{
	glm::vec2 position = GetPosition();
	float rotation = GetRotation();
	float angle = rotation == 0 ? 0 : glm::pi<float>() / (360 * GetRotation());

	float x = std::sin(angle);
	float y = std::cos(angle);
	return glm::vec2(-x, -y);
}
