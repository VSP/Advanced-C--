/////////////////////////////////////////////
#include "Game.h"
#include "Inventory.h"
#include "Player.h"
#include "TextRenderer.h"
#include "DrinkCommand.h"
#include <map>
#include <string>
#include <iostream>
//////////////////////////////////////////////
void DrinkCommand::Execute()
{
  
  
  if(hp)
  {
    //std::map<std::string, Item*>::iterator it = GetGame()->GetPlayer().find("Potion");
	
	if (GetGame()->GetPlayer().Find("Potion")!=NULL)
	{
		
		GetGame()->GetPlayer().RemoveItem("Potion");
		GetGame()->GetRenderer()->Render("You feel healthy!...ish?");
	}
	else
	{
	GetGame()->GetRenderer()->Render("You don't have potions");
	}
  }



}
//////////////////////////////////////////////