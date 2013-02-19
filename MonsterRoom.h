////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __MonsterRoom_h__
#define __MonsterRoom_h__
#include "Room.h"
#include "Enemy.h"
#include <sstream>
#include "MoveCommand.h"
#include <vector>
#include "Scene.h"
/////////////////////////////////////////////
//typedef vector<Enemy > EList;
////////////////////////////////////////////////////////////////////////////////
class MonsterRoom : public Room
{
private:
  
  

  bool noticedPlayer;
  int ID;
public:
  MonsterRoom()
  {
	
	SetID(1);
	
	
	
    SetDescription("You are in the monster room. bones etc.");
  }
  
  ////////////////////
  /// Makes enemy attack player once on every turn.
  void Update(){}
  /*
  {
    if ( evec.at(0).IsAlive() && noticedPlayer )
    {
      std::ostringstream s;
      Player & player = GetGame()->GetPlayer();
      s << evec.at(0).GetName() << " attacks " << player.GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());

      evec.at(0).Attack(&player);

    }
    noticedPlayer = true;
  }
  */
  /*
  ////////////////////
  /// Restricts movement until enemy is killed.
  /// \param pCommand Move command.
  /// \return Room pointer to next available room, NULL if none available.
  Room * OnMoveCommand( MoveCommand *pCommand )
  {
    if ( evec.at(0).IsAlive())
    {
      return NULL;
    }
    else
      return GetNextRoom( pCommand->GetDirection() );
  }
  /*
  void OnAttack( AttackCommand *pCommand )
  {
    if ( evec.at(1).IsAlive() && noticedPlayer)
    {
      Player & player = GetGame()->GetPlayer();
      std::ostringstream s;
      s << player.GetName() << " attacks " << evec.at(0).GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());
      player.Attack( &evec.at(1) );
      // Change room description a bit
      if ( evec.at(0).IsAlive() == false )
      {
	SetDescription("You are in the monster room. There is a pretty dead orc here.");
      }
    } 
    else 
    {
      // to encourage player to stop beating it further
      GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
    }

  }
*/
};
////////////////////////////////////////////////////////////////////////////////
#endif



