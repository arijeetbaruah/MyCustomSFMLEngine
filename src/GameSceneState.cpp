#include "../include/GameSceneState.hpp"
#include "../include/Game.hpp"
#include "../include/BaseStateMachine.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Player.hpp"
#include "../include/Astroid.hpp"
#include "../include/Constants.hpp"

GameSceneState::GameSceneState(Game* game, BaseStateMachine* stateMachine) : BaseState(game, stateMachine), m_player(nullptr), m_astroid(nullptr)
{

}

void GameSceneState::OnStart()
{
	PlayerFactory* playerFactory = new PlayerFactory("player");
	AstroidFactory* astroidFactory = new AstroidFactory("Asteroid.png");

	m_player = playerFactory
		->SetPosition(glm::vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2))
		->SetTexture("player.png")
		->Create();
	m_game->AddEntity(m_player);

	m_player->GetTransform()->SetSize(glm::vec2(0.3f, 0.3f));

	m_astroid = astroidFactory
		->SetPosition(100, 150)
		->Create("Astroid");
	m_game->AddEntity(m_astroid);
	m_astroid->GetTransform()->SetSize(glm::vec2(2, 2));

	delete astroidFactory;
	delete playerFactory;

	astroidFactory = nullptr;
	playerFactory = nullptr;

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
	m_game->RemoveEntity(m_astroid);
	delete m_player;
	delete m_astroid;
	m_player = nullptr;
	m_astroid = nullptr;
}
