////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __SearchCommand_h__
#define __SearchCommand_h__
#include <cstdlib>
#include "GoldFactory.h"
#include "Gold.h"
#include "Game.h"
#include <sstream>
#include "IRenderer.h"
/////

////////////////////////////////////////////////////////////////////////////////
class SearchCommand : public Command
{
friend class CommandFactory;
public:
  SearchCommand( Game *pGame ) : Command(pGame) {}
    void Execute()
  {
    if ( rand()%1000 < 436 )
    {
      GoldFactory f;
      int npMoney;
	  Gold *g = f.Create( 1+rand()%100 );
	  
      std::ostringstream s;
     s << "You found " << g->GetAmount() << " gold!\n";
	 
     GetGame()->GetRenderer()->Render(s.str());
	 GetGame()->GetPlayer().pMoney+=g;
     delete g;
    }
    else {
      GetGame()->GetRenderer()->Render( "You found nothing.\n");
   }
  }

};
////////////////////////////////////////////////////////////////////////////////
#endif
