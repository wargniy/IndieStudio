//
// Event_Game.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Mon Jun  5 11:44:42 2017 Simon RAGUIN
// Last update Sun Jun 18 17:45:48 2017 Simon RAGUIN
//

#ifndef EVENT_GAME_HPP
# define EVENT_GAME_HPP

#include "AEventListener.hpp"
#include "Car.hpp"
#include "SAppContext.hpp"

class	Event_Game : public AEventListener
{
private:
  irr::SEvent::SJoystickEvent JoystickState;
  SAppContext	*_context;
  std::vector<Car *>	car;
public:
  Event_Game(SAppContext *elem)
  {
    this->_context = elem;
  }
  ~Event_Game() {}
  bool	OnEvent(const irr::SEvent &);
  bool	keyMapping(const irr::SEvent &);
  bool	keyUnMapping(const irr::SEvent &);
  bool	dis_controlleur(const irr::SEvent &, int);

  void	addCar(Car *voiture)
  {
    car.push_back(voiture);
  }
  Car	*getCar(int i) const
  {
    if (i <= 3)
      return (car[i]);
    return (NULL);
  }
  irr::SEvent::SJoystickEvent	getJoystickState() const
  {
    return (JoystickState);
  }
  std::vector<Car *>	getCarVector()
  {
    return (car);
  }
};

#endif
