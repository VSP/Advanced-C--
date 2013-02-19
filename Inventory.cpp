#include "Inventory.h"

Inventory::~Inventory()
{
	for(auto item : inventory)
		if(item.second) delete item.second;
		
	inventory.clear();
}

void
Inventory::RemoveItem(const string& name)
{
	auto it = inventory.find(name);
	delete it->second;
	inventory.erase(it);

}
void
Inventory::AddItem(const string& name, Item* pItem)
{
	//pItem->SetItem(this);
	inventory.insert(make_pair(name, pItem));

}

Item* 
Inventory::Find(const string& name)
{
	auto it = inventory.find(name);
	if(it!=inventory.end()) return it->second;
	else return NULL;
}
void
Inventory::RenderAll()
{
	for(auto item : inventory)
	{
		cout << item.first;
		cout <<"\n";
	}
	cout << inventory.size();
	
}
