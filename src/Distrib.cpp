//
// Distrib.cpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Wed May 31 08:28:10 2017 Eloi Brehin
// Last update Sun Jun 18 20:50:55 2017 Eloi Brehin
//

#include "Distrib.hpp"

Distrib::Distrib()
{
  this->event = new MyEventListener();
  this->lib = new LibContainer(event);
  this->context = new SAppContext();
  this->music = new Sound();
  this->mEvent = new MenuEventListener(this->music);
  this->loading = new Loading(this->lib);
  context->setDevice(lib->getDevice());
  event->setLib(lib);
  event->setContext(context); //attention
  mEvent->setLib(lib);
  mEvent->setContext(context); //attention
}


Distrib::~Distrib()
{
  if (this->event)
    delete this->event;
  if (this->mEvent)
    delete this->mEvent;
  if (this->context)
    delete this->context;
  if (this->music)
    delete this->music;
  if (this->loading)
    delete this->loading;
  if (this->lib)
    delete this->lib;
}

void		Distrib::startGame()
{
  Profile	profile("Rodrigo");
  Intro		intro(this->lib);
  Menu		menu(this->lib, this->context);

  this->event->setSaves(intro.getSaves());
  this->loading->start();
  intro.setContext(context);
  this->loadSplashScreen(intro);
  this->startMenu(menu, intro);
  if (lib->isRunning())
    this->launch_game();
  this->context->setState(CREDITS);
  this->startMenu(menu, intro);
}

void		Distrib::launch_game()
{
  std::thread	play(&Sound::startPlaylistGame, this->music, this->context);
  Game		game(this->lib, 1, this->context);

  game.playing(this->mEvent->getPlayers());
  this->context->setState(MENU);
  this->music->stop();
  play.join();
}

void		Distrib::loadSplashScreen(Intro &intro)
{
  std::thread	play(&Sound::start, this->music, "splash", false);
  intro.loadVideo();
  this->context->setState(SPLASH_SCR);
  this->music->stop();
  play.join();
  std::thread	replay(&Sound::start, this->music, "gsplash", false);
  intro.loadGameSplash();
  this->context->setState(INTRO);
  replay.join();
  this->music->stop();
}

void		Distrib::startMenu(Menu &menu, Intro &intro)
{
  this->mEvent->reset();
  std::thread	play(&Sound::startPlaylistMenu, this->music, this->context);
  if (this->context->getState() == INTRO)
    intro.startIntro(this->event);
  if (this->lib->isRunning()
      && (this->context->getState() == MENU
	  || this->context->getState() == CREDITS))
    menu.startMenu(this->mEvent);
  this->music->stop();
  play.join();
}
