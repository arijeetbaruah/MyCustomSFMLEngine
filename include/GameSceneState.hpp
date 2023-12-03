#ifndef GAMESCENESTATE_H
#define GAMESCENESTATE_H

#include "./BaseState.hpp";

class Game;
class BaseStateMachine;
class Player;
class PlayerFactory;
class Explosion;
class Astroid;

class GameSceneState : public BaseState
{
public:
	GameSceneState(Game* game, BaseStateMachine* stateMachine);
	~GameSceneState();

	void OnStart() override;
	void OnUpdate(sf::RenderWindow& window, float deltaTime) override;
	void OnRender(sf::RenderWindow& window) override;
	void OnExit() override;

protected:
	Player* m_player;
	Astroid* m_astroid;
	Explosion* m_player_explosion;

	PlayerFactory* playerFactory;

	void OnPlayerDeath();
	void StartNewLevel();

	bool m_isPlayerDead;
	float m_playerRespawn;
};

#endif // !MAINMENUSCENESTATE_H

