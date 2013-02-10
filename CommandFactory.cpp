////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "CommandFactory.h"
#include "QuitCommand.h"
#include "SearchCommand.h"
#include "AttackCommand.h"
#include "UnknownCommand.h"
#include "SaveCommand.h"
#include "MoveCommand.h"
#include "ChangeCommand.h"
#include "InventoryCommand.h"
#include "TalkCommand.h"
#include "Game.h"
#include <sstream>
#include <string>
#include <iostream>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
ICommand * 
CommandFactory::Create( const std::string & str )
{
  std::istringstream s(str);
  std::string word;
  s >> word;

  
  if ( word == "talk")
  {
    return new TalkCommand(m_pGame);
  }
  if ( word == "quit" )
  {
    return new QuitCommand(m_pGame);
  }
  
  if ( word == "search")
  {
    return new SearchCommand(m_pGame);
  }
  
  if ( word == "attack" )
  {
    return new AttackCommand(m_pGame);
  }
  if ( word =="save")
  {
	return new SaveCommand (m_pGame);
  }
  if (word =="inventory")
  {
   return new InventoryCommand (m_pGame);
  }

  if ( word == "move" )
  {
    string dir;
    s >> dir;
    //cout << "got dir '" << dir << "'\n";
    MoveCommand *command = NULL;
    if ( dir == "north" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(North);
      return command;
    }
    else if ( dir == "south" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(South);
      return command;
    }
    else if ( dir == "east" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(East);
      return command;
    }
    else if ( dir == "west" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(West);
      return command;
    }

  }
  if (word =="equip")
  {
   string wep;
   s >> wep;
   ChangeCommand *command = NULL;
   if (wep =="dagger")
   {
	command = new ChangeCommand(m_pGame);
	command->SetWeapon(Dagger);
	return command;
   }
   else if (wep =="sword")
   {
    command = new ChangeCommand(m_pGame);
	command->SetWeapon(Sword);
	return command;
   }
   else if (wep =="axe")
   {
   	command = new ChangeCommand(m_pGame);
	command->SetWeapon(Axe);
	return command;
   }
  }

  return new UnknownCommand(m_pGame);  
}
////////////////////////////////////////////////////////////////////////////////
