//
// Profile.cpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Mon May 15 10:53:13 2017 Simon RAGUIN
// Last update Sun Jun 18 20:49:56 2017 Eloi Brehin
//

#include "Profile.hpp"

Profile::Profile(const std::string &name) :
  name(name)
{
  this->course = 0;
  this->choosenCar = "Mustang";
}

Profile::~Profile()
{
}

Profile		&Profile::operator=(const Profile &other)
{
  this->setName(other.getName());
  this->setCourse(other.getCourse());
  return (*this);
}

Profile::Profile(const Profile &other)
{
  this->setName(other.getName());
  this->setCourse(other.getCourse());
}

std::string	Profile::getName() const
{
  return (this->name);
}

int	Profile::getCourse() const
{
  return (this->course);
}

std::string	Profile::getChoosenCar() const
{
  return (this->choosenCar);
}

void	Profile::setName(const std::string &name)
{
  this->name = name;
}

void	Profile::setCourse(int i)
{
  this->course = i;
}

void	Profile::setChoosenCar(std::string &car)
{
  this->choosenCar = car;
}
