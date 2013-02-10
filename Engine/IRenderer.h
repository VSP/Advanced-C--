////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __IRenderer_h__
#define __IRenderer_h__
////////////////////////////////
#include <iostream>
////////////////////////////////////////////////////////////////////////////////

class IRenderer 
{
public:
  virtual void Render( const std::string & str ) = 0;

};
template <class TYPE>
IRenderer& operator<<(IRenderer & test, TYPE & str)
 {
    std::cout << str;
	return test;
 }
////////////////////////////////////////////////////////////////////////////////
#endif
