#ifndef BASESTATEMANAGER_H
#define BASESTATEMANAGER_H

#include "./BaseState.hpp";

class BaseStateMachine
{
public:
	BaseStateMachine(Game* game);
	void SetState(BaseState* state);
	virtual void OnUpdate(sf::RenderWindow& window, float deltaTime);
	virtual void OnRender(sf::RenderWindow& window);
protected:
	BaseState* m_current_state;
	Game* m_game;
};

#endif // !BASESTATEMANAGER_H

