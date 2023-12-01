#include "../include/Game.hpp"
#include "../include/SceneStateManager.hpp"

Game::Game()
{
	m_sceneStateManager = new SceneStateManager(this);
}

void Game::AddEntity(Entity* entity)
{
	m_entities.emplace(entity->GetID(), entity);
}

void Game::RemoveEntity(Entity* entity)
{
	m_entities.erase(entity->GetID());
}

void Game::Update(sf::RenderWindow& window, float deltaTime)
{
	for (auto& entity : m_entities)
	{
		entity.second->Update(window, deltaTime);
	}

	m_sceneStateManager->OnUpdate(window, deltaTime);

	for (auto entity1 = m_entities.begin(); entity1 != m_entities.end(); entity1++)
	{
		for (auto entity2 = entity1; entity2 != m_entities.end(); entity2++)
		{
			if (entity1 != entity2 && entity1->second->GetBounds().intersects(entity2->second->GetBounds()))
			{
				entity1->second->OnCollision(entity2->second);
				entity2->second->OnCollision(entity1->second);
			}
		}
	}
}

void Game::Draw(sf::RenderWindow& window)
{
	m_sceneStateManager->OnRender(window);

	for (auto& entity : m_entities)
	{
		entity.second->Render(window);
	}
}
