#include "AttackCommand.h"
#include "Game.h"
#include "Room.h"
////////////////////////////////////////////////////////////////////////////////
void AttackCommand::Execute()
{

for(auto enemy: GetGame()->GetEnemies())
{
  if ( enemy->IsAlive() && enemy->Aggro==true)
    {
      Player & player = GetGame()->GetPlayer();
      std::ostringstream s;
      s << player.GetName() << " attacks " << enemy->GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());
      player.Attack( enemy );
      // Change room description a bit
	  
      if (enemy->IsAlive() == false )
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
