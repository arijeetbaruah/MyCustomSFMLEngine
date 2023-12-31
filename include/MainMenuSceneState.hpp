#ifndef MAINMENUSCENESTATE_H
#define MAINMENUSCENESTATE_H

#include "./BaseState.hpp";

class Game;
class Button;
class BaseStateMachine;

class MainMenuSceneState : public BaseState
{
public:
	MainMenuSceneState(Game* game, BaseStateMachine* stateMachine);
	~MainMenuSceneState();

	void OnStart() override;
	void OnUpdate(sf::RenderWindow& window, float deltaTime) override;
	void OnRender(sf::RenderWindow& window) override;
	void OnExit() override;

protected:
	Button* playBtn;
	Button* exitBtn;
};

#endif // !MAINMENUSCENESTATE_H

