////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
#ifndef __Enemy_h__
#define __Enemy_h__
#include "Game.h"
#include "Room.h"
#include "Player.h"
#include "GameObject.h"
#include "Globals.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include "IRenderer.h"

const int ENEMY_DEFAULT_HITPOINTS = 3;

using namespace std;

//class Game;

class Enemy : public GameObject
{
friend class AttackCommand;
friend class Game;
protected:

  bool CanAct;
  bool Inactive;
  Game *m_pGame;
  Room * mRoom;
  bool Aggro;
  bool CanMove;
  
public:

  Enemy();
  ~Enemy();
  bool IsAlive();
  
  void Attack( GameObject *pObject );

 void Update();


void CheckRoom();
Room* GetRoom();
void SetRoom(Room* MRoom);

void Move(Direction direction);

void SetGame( Game * pGame );
Game * GetGame();

};


#endif
