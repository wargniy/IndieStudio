//
// AEventListener.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Wed May 31 07:58:34 2017 Eloi Brehin
// Last update Fri Jun 16 11:44:07 2017 Simon RAGUIN
//

#ifndef AEVENTLISTENER_HPP_
# define AEVENTLISTENER_HPP_

#include <irrlicht.h>
#include "LibContainer.hpp"
#include "Car.hpp"

class		AEventListener : public irr::IEventReceiver
{
protected:
  SAppContext	*context;
  LibContainer	*lib;

public:
  AEventListener();
  virtual ~AEventListener();

  void		setLib(LibContainer *);
  void		setContext(SAppContext *);
  LibContainer	*getLib();
  AContext	*getContext();
  virtual bool		OnEvent(const irr::SEvent &) = 0;
  virtual bool		keyMapping(const irr::SEvent &) = 0;
};

#endif // !AEVENTLISTENER_HPP_
