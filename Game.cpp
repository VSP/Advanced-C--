 ////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "Game.h"
#include "Player.h"
#include "GoldFactory.h"
#include "Gold.h"
#include "QuitCommand.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "TextRenderer.h"
#include <sstream>
#include "IRenderer.h"
#include "CommandFactory.h"
#include "Dungeon.h"
#include "Hallway.h"
#include "MonsterRoom.h"
#include "NPC_Room.h"
#include "Chambers.h"
#include "globals.h"
#include "Exceptions.h"
#include "Enemy.h"
#include <ctime>
#include <string>

////////////////////////////////////////////////////////////////////////////////
using namespace std;
#define DEV_NAME "anssi.grohn@pkamk.fi"
#define YEAR 2013

////////////////////////////////////////////////////////////////////////////////
Game::Game() : running(true), r(*new TextRenderer)
{
  renderer =new TextRenderer;
  


  rooms[kDungeon] = new Dungeon();
  rooms[kDungeon]->SetGame(this);

  rooms[kHallway] = new Hallway();
  rooms[kHallway]->SetGame(this);

  rooms [kNPC] = new NPCRoom();
  rooms [kNPC]->SetGame(this);
  
  rooms[kMonster] = new MonsterRoom();
  rooms[kMonster]->SetGame(this);
  
  rooms[kChambers] = new Chambers();
  rooms[kChambers]->SetGame(this);

  rooms[kDungeon]->SetNextRoom(North,rooms[kHallway]);

  rooms[kHallway]->SetNextRoom(South,rooms[kDungeon]);
  rooms[kHallway]->SetNextRoom(North,rooms[kNPC]);
  
  rooms[kNPC]->SetNextRoom(South,rooms[kHallway]);
  rooms[kNPC]->SetNextRoom(North,rooms[kMonster]);
  
  rooms[kMonster]->SetNextRoom(South,rooms[kNPC]);
  rooms[kMonster]->SetNextRoom(North,rooms[kChambers]);

  rooms[kChambers]->SetNextRoom(South,rooms[kMonster]);
  
  currentRoom = rooms[kDungeon];

  
  //enemy = new Enemy(dynamic_cast<Game*>GetGame()));
  //enemy->SetEnemy(rooms[kMonster]);
  s = new Scene();
  s->SetGame(this);
  
  eGuard = new Enemy();
  eGuard->SetGame(this);
  eGuard->SetName("Orc Guard");
  eGuard->CanMove=false;
  eGuard->SetRoom(rooms[kMonster]);
  s->GetUpdateables().push_back(eGuard);
  e.push_back(eGuard);
  ePatrol = new Enemy();
  ePatrol->SetGame(this);
  ePatrol->SetName("NinjaPirate");
  ePatrol->SetRoom(rooms[kMonster]);
  s->GetUpdateables().push_back(ePatrol);
  e.push_back(ePatrol);
}
////////////////////////////////////////////////////////////////////////////////
Game::~Game()
{

}
///////////////////////////////////////////////////////////////

/////////////////
void Game::Play()
{
  string cmd;
  
  renderer->Render("Welcome to Fiends'n'Frogs adventure game!\n");
  ostringstream s;
  s << "by " << DEV_NAME << "(c) " << YEAR << ". Licensed under GPLv3.\n";
  renderer->Render(s.str());
  renderer->Render("type load to load any else button to chart a new\n");
  getline(cin,cmd);
  if(cmd == "load")
  {
	r <<"Load Started\n";
	Player::Load(player);
  }
  else
	Player::AskInfo(player);
	
  renderer->Render("\nPlayer statistics:\n\n");
  player.PrintSummary();
  player.SetGame(this);
  if(cmd =="load")
  {
  renderer->Render("\nAnd behold, the adventure continues!\n");
  }
  else
	renderer->Render("\nAnd behold, the adventure begins!\n");
	
  //player.SetGame(this);
  if(cmd =="load")
  {
	//cout << player.whereID;
  	if(player.GetWhereID()==3)
	{
		//cout << player.whereID;
		SetCurrentRoom(rooms[kDungeon]);
		//cout << player.whereID;
		//currentRoom = rooms[kMonster];
	}	
	else if(player.GetWhereID()==2)
	{
		SetCurrentRoom(rooms[kHallway]);
	}	
	else if(player.GetWhereID()==1)
	{
		//cout << player.whereID;
		currentRoom = rooms[kMonster];
		//cout << player.whereID;
	}	
	else if(player.GetWhereID()==4)
	{
		SetCurrentRoom(rooms[kChambers]);
	}	
  }
  srand(time(NULL));
 
  while(running)
  {
	//cout << player.whereID;

	//cout << player.whereID;
    renderer->Render(GetCurrentRoom()->GetDescription());
	
    renderer->Render("\n> ");
	
	
    getline(cin,cmd);
	
	try
	{
		//Make this a bit better
		if(cmd == "search"||cmd == "drink potion"||cmd == "talk"||cmd =="quit"||cmd =="attack"||cmd =="move north"||cmd =="move south"||cmd =="save"||cmd =="equip dagger"||cmd =="equip sword"||cmd =="equip axe"||cmd =="inventory")
		{
		
		CommandFactory comm(this);
		ICommand *pCommand = comm.Create( cmd ); 
		if ( pCommand ) pCommand->Execute();
		delete pCommand;
		}
		else
		{
		 throw UCMD("Say again?\n");;
		}
	}catch(UCMD & e){
		renderer->Render(e.what());
	}
	
	
  //  CommandFactory comm(this);
   // ICommand *pCommand = comm.Create( cmd ); 
   // if ( pCommand ) pCommand->Execute();
   // delete pCommand;
	Update();
    GetCurrentRoom()->Update();
	
       try 
		{
	
		if (player.GetHitpoints() <=0)
			throw DeadPCError("PC is very dead :(");
	
	}catch (DeadPCError & e){
		renderer->Render(e.what());
		SetRunning(false);
		
	}
  
  }
  // final message to player
  getline(cin,cmd);
  renderer->Render("Exiting, bye!\n");
  
}
////////////////////////////////////////////////////////////////////////////////
void
Game::SetRenderer( IRenderer *pRenderer )
{
  renderer = pRenderer;
}
////////////////////////////////////////////////////////////////////////////////
IRenderer * 
Game::GetRenderer() const
{
  return renderer;
}
////////////////////////////////////////////////////////////////////////////////
bool
Game::IsRunning() const
{
  return running;
}
////////////////////////////////////////////////////////////////////////////////
void
Game::SetRunning( bool bFlag ) 
{
  running = bFlag;
}
////////////////////////////////////////////////////////////////////////////////
Player & 
Game::GetPlayer()
{
  return player;
}
////////////////////////////////////////////////////////////////////////////////

Room *
Game::GetCurrentRoom()
{
  return currentRoom;
}
////////////////////////////////////////////////////////////////////////////////
void 
Game::SetCurrentRoom( Room *pRoom )
{
  currentRoom = pRoom;
}
//////////////////////////////////////////////////////////

//////////////////////
IRenderer & 
Game::GetR() const
{
	return r;
}
////////

void
Game::Update()
{
	s->Update();
}

Enemy *
Game::GetEnemy()
{
	return eGuard;
}

