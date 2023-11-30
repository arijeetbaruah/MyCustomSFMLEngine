#ifndef BASESTATE_H
#define BASESTATE_H

#include<SFML/Graphics.hpp>

class Game;
class BaseStateMachine;

class BaseState
{
public:
	BaseState(Game* game, BaseStateMachine* stateMachine);
	virtual ~BaseState();
	virtual void OnStart() = 0;
	virtual void OnUpdate(sf::RenderWindow& window, float deltaTime) = 0;
	virtual void OnRender(sf::RenderWindow& window) {}
	virtual void OnExit() = 0;
protected:
	Game* m_game;
	BaseStateMachine* m_stateMachine;
};

#endif // !BASESTATE_H
