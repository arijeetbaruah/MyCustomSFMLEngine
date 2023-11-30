#include "../include/SceneStateManager.hpp"
#include "../include/Game.hpp"
#include "../include/MainMenuSceneState.hpp"
#include "../include/GameSceneState.hpp"

SceneStateManager::SceneStateManager(Game* game)
{
	stateMap.emplace(Scene::MainMenu, new MainMenuSceneState(game, this));
	stateMap.emplace(Scene::Game, new GameSceneState(game, this));
	SwitchScene(Scene::MainMenu);
}

void SceneStateManager::SwitchScene(Scene scene)
{
	SetState(stateMap[scene]);
}
