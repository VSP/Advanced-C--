////////////////////
#ifndef __NPCRoom_h__
#define __NPCRoom_h__
#include "Room.h"
#include "Enemy.h"
#include <sstream>
#include "MoveCommand.h"
////////////////////////////////////////////////////////////////////////////////
class NPCRoom : public Room
{
private:
  Enemy npc;
  bool noticedPlayer;
  bool isAggroed;
  int ID;
public:
  NPCRoom()
  {
	SetID(5);
	isAggroed = false;
    noticedPlayer = false;
    npc.SetName( "Stranger");
    SetDescription("You are in an empty room, Suddenly a dark stranger emerges from the shadow. You torch flickers as if recognizing the figure. Stranger doesn't seem to notice you");
  }
  ////////////////////
  /// Makes enemy attack player once on every turn.
  void Update()
  {
	GetGame()->GetPlayer().tDistance = true;
    if ( npc.IsAlive() && noticedPlayer && isAggroed)
    {
      std::ostringstream s;
      Player & player = GetGame()->GetPlayer();
      s << npc.GetName() << " attacks " << player.GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());

      npc.Attack(&player);

    }
    noticedPlayer = true;
	SetDescription("The old man is staring at the wall");
  }
  
  Room * OnMoveCommand( MoveCommand *pCommand )
  {
    if ( npc.IsAlive()&&isAggroed)
    {
      return NULL;
    }
    else
	  GetGame()->GetPlayer().tDistance = false; 
      return GetNextRoom( pCommand->GetDirection() );
  }
  
  void OnAttack( AttackCommand *pCommand )
  {
    if ( npc.IsAlive() && noticedPlayer)
    {
      Player & player = GetGame()->GetPlayer();
      std::ostringstream s;
      s << player.GetName() << " attacks " << npc.GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());
      player.Attack( &npc );
      // Change room description a bit
      if ( npc.IsAlive() == false )
      {
	SetDescription("You are in the empty room. Bloody robe significes that a man once was here");
      }
    } 
    else 
    {
      // to encourage player to stop beating it further
      GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
    }

  }

};
////////////////////////////////////////////////////////////////////////////////
#endif