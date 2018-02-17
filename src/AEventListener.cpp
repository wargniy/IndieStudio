//
// AEventListener.cpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Wed May 31 08:10:45 2017 Eloi Brehin
// Last update Tue Jun  6 15:05:10 2017 Eloi Brehin
//

#include "AEventListener.hpp"

AEventListener::AEventListener()
{
}

AEventListener::~AEventListener()
{
}

void	AEventListener::setLib(LibContainer *lib)
{
  this->lib = lib;
}

void	AEventListener::setContext(SAppContext *context)
{
  this->context = context;
}

LibContainer	*AEventListener::getLib()
{
  return (this->lib);
}

AContext	*AEventListener::getContext()
{
  return (this->context);
}
