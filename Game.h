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
class Enemy;
////////////////////////////////////////////////////////////////////////////////
enum RoomId { kDungeon, kHallway, kMonster, kChambers, kNPC, kNumRooms };
#include "Player.h"
#include "Enemy.h"
//#include "Scene.h"
#include <list>
#include <vector>
////////////////////////////////////////////////////////////////////////////////
typedef vector<Enemy*> Enemies;
//class Wandering_Monster;

class Scene;
class Game 

{

private:
  Scene *s;
  bool running;
  Player player;
  
  Enemies e;
  Enemy *eGuard;
  Enemy *ePatrol;
  IRenderer * renderer;
  IRenderer & r;
  Room      *rooms[kNumRooms]; ///< Map.
  Room      *currentRoom;
  
public:
  Game();
  virtual ~Game();
 
  void Play();
  void Update();
  Enemies& GetEnemies(){return e;}
  void SetRenderer( IRenderer *pRenderer );
  IRenderer * GetRenderer() const;
  IRenderer & GetR() const;
  bool IsRunning() const;
  void SetRunning(bool bFlag ) ;
  Player & GetPlayer();
  Room * GetCurrentRoom();
  void SetCurrentRoom( Room *pRoom );
  Enemy * GetEnemy();
  
  
  //Scene*GetScene();
  
  
};
////////////////////////////////////////////////////////////////////////////////
#endif
