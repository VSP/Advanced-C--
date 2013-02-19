////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Player_h__
#define __Player_h__
#include <string>
#include "GameObject.h"
#include "Gold.h"
#include "Weapons.h"
#include "Inventory.h"
#include "Sword.h"
#include "Axe.h"
//#include "Enemy.h"

class Game;
class Enemy;
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject, public Inventory
{
friend class ChangeCommand;
friend class SearchCommand;
friend class InventoryCommand;
friend class SaveCommand;
friend class NPCRoom;
friend class TalkCommand;
friend class DrinkCommand;


private:
  Game *game;
  int whereID;
  Gold pMoney; 
  int  pWeapon;
  bool tDistance;
  string roomdesc;
  
  
public:
  
  Player();

  virtual ~Player();
  void SetGame( Game * game );
  void Attack( GameObject *pObject);

  void PrintSummary();
  static void AskInfo( Player & p );
  static void Load (Player & p);
  
  void SetWhereID(int id);
  int GetWhereID();
  
  void SetDesc(string s);
  string GetDesc();
  
  Inventory GetInv();
};
////////////////////////////////////////////////////////////////////////////////
#endif
