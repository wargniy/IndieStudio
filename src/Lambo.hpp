//
// Lambo.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Fri Jun  2 09:40:43 2017 Simon RAGUIN
// Last update Fri Jun 16 11:25:53 2017 Simon RAGUIN
//

#ifndef LAMBO_HPP
# define LAMBO_HPP

#include "Car.hpp"

class Lambo : public Car
{
public:
  Lambo(IrrlichtDevice *device, LibContainer *lib) :
    Car(device, lib, "../irrlicht-1.8.4/media/pcikup.obj", 1., 1., 1., "Lambo")
  {
  }
  ~Lambo();
}
