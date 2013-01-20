////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Gold_h__
#define __Gold_h__
////////////////////////////////////////////////////////////////////////////////
class GoldFactory;
////////////////////////////////////////////////////////////////////////////////
class Gold 
{
  friend class GoldFactory;
  friend class InventoryCommand;
  friend class Player;
  
private:
	unsigned int m_nAmount;
	Gold(unsigned int nAmount);
	Gold();
public:
	
	virtual ~Gold();
	unsigned int GetAmount() const;
	void SetAmount( unsigned int value );
	Gold& operator+=(const Gold* g)
	{
		m_nAmount += g->GetAmount();
		return *this;
		
	}
};
////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
#endif
