#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/vec2.hpp>

class Transform
{
protected:
	glm::vec2 m_position;

public:
	Transform(const glm::vec2& position);
};

#endif // !TRANSFORM_H
