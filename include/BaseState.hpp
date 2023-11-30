#ifndef BASESTATE_H
#define BASESTATE_H

#include<SFML/Graphics.hpp>

class BaseState
{
public:
	virtual void OnStart() = 0;
	virtual void OnUpdate(sf::RenderWindow& window, float deltaTime) = 0;
	virtual void OnRender(sf::RenderWindow& window) {}
	virtual void OnExit() = 0;
};

#endif // !BASESTATE_H
