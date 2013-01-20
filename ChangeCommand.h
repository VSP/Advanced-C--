////////////////////
/// C++ Advanced
/// Adventure Game 3
/// 
/// Ville Peltola
////////////////////
#ifndef __ChangeCommand_h__
#define __ChangeCommand_h__
////////////////////////////////////////////////////////////////////////////////
#include "Command.h"
#include "Weapons.h"
#include "Player.h"
#include "Game.h"


class Game;
//class Player;

////////////////////////////////////////////////////////////////////////////////
class ChangeCommand  : public Command
{
private:
	WeaponsE weapon;
public:
  ChangeCommand( Game *pGame ) : Command(pGame) { }
  void SetWeapon( WeaponsE wep ) { weapon = wep; }
  WeaponsE GetWeapon() const { return weapon; }
  void Execute();

};
////////////////////////////////////////////////////////////////////////////////
#endif
