#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/vec2.hpp>

class Transform
{
protected:
	glm::vec2 m_position;
	float m_rotation;
	glm::vec2 m_size;

public:
	Transform(const glm::vec2& position);

	void SetPosition(const glm::vec2 position);
	glm::vec2 GetPosition() const;

	void SetRotation(const float rotation);
	float GetRotation() const;

	void SetSize(const glm::vec2 size);
	glm::vec2 GetSize() const;

	void Move(const glm::vec2 movement);
	void Rotate(float rotation);

	glm::vec2 GetForward() const;
};

#endif // !TRANSFORM_H
