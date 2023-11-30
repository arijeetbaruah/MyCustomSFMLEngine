#include "../include/Transform.hpp"

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
