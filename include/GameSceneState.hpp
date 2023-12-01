#ifndef GAMESCENESTATE_H
#define GAMESCENESTATE_H

#include "./BaseState.hpp";

class Game;
class BaseStateMachine;
class Player;
class Astroid;

class GameSceneState : public BaseState
{
public:
	GameSceneState(Game* game, BaseStateMachine* stateMachine);

	void OnStart() override;
	void OnUpdate(sf::RenderWindow& window, float deltaTime) override;
	void OnRender(sf::RenderWindow& window) override;
	void OnExit() override;

protected:
	Player* m_player;
	Astroid* m_astroid;

	sf::Texture m_playerTexture;
	sf::Texture m_astroidTexture;
};

#endif // !MAINMENUSCENESTATE_H

