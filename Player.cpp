////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#include "Player.h"
#include "Game.h"
#include "IRenderer.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>


using namespace std;
////////////////////////////////////////////////////////////////////////////////
Player::Player()
{
  
  tDistance = false;
  //Item *s = new Item();
  Item *wD = new Item(1,1);
  Item *wS = new Item(2,1);
  Item *wA = new Item(5,1);
  
  Item *pP1 = new Item(3);

  //s->name ="Axe";
  //s-> wDmg=5;
  AddItem("Sword", wS);
  AddItem("Axe", wA);
  AddItem("Dagger", wD);
  AddItem("Potion", pP1);

  map<const string,int >StatMap{{"Stamina",3},{"Dex",1}};
  SetHitpoints(3);
}
////////////////////////////////////////////////////////////////////////////////
Player::~Player()
{
  
}
////////////////////////////////////////////////////////,////////////////////////
void
Player::Attack( GameObject *pObject )
{
  int hp = pObject->GetHitpoints();
  if ( (rand() % 100) < 63 )
  {
    // convert this into weapon 
    // with damage property
    pObject->SetHitpoints(hp-pWeapon); 
    ostringstream s;
    s << GetName() << " hits!\n";
    game->GetRenderer()->Render( s.str() );
  }
  else
  {
    ostringstream s;
    s << GetName() << " misses!\n";
    game->GetRenderer()->Render( s.str() );
  }
}
////////////////////////////////////////////////////////////////////////////////
void 
Player::PrintSummary()
{

  cout << "Name:" << GetName() << "\n";
  cout << "Race: " <<  GetRace() << "\n";
  cout << "Class: " << GetClass() << "\n";
  cout << "age: " << GetAge() << "\n";
  cout << "gender: " << GetGender() << "\n";
  cout << "experience: " << GetExperience() << "\n";
}
////////////////////////////////////////////////////////////////////////////////
void
Player::AskInfo( Player & p)
{
  ifstream f("playerdata.txt");
  while ( !f.eof()  )
  {
    string line;
    f >> line;
    if ( line == "#player")
    {
      int iTmp;
      string strTmp;
      char g;
      f >> strTmp; p.SetName(strTmp); 
      f >> strTmp; p.SetRace(strTmp);
      f >> iTmp; p.SetClass((Class)iTmp);
      f >> iTmp; p.SetAge(iTmp);
      f >> g; p.SetGender( (g == 'm' ? Male : Female) );
      f >> iTmp; p.SetExperience(iTmp);
      
    }

    /*
  cout << "\nPlease enter your details:\n\n";
  cout << "Your name:"; cin >> p.name;
  cout << "Race: "; cin >> p.race;
  int c;
  cout << "Class: ";cin >> c; p.myClass = (Class)c;
  cout << "age: "; cin >> p.age;
  char g;
  cout << "gender: "; cin >> g; p.gender = g == 'm' ? Male : Female;
  p.experience = 0;*/
  }
}
////////////////////////////////////////////////////////////////////////////////
void 
Player::Load (Player & p)
{
  ifstream f("save.txt");
 
  while ( !f.eof()  )
  {
    string line;
    f >> line;
    if ( line == "#player")
    {
      int iTmp;
      string strTmp;
      char g;
      f >> strTmp; p.SetName(strTmp); 
	  
      f >> strTmp; p.SetRace(strTmp);
	  
      f >> iTmp; p.SetClass((Class)iTmp);
	  
      f >> iTmp; p.SetAge(iTmp);
	  
      f >> g; p.SetGender( (g == 'm' ? Male : Female) );
	  
      f >> iTmp; p.SetExperience(iTmp);
      
	  f >> iTmp; p.SetWhereID(iTmp);
	  
	  f >> iTmp; p.pMoney.SetAmount(iTmp);
    }
	}
	f.close();
}

void 
Player::SetGame( Game * game )
{ 
  this->game = game;
}
////////////////////////////////////////////////////////////////////////////////
void 
Player::SetWhereID(int id)
{
	whereID = id;
}
int 
Player::GetWhereID()
{
	return whereID;
}
/////////////////////
void
Player::SetDesc(string s)
{
	roomdesc = s;
}
//////////////////////////////////////////////////////
string
Player::GetDesc()
{
	return roomdesc;
}
