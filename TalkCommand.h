////////////////////////////////////////////////////////////////////////////////
#ifndef __TalkCommand_h__
#define __TalkCommand_h__
#include "Command.h"
////////////////////////
/*
template <class X>
class Test
{
private:
X x;
public:

template<class X, class Y ,class Z>
Test<X> Plus(const Test<Y>& y , const Test<Z>& z)
{
	return Test<X>(y.x+z.x)
}

}
*/

class TalkCommand : public Command
{
friend class CommandFactory;
public:

  TalkCommand( Game *pGame ) : Command(pGame) {}
    void Execute()
  {
  double number1, number2;
	if (GetGame()->GetPlayer().tDistance == false)
	{
		GetGame()->GetRenderer()->Render("You are all alone...");
	}
	else
	{
		GetGame()->GetRenderer()->Render("The dark stranger turns toward you. And starts talking about his adventureing life\n");
		//GetGame()->GetRenderer()->Render("What is your number one?\n");
		//cin >> number1;
		//GetGame()->GetRenderer()->Render("What is thous number two?\n");
		//cin >> number2;
		
//GetGame()->GetRenderer()->Render(Plus<double>(number1,number2));
		
	}
  }

};
#endif