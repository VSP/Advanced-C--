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
class Game;

////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
friend class ChangeCommand;
friend class SearchCommand;
friend class InventoryCommand;
friend class SaveCommand;
friend class NPCRoom;
friend class TalkCommand;

private:
  Game *game;
  int whereID;
  Gold pMoney; 
  int  pWeapon;
  bool tDistance;
  
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
  
};
////////////////////////////////////////////////////////////////////////////////
#endif
