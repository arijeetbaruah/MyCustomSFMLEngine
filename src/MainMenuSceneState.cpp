#include "../include/MainMenuSceneState.hpp"
#include "../include/ButtonFactory.hpp"
#include "../include/Game.hpp"
#include "../include/GameSceneState.hpp"
#include "../include/Button.hpp"
#include "../include/BaseStateMachine.hpp"
#include "../include/SceneStateManager.hpp"

MainMenuSceneState::MainMenuSceneState(Game* game, BaseStateMachine* stateMachine) : BaseState(game, stateMachine)
{
	ButtonFactory* playBtnFactory = new ButtonFactory("playBtn", "Play");
	ButtonFactory* exitBtnFactory = new ButtonFactory("exitBtn", "Exit");

	playBtn = playBtnFactory
		->SetPosition(glm::vec2(1920u / 2, 300))
		->SetSize(glm::vec2(100, 50))
		->SetIdleColor(sf::Color::Blue)
		->SetHoverColor(sf::Color::Red)
		->Create();

	exitBtn = exitBtnFactory
		->SetPosition(glm::vec2(1920u / 2, 500))
		->SetSize(glm::vec2(100, 50))
		->SetIdleColor(sf::Color::Blue)
		->SetHoverColor(sf::Color::Red)
		->Create();

	delete playBtnFactory;
	delete exitBtnFactory;

	playBtnFactory = nullptr;
	exitBtnFactory = nullptr;
}

MainMenuSceneState::~MainMenuSceneState()
{
	delete playBtn;
	delete exitBtn;

	BaseState::~BaseState();

	playBtn = nullptr;
	exitBtn = nullptr;
}

void MainMenuSceneState::OnStart()
{

}

void MainMenuSceneState::OnUpdate(sf::RenderWindow& window, float deltaTime)
{
	playBtn->Update(window, deltaTime);
	exitBtn->Update(window, deltaTime);

	if (playBtn->isPressed())
	{
		SceneStateManager* sceneStateMachine = reinterpret_cast<SceneStateManager*>(m_stateMachine);
		sceneStateMachine->SwitchScene(Scene::Game);
	}

	if (exitBtn->isPressed())
	{
		exit(EXIT_SUCCESS);
	}
}

void MainMenuSceneState::OnRender(sf::RenderWindow& window)
{
	playBtn->Render(window);
	exitBtn->Render(window);
}

void MainMenuSceneState::OnExit()
{

}
