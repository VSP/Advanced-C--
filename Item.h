#ifndef __Item_h__
#define __Item_h__

//struct Item {std::string name; int wDmg;};

class Item

{
friend class Player;
protected:
	int wDmg;
	int wSpeed;
	int hpGain;

public:
	Item(int GAIN){hpGain = GAIN;}
	Item(int DMG, int SPEED){ wDmg=DMG; wSpeed=SPEED;}
	
	~Item(){}
	//void SetItem(Item*item){}

};

//*/

#endif