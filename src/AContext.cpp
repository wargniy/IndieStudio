//
// AContext.cpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio/src
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Fri Jun  2 11:50:42 2017 Eloi Brehin
// Last update Fri Jun  2 12:08:28 2017 Eloi Brehin
//

#include "AContext.hpp"

AContext::AContext(eContext state) : Device(0), shouldQuit(false),
				     shouldContinue(false), state(state)
{
}

AContext::~AContext()
{
}

void	AContext::setDevice(irr::IrrlichtDevice *device)
{
  this->Device = device;
}

void	AContext::addButton(GUI::IGUIButton *button, std::string name)
{
  this->Button[name] = button;
}

void	AContext::setQuit(bool elem)
{
  this->shouldQuit = elem;
}

void	AContext::setContinue(bool elem)
{
  this->shouldContinue = elem;
}

void	AContext::setButtonFont(const std::string &src)
{
  GUI::IGUIFont	*font = this->Device->getGUIEnvironment()->getFont(src.c_str());
  for (auto& e : this->Button)
    {
      e.second->setOverrideFont(font);
    }
}

void	AContext::setButtonBackground(const std::string &src)
{
  for (auto& e : this->Button)
    {
      e.second->setDrawBorder(false);
      e.second->setImage(this->Device->getVideoDriver()->getTexture(src.c_str()));
    }
}

void	AContext::reinitButtons()
{
  this->Button.clear();
}

void	AContext::setState(eContext state)
{
  this->state = state;
}

irr::IrrlichtDevice	*AContext::getDevice() const
{
  return (this->Device);
}

CORE::array<TimerAction>	AContext::getTimer() const
{
  return (this->TimerActions);
}

bool			AContext::getQuit() const
{
  return (this->shouldQuit);
}

bool			AContext::getContinue() const
{
  return (this->shouldContinue);
}

GUI::IGUIButton		*AContext::getButton(std::string name)
{
  return (this->Button[name]);
}

eContext		AContext::getState() const
{
  return (this->state);
}
