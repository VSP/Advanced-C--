////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Module 2 
/// Ville-Santeri Peltola
////////////////////
#ifndef __SaveCommand_h__
#define __SaveCommand_h__
////////////////////////////////////////////////////////////////////////////////
#include "Command.h"
class Game;
#include "Dungeon.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
class SaveCommand  : public Command
{
public:
  SaveCommand( Game *pGame ) : Command(pGame) { }

  
  void Execute();
 };
 ////////////////////////////////////////////////////////////////////////////////
 #endif