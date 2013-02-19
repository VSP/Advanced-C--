/*
#ifndef __Wandering_Monster_h__
#define __Wanderomg_Monster_h__

#include <iostream>
#include <cstdlib>
#include <vector>


#include "Enemy.h"
#include "MoveCommand.h"
//////////

//////////

//const int WENEMY_DEFAULT_HITPOINTS = 1;

using namespace std;
class Game;
class Wandering_Monster : public Enemy
{

private:

 vector <Enemy> evec;
 Enemy we;
 Enemy we2;
public:
 Wandering_Monster();

 virtual ~Wandering_Monster();
 void Move();
 
 void Update();

 
};
#endif

*/