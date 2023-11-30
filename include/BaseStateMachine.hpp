#ifndef BASESTATEMANAGER_H
#define BASESTATEMANAGER_H

#include "./BaseState.hpp";

class BaseStateMachine
{
public:
	BaseStateMachine();
	void SetState(BaseState* state);
	virtual void OnUpdate(sf::RenderWindow& window, float deltaTime);
	virtual void OnRender(sf::RenderWindow& window);
protected:
	BaseState* m_current_state;
};

#endif // !BASESTATEMANAGER_H

