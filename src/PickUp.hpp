//
// Lambo.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Fri Jun  2 09:40:43 2017 Simon RAGUIN
// Last update Fri Jun 16 15:41:56 2017 Simon RAGUIN
//

#ifndef PICKUP_HPP
# define PICKUP_HPP

#include "Car.hpp"

class PickUp : public Car
{
public:
  PickUp(irr::IrrlichtDevice *device, LibContainer *lib) :
    Car(device, lib, "../resources/models/pickup/pcikup.obj", 1., 1., 1., "Pickup")
  {
  }
  ~PickUp();
};

#endif
