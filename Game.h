////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Game_h__
#define __Game_h__
////////////////////////////////////////////////////////////////////////////////
class IRenderer;
class Room;
////////////////////////////////////////////////////////////////////////////////
enum RoomId { kDungeon, kHallway, kMonster, kChambers, kNPC, kNumRooms };
#include "Player.h"
#include "Enemy.h"
#include "TemplateRenderer.h"
////////////////////////////////////////////////////////////////////////////////


class Game 

{

private:
  bool running;
  Player player;
  TemplateRenderer *trenderer;
  IRenderer * renderer;
  IRenderer & r;
  Room      *rooms[kNumRooms]; ///< Map.
  Room      *currentRoom;
public:
  Game();
  virtual ~Game();
  void Play();
  void SetRenderer( IRenderer *pRenderer );
  IRenderer * GetRenderer() const;
  IRenderer & GetR() const;
  bool IsRunning() const;
  void SetRunning(bool bFlag ) ;
  Player & GetPlayer();
  Room * GetCurrentRoom();
  void SetCurrentRoom( Room *pRoom );
  
  
  
};
////////////////////////////////////////////////////////////////////////////////
#endif
