#include "Enemy.h"

Enemy::Enemy()         
  {
	
    SetHitpoints(ENEMY_DEFAULT_HITPOINTS) ;
	Aggro = false;
	CanMove = true;
	CanAct = false;
	Inactive = false;
  }
  Enemy::~Enemy()
  {
  
  }
  bool 
  Enemy::IsAlive()
  {
	return (GetHitpoints()>0);
  }
  
  void 
  Enemy::Attack( GameObject *pObject )
  {
    int hp = pObject->GetHitpoints();
    if ( (rand() % 10) < 3 )
    {
      // TODO: convert this into weapon 
      // with damage property. Can you do it? Is so, explain in your learning diary how.
      pObject->SetHitpoints(hp-1); 
      cout << GetName() << " hits!\n";
    }
    else
      cout << GetName() << " misses!\n";
  }
 void 
 Enemy::Update()
{
	if(IsAlive() && Inactive==false)
	{
	CheckRoom();
	if(Aggro == false && CanMove== true)
	{
		
		Move(South);
		
	}
	else if(Aggro ==true&&CanAct == true )
	{
	  std::ostringstream s;
      Player & player = GetGame()->GetPlayer();
      s << GetName() << " attacks " << player.GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());

      Attack(&player);
	}
	
	else if(CanAct == false && Aggro==true)
	{
		CanAct = true;
	}

    }
	else if(IsAlive()==false&&Inactive == false)
	{
		GetGame()->GetRenderer()->Render("The enemy dies! You are victorious!\n");
		
		//GetGame()->GetCurrentRoom()->SetDescription(GetGame()->GetPlayer().GetDesc());
		Inactive = true;
	}
}
Room* 
Enemy::GetRoom()
{
	return mRoom;
}
void
Enemy::SetRoom(Room* MRoom)
{
	mRoom = MRoom;
}
void 
Enemy::Move(Direction direction)
{
		
		Room* isnow = GetRoom();
		Room* next = isnow->GetNextRoom(direction);
		if(next)
		{
		  SetRoom(next);
		  cout << " Patrol moves south ";
	    }
}
void 
Enemy::SetGame( Game * pGame ){m_pGame=pGame;}
////////////////////
Game * 
Enemy::GetGame() {return m_pGame;}
//////////////
void
Enemy::CheckRoom()
{
	
	if(GetGame()->GetCurrentRoom() == GetRoom())
	{
		if(Aggro == false)
		{
		GetGame()->GetRenderer()->Render("A wild enemy appears before you! it looks angry!\n");
		GetGame()->GetPlayer().SetDesc(GetGame()->GetCurrentRoom()->GetDescription());
		}
		Aggro = true;
	}
		
	else
		Aggro = false;
}