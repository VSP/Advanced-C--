#include "AttackCommand.h"
#include "Game.h"
#include "Room.h"
////////////////////////////////////////////////////////////////////////////////
void AttackCommand::Execute()
{
for(int i=0; i<GetGame()->GetEnemies().size();i++)
{
  if ( GetGame()->GetEnemies().at(i)->IsAlive() && GetGame()->GetEnemies().at(i)->Aggro==true)
    {
      Player & player = GetGame()->GetPlayer();
      std::ostringstream s;
      s << player.GetName() << " attacks " << GetGame()->GetEnemies().at(i)->GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());
      player.Attack( GetGame()->GetEnemies().at(i) );
      // Change room description a bit
	  
      if ( GetGame()->GetEnemies().at(i)->IsAlive() == false )
      {
		//SetDescription("You are in the monster room. There is a pretty dead orc here.");
      }
    } 
    //else 
   //{
      // to encourage player to stop beating it further
     // GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
   // }
}
}
////////////////////////////////////////////////////////////////////////////////
