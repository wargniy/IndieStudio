//
// LibContainer.cpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio/src
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon May 15 10:57:46 2017 Eloi Brehin
// Last update Sun Jun 18 21:06:47 2017 Eloi Brehin
//

#include "LibContainer.hpp"

LibContainer::LibContainer(irr::IEventReceiver *events)
{
  CORE::array<irr::SJoystickInfo>	joystickInfo;

  this->device = irr::createDevice(VIDEO::EDT_OPENGL,
				   CORE::dimension2d<irr::u32>(WIN_WIDTH, WIN_HEIGHT),
				   16, true, false, true, events);
  if (!device)
    throw std::runtime_error("Device not loaded");
  this->device->setResizable(false);
  this->VDriver = this->device->getVideoDriver();
  this->smgr = this->device->getSceneManager();
  this->main_env = this->device->getGUIEnvironment();
  this->running = true;
  this->device->activateJoysticks(joystickInfo);
}

LibContainer::~LibContainer()
{
  if (this->device)
    {
      this->VDriver->removeAllTextures();
      this->device->closeDevice();
    }
}

irr::IrrlichtDevice	*LibContainer::getDevice()
{
  return this->device;
}

VIDEO::IVideoDriver	*LibContainer::getVDriver()
{
  return this->VDriver;
}

SCENE::ISceneManager	*LibContainer::getSmgr()
{
  return this->smgr;
}

GUI::IGUIEnvironment	*LibContainer::getGuienv()
{
  return this->main_env;
}

bool		LibContainer::isRunning()
{
  return (this->running);
}

void		LibContainer::setRun(bool running)
{
  this->running = running;
}
