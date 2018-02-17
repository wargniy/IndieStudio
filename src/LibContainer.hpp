//
// LibContainer.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio/src
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon May 15 10:57:34 2017 Eloi Brehin
// Last update Sun Jun 18 20:42:56 2017 Eloi Brehin
//

#ifndef LIBCONTAINER_HPP__
# define LIBCONTAINER_HPP__

#include <exception>
#include <iostream>
#include "SAppContext.hpp"

#ifdef __IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

# define WIN_WIDTH	(1920)
# define WIN_HEIGHT	(1080)
# define XSTART_B	(WIN_WIDTH / 2 - 200)
# define XEND_B		(WIN_WIDTH / 2 + 200)

class			LibContainer
{
  irr::IrrlichtDevice	*device; // createDevice(video::EDT_OPENGL, win_size, bits, fullscreen, false, vsync, eventListener)
  VIDEO::IVideoDriver	*VDriver; // device->getVideoDriver()
  SCENE::ISceneManager	*smgr; // device->getSceneManager()
  GUI::IGUIEnvironment	*main_env; // device->getGUIEnvironment()
  bool			running;
  //SAppContext		*context; //à sortir de cette classe
public:
  LibContainer(irr::IEventReceiver *);
  ~LibContainer();

  irr::IrrlichtDevice	*getDevice();
  VIDEO::IVideoDriver	*getVDriver();
  SCENE::ISceneManager	*getSmgr();
  GUI::IGUIEnvironment	*getGuienv();
  bool			isRunning();
  void			setRun(bool);
};

#endif // !LIBCONTAINER_HPP__
