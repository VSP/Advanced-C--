#ifndef __TemplateRenderer_h__
#define __TemplateRenderer_h__
////////////////////////////////
#include <iostream>
////////////////////////////////////////////////////////////////////////////////

class TemplateRenderer
{
public:
  TemplateRenderer(){}
  ~TemplateRenderer(){}
  template<typename TYPE>
  TYPE Render(TYPE tests)
  {
	std::cout <<tests;
  }

};
#endif