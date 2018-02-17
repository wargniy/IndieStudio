//
// CarFactory.cpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Wed Jun 14 09:58:55 2017 Simon RAGUIN
// Last update Fri Jun 16 13:59:13 2017 Simon RAGUIN
//

#include "CarFactory.hpp"

CarFactory::CarFactory()
{
  this->container["Mustang"] = &CarFactory::createMustang;
  this->container["Pickup"] = &CarFactory::createPickUp;
}

CarFactory::~CarFactory()
{
}

Car	*CarFactory::createCar(const std::string type,
			       LibContainer *lib,
			       irr::IrrlichtDevice *device)
{
  return ((this->*this->container[type])(lib, device));
}

Car	*CarFactory::createMustang(LibContainer *lib, irr::IrrlichtDevice *device)
{
  return (new Mustang(device, lib));
}

Car	*CarFactory::createPickUp(LibContainer *lib, irr::IrrlichtDevice *device)
{
  return (new PickUp(device, lib));
}
