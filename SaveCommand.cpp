#include "SaveCommand.h"
#include "Player.h"
#include "Game.h"
#include "Room.h"
#include "GameObject.h"
#include "enemy.h"
#include <fstream>
////////

////////////////////////////////////////////////////////////////////////////////
void SaveCommand::Execute()
{
  ofstream saveFile;
  saveFile.open ("save.txt");
  
  saveFile << "#player "<<GetGame()->GetPlayer().GetName() << "\n";
  saveFile << GetGame()->GetPlayer().GetRace() << "\n";
  saveFile << GetGame()->GetPlayer().GetClass() << "\n";
  saveFile << GetGame()->GetPlayer().GetAge() << "\n";
  saveFile << GetGame()->GetPlayer().GetGender() << "\n";
  saveFile << GetGame()->GetPlayer().GetExperience() << "\n";
  saveFile << GetGame()->GetCurrentRoom()->GetID();
  
  
  //saveFile << enemy.IsAlive() << "\n";
  saveFile.close();
  
  GetGame()->GetRenderer()->Render("Saved\n");
}
////////////////////////////////////////////////////////////////////////////////
