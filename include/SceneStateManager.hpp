#ifndef BASESCENEMANAGER_H
#define BASESCENEMANAGER_H

#include <unordered_map>
#include "./BaseStateMachine.hpp";

class Game;
class BaseState;

const std::string MAINMENUSCENE = "MainMenu";
const std::string GAMESCENE = "Game";

enum class Scene
{
	MainMenu,
	Game
};

class SceneStateManager : public BaseStateMachine
{
public:
	SceneStateManager(Game* game);
	void SwitchScene(Scene scene);

protected:
	std::unordered_map<Scene, BaseState*> stateMap;
};

#endif // !BASESCENEMANAGER_H

