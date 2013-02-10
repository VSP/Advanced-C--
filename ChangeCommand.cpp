///////////////////////////
/// C++ Advanced
/// Adventure Game 3
/// 
/// Ville Peltola
//////////////////////////
#include "ChangeCommand.h"
#include "TextRenderer.h"
#include "Weapons.h"
#include "IRenderer.h"
//////////////////////////

void 
ChangeCommand::Execute()
{
Weapons w;

	if (weapon == Dagger)
		{
		GetGame()->GetPlayer().pWeapon=w.wDagger;
		GetGame()->GetR() << "\nYou are now wielding a dagger\n";
		}
	else if (weapon == Sword)
		{	
		GetGame()->GetPlayer().pWeapon=w.wSword;
		GetGame()->GetRenderer()->Render("\nYou are now wielding a sword\n");
		}
	else if(weapon == Axe)
		{
		GetGame()->GetPlayer().pWeapon=w.wBigAssAxe;
		GetGame()->GetRenderer()->Render("\nYou are now wielding an axe\n");
		}
delete &w;

}
/////////////////////////////7