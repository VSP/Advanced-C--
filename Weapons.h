////////////////////
/// C++ Advanced
/// Adventure Game 3
///  
/// Ville-Santeri Peltola
////////////////////

#ifndef __Weapons_h__
#define __Weapons_h__
/////////////////////
//#include "ChangeCommand.h"

enum WeaponsE{Dagger,Sword,Axe};

class Weapons
{
friend class ChangeCommand;
friend class Player;
private:
	static int const wDagger=1;
	static int const wSword=2;
	static int const wBigAssAxe=5;

	
};

#endif