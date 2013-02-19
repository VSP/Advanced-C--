#ifndef __DrinkCommand_h__
#define __DrinkCommand_h__
#include "Command.h"
#include "globals.h"
////////////////////////////////////////////////////////////
////////////////////

enum Potion{mp,hp};

class DrinkCommand : public Command 
{
friend class CommandFactory;
private:
  Potion potion; 
public:
  DrinkCommand( Game *pGame ) : Command(pGame) { }

  void SetDrinkWhat( Potion p ) { potion = p; }
  Potion GetPotion() const { return potion; }

  void Execute();

};
////////////////////////////////////////////////////////////////////////////////

#endif
