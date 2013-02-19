///////////////////////////
/// C++ Advanced
/// Adventure Game 3
/// 
/// Ville Peltola
//////////////////////////
#include "InventoryCommand.h"
#include "sstream"
#include "Inventory.h"
#include <string>
#include <map>
#include <iostream>

#include <iterator>

//////////////////////////
void 
InventoryCommand::Execute()
{
	GetGame()->GetRenderer()->Render("You have: \n");
	
	GetGame()->GetPlayer().RenderAll();
	std::ostringstream s;
	//GetGame()->GetRenderer()->Render("\nYou have a sword, an axe and a dagger\n");
	
	s << "You have " << GetGame()->GetPlayer().pMoney.GetAmount() << " gold!\n";
    GetGame()->GetRenderer()->Render(s.str());
	
	
}
/////////////////////////////7