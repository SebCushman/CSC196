#include "pch.h"
#include "Scene.h"
#include "Actor.h"

namespace nc
{
	void Scene::Startup()
	{
		// nothing
	}

	void Scene::Shutdown()
	{
		// iterate through the actors and call delete on each actor
		// this will free up the memory for each actor
		for (nc::Actor* actor : m_actors) {
			RemoveActor(actor);
		}
		// clear m_actors list
		m_actors.clear();
	}

	void Scene::Update(float dt)
	{
		for (nc::Actor* actor : m_actors) {
			actor->Update(dt);
		}
	}

	void Scene::Draw(Core::Graphics& graphics)
	{
		for (nc::Actor* actor : m_actors) {
			actor->Draw(graphics);
		}
	}

	void Scene::AddActor(Actor* actor)
	{
		// set the scene for the actor, use this
		// push back the actor on the actors list
		m_actors.push_back(actor);
	}

	void Scene::RemoveActor(Actor* actor)
	{
		std::list<Actor*>::iterator iter = std::find(m_actors.begin(), m_actors.end(), actor);
		if (iter != m_actors.end())
		{
			delete* iter;
			m_actors.erase(iter);
		}
	}
}
