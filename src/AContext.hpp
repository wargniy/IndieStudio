//
// AContext.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio/src
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Fri Jun  2 11:21:54 2017 Eloi Brehin
// Last update Wed Jun 14 17:47:23 2017 Eloi Brehin
//

#ifndef ACONTEXT_HPP_
# define ACONTEXT_HPP_

#include "irrlicht.h"
#include "driverChoice.h"
#include "Profile.hpp"
#include <iostream>
#include <vector>
#include <map>

#ifdef __IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

#define CORE	irr::core
#define SCENE	irr::scene
#define VIDEO	irr::video
#define IO	irr::io
#define GUI	irr::gui

const int DELAY_TIME = 3000;

enum ETimerAction
  {
    ETA_MOUSE_VISIBLE,
    ETA_MOUSE_INVISIBLE,
  };

struct TimerAction
{
  irr::u32 TargetTime;
  ETimerAction Action;
};

/* Cette enum sert à définir l'état dans lequel le context évolue
** Elle servira à l'EventManager pour définir les actions à effectuer
*/
enum	eContext
{
  SPLASH_SCR,
  INTRO,
  MENU,
  CREDITS,
  GAME,
  CHOICE,
  QUIT,
};

class	AContext
{
protected:
  bool						shouldQuit;
  bool						shouldContinue;
  irr::IrrlichtDevice				*Device;
  std::map<std::string, GUI::IGUIButton *>	Button;
  CORE::array<TimerAction>			TimerActions;
  eContext					state;

public:
  AContext(eContext);
  ~AContext();

  virtual void	update() = 0;
  virtual void	runTimerAction(const TimerAction &) = 0;

  void	addButton(GUI::IGUIButton *, std::string);
  //setters
  void	setState(eContext);
  void	setQuit(bool);
  void	setContinue(bool);
  void	setDevice(irr::IrrlichtDevice *);
  void	setButtonBackground(const std::string &);
  void	setButtonFont(const std::string &);
  //reinit
  void	reinitButtons();
  //getter
  irr::IrrlichtDevice			*getDevice() const;
  GUI::IGUIButton			*getButton(std::string);
  CORE::array<TimerAction>		getTimer() const;
  bool					getQuit() const;
  bool					getContinue() const;
  eContext				getState() const;
};

#endif // !ACONTEXT_HPP_
