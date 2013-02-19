#include "Scene.h"
#include <algorithm>
Scene::Scene()
{
 //guard = new Enemy();
 //7/ninja = new Enemy();

  //m_ulist.push_back(guard);
  //m_ulist.push_back(ninja);
}
Scene::~Scene()
{

}
struct UpdateOp
{
	
	inline void operator ()(Updateable * Obj)
	{
		Obj->Update();
	}
};
void Scene::Update()
{
	EnemyList & lst = GetUpdateables();
	for_each(lst.begin(), lst.end(), UpdateOp());
}

void Scene::SetGame(Game*pGame)
{
	game = pGame;
}
Game*
Scene::GetGame() const
{
	return game;
}
