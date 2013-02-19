/*
#include "Map.h"
#include "Dungeon.h"
#include "Hallway.h"
#include "MonsterRoom.h"
#include "NPC_Room.h"
#include "Chambers.h"
Map::Map()
{
  rooms[kDungeon] = new Dungeon();
  //rooms[kDungeon]->SetGame(this);
  vmap.push_back(new Dungeon())
  
  rooms[kHallway] = new Hallway();
  rooms[kHallway]->SetGame(this);

  rooms [kNPC] = new NPCRoom();
  rooms [kNPC]->SetGame(this);
  
  rooms[kMonster] = new MonsterRoom();
  rooms[kMonster]->SetGame(this);
  
  rooms[kChambers] = new Chambers();
  rooms[kChambers]->SetGame(this);
}
Map::~Map()
{


}
Map::GetGame()
{
	return game;
}
Map::SetGame(Game* g)
{
	game = g;
}
*/