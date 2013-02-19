#include "Inventory.h"

Inventory::~Inventory()
{
	for(std::map<std::string, Item*>::iterator it = inventory.begin(); it != inventory.end();++it)
		if(it->second) delete it-> second;
		
	inventory.clear();
}

void
Inventory::RemoveItem(const string& name)
{
	std::map<std::string, Item*>::iterator it = inventory.find(name);
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
	std::map<std::string, Item*>::iterator it = inventory.find(name);
	if(it!=inventory.end()) return it->second;
	else return NULL;
}
void
Inventory::RenderAll()
{
	for(std::map<std::string, Item*>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		cout << it->first;
		cout <<"\n";
	}
	cout << inventory.size();
	
}
