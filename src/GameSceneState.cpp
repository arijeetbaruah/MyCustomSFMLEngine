#include "../include/GameSceneState.hpp"
#include "../include/Game.hpp"
#include "../include/BaseStateMachine.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Player.hpp"
#include "../include/PlayerFactory.hpp"
#include "../include/Explosion.hpp"
#include "../include/Astroid.hpp"
#include "../include/Constants.hpp"
#include "../include/Explosion.hpp"
#include "../include/Logger.hpp"

const float BG_SPEED = 100.f;
const float RESPAWN_COOLDOWN = 5;

GameSceneState::GameSceneState(Game* game, BaseStateMachine* stateMachine) : BaseState(game, stateMachine),
	m_player(nullptr), m_astroid(nullptr), m_player_explosion(nullptr),
	m_isPlayerDead(false), m_playerRespawn(0)
{
	playerFactory = new PlayerFactory("player");
}

GameSceneState::~GameSceneState()
{
	delete playerFactory;
}

void GameSceneState::OnStart()
{
	AstroidFactory* astroidFactory = new AstroidFactory("Asteroid.png");

	m_player = playerFactory
		->SetPosition(glm::vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2))
		->SetTexture("player.png")
		->SetOnDeath([this]() { OnPlayerDeath(); })
		->Create();
	m_game->AddEntity(m_player);

	m_player->GetTransform()->SetSize(glm::vec2(0.3f, 0.3f));

	m_astroid = astroidFactory
		->SetPosition(100, 150)
		->Create("Astroid");
	m_game->AddEntity(m_astroid);
	m_astroid->GetTransform()->SetSize(glm::vec2(2, 2));

	delete astroidFactory;
	astroidFactory = nullptr;

}

void GameSceneState::OnUpdate(sf::RenderWindow& window, float deltaTime)
{
	if (m_isPlayerDead)
	{
		if (m_playerRespawn <= 0)
		{
			m_player->SetIsActive(true);
			m_isPlayerDead = false;
		}
		m_playerRespawn -= deltaTime;
	}
}

void GameSceneState::OnRender(sf::RenderWindow& window)
{
}

void GameSceneState::OnExit()
{
	m_game->DestroyEntity(m_player);
	m_game->DestroyEntity(m_astroid);
	delete m_player;
	delete m_astroid;
	m_player = nullptr;
	m_astroid = nullptr;

	if (m_player_explosion != nullptr)
	{
		delete m_player_explosion;
		m_player_explosion = nullptr;
	}
}

void GameSceneState::OnPlayerDeath()
{
	Logger::GetInstance()->log(LogLevel::INFO, "OnDeath");

	m_player_explosion = new Explosion("m_explosion_texture", "Explosion.png", m_player->GetTransform()->GetPosition());
	m_player->SetIsActive(false);
	m_player_explosion->SetOnAnimation([this]()
	{
		m_player->SetIsActive(true);
		m_game->DestroyEntity(m_player_explosion);
		StartNewLevel();
	});
	m_game->AddEntity(m_player_explosion);
}

void GameSceneState::StartNewLevel()
{
	m_player->GetTransform()->SetPosition(glm::vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	m_player->GetTransform()->SetRotation(0);
	m_isPlayerDead = true;
	m_playerRespawn = RESPAWN_COOLDOWN;
}
