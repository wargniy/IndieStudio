//
// Game.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Sat Jun  3 17:37:06 2017 Simon RAGUIN
// Last update Sun Jun 18 17:43:50 2017 Simon RAGUIN
//

#ifndef GAME_HPP
# define GAME_HPP

#include <chrono>
#include <thread>
#include "MapPool.hpp"

class Game
{
private:
  SCENE::ICameraSceneNode *_camera;
  SCENE::ITriangleSelector *_selector;
  SCENE::ISceneNodeAnimator *_animator;
  Event_Game		*_event_j1;
  LibContainer		*_lib;
  SAppContext		*context;

  MapPool		pool;
  std::vector<Car *>	car_container;
  CarFactory		factory;
  int			nb_joueur;
  std::chrono::steady_clock::time_point	boost;
  std::chrono::steady_clock::time_point	count_down;

public:
  Game(LibContainer *lib, int nb, SAppContext *context)
  {
    this->nb_joueur = nb;
    this->_lib = lib;
    this->context = context;
    this->pool.setLib(lib);
    _event_j1 = new Event_Game(this->context);
  }
  ~Game()
  {
    if (this->_event_j1)
      delete this->_event_j1;
  }

  void	init_camera();
  void	init_map();
  void	init_map_selector();
  void	playing(std::vector<Profile*>);
  void	collision_car(SCENE::ITriangleSelector *, Car *);
  void	set_car_pos(Car *, int );
  int	is_last_car();
  void	CountDownForRun(int);
  void	setTexture(Car *, int);
  void	countTexture(std::string, int *);

  //getteur
  SCENE::ICameraSceneNode *getCamera() const
  {
    return _camera;
  }
  SCENE::ITriangleSelector	*getSelector() const
  {
    return _selector;
  }
  SCENE::ISceneNodeAnimator	*getAnimator() const
  {
    return _animator;
  }
  AEventListener	*getEvent() const
  {
    return _event_j1;
  }
  LibContainer		*getLib() const
  {
    return _lib;
  }
  SAppContext		*getContext() const
  {
    return context;
  }

  //setteur
  void	setCamera(SCENE::ICameraSceneNode *camera)
  {
    this->_camera = camera;
  }
  void	setTriangleselector(SCENE::ITriangleSelector *selector)
  {
    this->_selector = selector;
  }
  void	setAnimator(SCENE::ISceneNodeAnimator *animator)
  {
    this->_animator = animator;
  }
  void	setEvent(Event_Game *event)
  {
    this->_event_j1 = event;
  }
  void	setLib(LibContainer *lib)
  {
    this->_lib = lib;
  }
  void	setContext(SAppContext *context)
  {
    this->context = context;
  }
  void	update_scene()
  {
    this->_lib->getVDriver()->beginScene(true, true, irr::video::SColor(0, 200, 200, 200));
    this->_lib->getSmgr()->drawAll();
    this->_lib->getGuienv()->drawAll();
    this->_lib->getVDriver()->endScene();
  }
};

#endif
