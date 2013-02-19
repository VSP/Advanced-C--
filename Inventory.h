#ifndef __Inventory_h__
#define __Inventory_h__

#include <map>
#include <sstream>
#include <iostream>
#include "Item.h"
#include "Axe.h"
#include "Sword.h"
#include <iterator>
using namespace std;

//struct Item {std::string name, int wDmg};

//typedef std::map<std::string, Item*> inventory;
class Inventory
{
friend class DrinkCommand;
friend class InventoryCommand;
protected:
	std::map<std::string, Item*> inventory;

public:
	Inventory(){}
	virtual ~Inventory();
	void RemoveItem(const string& name);
	void AddItem(const string& name, Item* pItem);
	Item* Find(const string&name);
	void RenderAll();
	

};

#endif
