//
// Mustang.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Wed May 31 09:58:50 2017 Simon RAGUIN
// Last update Fri Jun 16 11:43:11 2017 Simon RAGUIN
//

#ifndef MUSTANG_HPP
# define MUSTANG_HPP

#include "Car.hpp"

class	Mustang : public Car
{
public:
  Mustang(irr::IrrlichtDevice *device, LibContainer *lib) :
    Car(device, lib, "../resources/PoliceCar.3DS", 1., 1., 1., "Mustang")
  {
  }
  ~Mustang();
};

#endif
