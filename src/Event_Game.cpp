//
// Event_Game.cpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Mon Jun  5 11:50:00 2017 Simon RAGUIN
// Last update Sun Jun 18 20:50:11 2017 Eloi Brehin
//

#include "Event_Game.hpp"

bool	Event_Game::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.PressedDown == true)
    {
      return keyMapping(event);
    }
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.PressedDown == false)
    {
      return keyUnMapping(event);
    }
  //non mais on va mettre la voiture ici je pense
  if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT &&
      event.JoystickEvent.Joystick == 1 && this->car.size() >= 3 && this->car[2]->getRun() == 0)
    {
      return dis_controlleur(event, 2);
    }
  //multi controleur
  if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT &&
      event.JoystickEvent.Joystick == 2 && this->car.size() >= 4 && this->car[3]->getRun() == 0)
    {
      return dis_controlleur(event, 3);
    }
  return (true);
}

bool	Event_Game::dis_controlleur(const irr::SEvent &event, int j)
{
  irr::f32 moveHorizontal = 0.f;
  irr::f32 moveVertical = 0.f;
  const irr::f32 DEAD_ZONE = 0.05f;
  const irr::f32 frameDeltaTime = 1.f;
  const irr::u16 povDegrees = JoystickState.POV / 100;
  CORE::vector3df nodePosition;

  car[j]->setLeft(0);
  car[j]->setRight(0);
  nodePosition = this->car[j]->getNode()->getPosition();
  JoystickState = event.JoystickEvent;
  moveHorizontal = (irr::f32)JoystickState.Axis[irr::SEvent::SJoystickEvent::AXIS_X] / 32767.f;
  if(fabs(moveHorizontal) < DEAD_ZONE)
    moveHorizontal = 0.f;
  moveVertical = (irr::f32)JoystickState.Axis[irr::SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
  if(moveVertical < 0.1 && moveVertical > -0.1)
    moveVertical = 0.f;
  if (moveHorizontal > 0)
    {
      this->car[j]->setLeft(0);
      this->car[j]->setRight((-1) * moveHorizontal);
    }
  if (moveHorizontal < 0)
    {
      this->car[j]->setLeft(moveHorizontal);
      this->car[j]->setRight(0);
    }
  // if (JoystickState.IsButtonPressed(0) == true)
  //   car[j]->setUp(1.);
  // if (JoystickState.IsButtonPressed(0) == false)
  //   car[j]->setUp(0);
  // if (JoystickState.IsButtonPressed(1) == true)
  //   car[j]->setBack(1.);
  // if (JoystickState.IsButtonPressed(1) == false)
  //   car[j]->setBack(0);
  car[j]->getNode()->setPosition(nodePosition);
  return (true);
}

bool	Event_Game::keyMapping(const irr::SEvent &event)
{
  switch (event.KeyInput.Key)
    {
    case irr::KEY_KEY_D:
      if (this->car[0]->getRun() == 0)
	this->car[0]->setLeft(1.);
      break;
    case irr::KEY_KEY_Q:
      if (this->car[0]->getRun() == 0)
	this->car[0]->setRight(1.);
      break;
    case irr::KEY_RIGHT:
      if (this->car[0]->getRun() == 0)
	if (this->car.size() >= 2)
	  this->car[1]->setLeft(1.);
      break;
    case irr::KEY_LEFT:
      if (this->car[0]->getRun() == 0)
	if (this->car.size() >= 2)
	  this->car[1]->setRight(1.);
      break;
    case irr::KEY_ESCAPE:
      this->context->setQuit(true);
      this->context->setState(QUIT);
      this->lib->setRun(false);
    default:
      break;
    }
  return (true);
}

bool	Event_Game::keyUnMapping(const irr::SEvent &event)
{
  switch (event.KeyInput.Key)
    {
    case irr::KEY_KEY_D:
      if (this->car[0]->getRun() == 0)
	this->car[0]->setLeft(0);
      break;
    case irr::KEY_KEY_Q:
      if (this->car[0]->getRun() == 0)
	this->car[0]->setRight(0);
      break;
    case irr::KEY_RIGHT:
      if (this->car[0]->getRun() == 0)
	if (this->car.size() >= 2)
	  this->car[1]->setLeft(0);
      break;
    case irr::KEY_LEFT:
      if (this->car[0]->getRun() == 0)
	if (this->car.size() >= 2)
	  this->car[1]->setRight(0);
      break;
    default:
      break;
    }
  return (true);
}
