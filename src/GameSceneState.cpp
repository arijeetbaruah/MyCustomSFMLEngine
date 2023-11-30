#include "../include/GameSceneState.hpp"
#include "../include/Game.hpp"
#include "../include/BaseStateMachine.hpp"
#include "../include/Player.hpp"

GameSceneState::GameSceneState(Game* game, BaseStateMachine* stateMachine) : BaseState(game, stateMachine), m_player(nullptr)
{
	
}

void GameSceneState::OnStart()
{
	m_player = (new PlayerFactory("player"))->Create();
	m_game->AddEntity(m_player);
}

void GameSceneState::OnUpdate(sf::RenderWindow& window, float deltaTime)
{

}

void GameSceneState::OnRender(sf::RenderWindow& window)
{

}

void GameSceneState::OnExit()
{
	m_game->RemoveEntity(m_player);
	delete m_player;
	m_player = nullptr;
}
