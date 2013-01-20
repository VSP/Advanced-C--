///////////////////////////
/// C++ Advanced
/// Adventure Game 3
/// 
/// Ville Peltola
//////////////////////////
#include "InventoryCommand.h"
#include "sstream"
//////////////////////////
void 
InventoryCommand::Execute()
{

	
	
	std::ostringstream s;
	GetGame()->GetRenderer()->Render("\nYou have a sword, an axe and a dagger\n");
	s << "You have " << GetGame()->GetPlayer().pMoney.GetAmount() << " gold!\n";
    GetGame()->GetRenderer()->Render(s.str());
	
	
}
/////////////////////////////7