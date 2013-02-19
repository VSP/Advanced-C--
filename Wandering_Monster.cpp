/*
#include "Wandering_Monster.h"
#include "Command.h"

Wandering_Monster::Wandering_Monster()
 {
  evec.push_back(we);
  evec.push_back(we2);
  evec.at(0).SetName("Ninja");
  evec.at(1).SetName("Guard");
  evec.at(1).SetMonster(rooms[kMonster]);
 }
 virtual 
 Wandering_Monster ~Wandering_Monster(){}
 void 
 Wandering_Monster::Move()
 {
	if(evec.at(0).IsAlive()&&Aggro==false)
	{
		if((rand() % 10) < 3)
		{
			Room* dungeon = evec.at(0).GetRoom()->GetNextRoom(South);
			evec.at(0).SetMonster(dungeon);
			cout << "Moved South!";
		}
		else
		{
			//Room* dungeon = evec.at(0).GetRoom()->GetNextRoom(South);
			//evec.at(0).SetMonster(dungeon);
		}
	}

 }
 void 
 Wandering_Monster::Update()
 {
	
	for(int i=0;i<evec.size();i++ )
	{
	if(evec.at(i).GetRoom() == GetGame()->GetCurrentRoom())
	{
		evec.at(i).Aggro= true;
	}
	else
		Aggro = false;
	
	if ( evec.at(i).IsAlive() && Aggro )
    {
      std::ostringstream s;
      Player & player = GetGame()->GetPlayer();
      s << evec.at(i).GetName() << " attacks " << player.GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());

      evec.at(i).Attack(&player);
	}
	 if(evec.at(i).IsAlive)
	 {
		Move();
	 }
    }
	
 }
 */
 