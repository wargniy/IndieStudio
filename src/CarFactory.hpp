//
// CarFactory.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Wed Jun 14 09:47:41 2017 Simon RAGUIN
// Last update Fri Jun 16 13:58:52 2017 Simon RAGUIN
//

#include <map>
#include "Mustang.hpp"
#include "PickUp.hpp"
#include "LibContainer.hpp"

class	CarFactory
{
private:
  typedef Car *(CarFactory::*ptr)(LibContainer *lib, irr::IrrlichtDevice *device);
  std::map<std::string, ptr> container;
public:
  Car	*createCar(const std::string type,
		   LibContainer *lib,
		   irr::IrrlichtDevice *device);
  CarFactory();
  ~CarFactory();
public:
  Car	*createMustang(LibContainer *lib, irr::IrrlichtDevice *device);
  Car	*createPickUp(LibContainer *lib, irr::IrrlichtDevice *device);
};
