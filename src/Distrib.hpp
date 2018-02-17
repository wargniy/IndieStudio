//
// Distrib.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Wed May 31 08:27:04 2017 Eloi Brehin
// Last update Tue Jun  6 15:14:45 2017 Eloi Brehin
//

#ifndef DISTRIB_HPP_
# define DISTRIB_HPP_

#include <iostream>
#include <cstdlib>
#include "LibContainer.hpp"
#include "MyEventListener.hpp"
#include "MenuEventListener.hpp"
#include "Intro.hpp"
#include "Menu.hpp"
#include "Sound.hpp"
#include "Loading.hpp"
#include "Game.hpp"

class	Distrib
{
  MyEventListener	*event;
  MenuEventListener	*mEvent;
  LibContainer		*lib;
  SAppContext		*context;
  Sound			*music;
  Loading		*loading;


public:
  Distrib();
  ~Distrib();

  void			startGame();
  void			launch_game();
  void			loadSplashScreen(Intro &);
  void			startMenu(Menu &, Intro &);
};

#endif // !DISTRIB_HPP_
