//
// Game.cpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Sat Jun  3 18:02:29 2017 Simon RAGUIN
// Last update Sun Jun 18 20:21:26 2017 Simon RAGUIN
//

#include "Game.hpp"

void				Game::setTexture(Car *car, int i)
{
  switch (i)
    {
    case 0:
      car->getNode()->setMaterialTexture(0, car->getLib()->getVDriver()->getTexture("../resources/fonts/sferiff_red.png"));
      break;
    case 1:
      car->getNode()->setMaterialTexture(0, car->getLib()->getVDriver()->getTexture("../resources/fonts/sferiff_blue.png"));
      break;
    case 2:
      car->getNode()->setMaterialTexture(0, car->getLib()->getVDriver()->getTexture("../resources/fonts/sferiff_yellow.png"));
      break;
    case 3:
      car->getNode()->setMaterialTexture(0, car->getLib()->getVDriver()->getTexture("../resources/fonts/sferiff_green.png"));
      break;
    }
}

int	Game::is_last_car()
{
  int	i = 0;
  int	j = 0;

  while (i < car_container.size())
    {
      if (car_container[i]->getPosition().Y <= 60)
	{
	  car_container[i]->setRun(1);
	  j = j + 1;
	}
      i = i + 1;
    }
  if (j == car_container.size() || (j == (car_container.size() - 1) && car_container.size() != 1))
    return (1);
  return (4);
}

void				Game::countTexture(std::string str, int *i)
{
  _lib->getGuienv()->clear();
  _lib->getGuienv()->addImage(this->_lib->getVDriver()->getTexture(str.c_str()), CORE::position2d<int>(10,10));
  count_down = std::chrono::steady_clock::now() + std::chrono::seconds(1);
  *i = *i + 1;
}

void				Game::CountDownForRun(int i)
{
  while (i != 5)
    {
      _lib->getVDriver()->beginScene(true, true, 0);
      if (std::chrono::steady_clock::now() > count_down && i == 0)
	countTexture("../resources/fonts/number3.png", &i);
      if (std::chrono::steady_clock::now() > count_down && i == 1)
	countTexture("../resources/fonts/number2.png", &i);
      if (std::chrono::steady_clock::now() > count_down && i == 2)
	countTexture("../resources/fonts/number1.png", &i);
      if (std::chrono::steady_clock::now() > count_down && i == 3)
	countTexture("../resources/fonts/go.png", &i);
      if (std::chrono::steady_clock::now() > count_down && i == 4)
	i = 5;
      _lib->getSmgr()->drawAll();
      _lib->getGuienv()->drawAll();
      _lib->getVDriver()->endScene();
    }
  _lib->getGuienv()->clear();
}

void				Game::init_camera()
{
  this->_camera = this->_lib->getSmgr()->addCameraSceneNode(0, CORE::vector3df(0, 300, -125), CORE::vector3df(0,100, 0));

  _camera->setFOV(irr::core::PI / 2.0f);
  _camera->setFarValue(9000.f);
}

void	Game::set_car_pos(Car *car, int i)
{
  car->getNode()->setPosition(CORE::vector3df(-90,110,-105 + (5 * i)));
  car->getNode()->setRotation(CORE::vector3df(0, 90, 0));
  car->getNode()->getMaterial(0).NormalizeNormals = true;
  car->getNode()->getMaterial(0).Lighting = true;
  _selector->drop();
}

void				Game::init_map_selector()
{
  _selector = this->_lib->getSmgr()->createOctreeTriangleSelector(pool.getNode()->getMesh(), pool.getNode(), 128);
  pool.getNode()->setTriangleSelector(_selector);
}

void	Game::collision_car(SCENE::ITriangleSelector *selector, Car *car)
{
  const irr::core::aabbox3d<irr::f32>& box = car->getNode()->getBoundingBox();
  irr::core::vector3df radius = box.MaxEdge - box.getCenter();
  SCENE::ISceneNodeAnimator	*animCar = this->_lib->getSmgr()->createCollisionResponseAnimator(selector, car->getNode(), radius, CORE::vector3df(0, -10, 0), CORE::vector3df(0, 0, 0));

  car->getNode()->addAnimator(animCar);
  animCar->drop();
}

void				Game::playing(std::vector<Profile*> tab)
{
  int				i = 0;

  _lib->getGuienv()->clear();
  _lib->getSmgr()->clear();
  pool.init_map(0);
  init_map_selector();
  init_camera();
  for (auto &it : tab)
    {
      Car	*vehicule = factory.createCar(it->getChoosenCar(), _lib, _lib->getDevice());
      setTexture(vehicule, i);
      if (it->getChoosenCar() == "Mustang")
	vehicule->getNode()->setScale(CORE::vector3df(0.0035)); //police //a déplacer
      else
	vehicule->getNode()->setScale(CORE::vector3df(4.9)); //pick_up
      set_car_pos(vehicule, i);
      collision_car(_selector, vehicule);
      _event_j1->addCar(vehicule);
      car_container.push_back(vehicule);
      i = i + 1;
    }
  i = 0;

  nb_joueur = car_container.size();
  boost = std::chrono::steady_clock::now();
  count_down = std::chrono::steady_clock::now();

  CountDownForRun(i);

  this->_lib->getDevice()->setEventReceiver(_event_j1);
  while (this->_lib->getDevice()->run() && this->context->getQuit() == false && i < pool.getMapdata().size())
    {
      for (auto &elem : car_container)
	elem->update();
      for (auto &car : this->car_container)
	car->setUp(1.);
      if (std::chrono::steady_clock::now() > boost)
	{
	  for (auto &elem : car_container)
	    {
	      elem->setSpeed(elem->getSpeed() + 0.15);
	      elem->setDrift(elem->getDrift() + 0.15);
	    }
	  boost = std::chrono::steady_clock::now() + std::chrono::seconds(7);
	}
      update_scene();
      if (is_last_car() == 1)
	{
	  i = i + 1;
	  if (i < pool.getMapdata().size())
	    {
	      pool.init_map(i);
	      init_map_selector();
	      int idx_tab = -1;
	      while (++idx_tab < car_container.size())
		{
		  set_car_pos(car_container[idx_tab], idx_tab);
		  collision_car(_selector, car_container[idx_tab]);
		  car_container[idx_tab]->setRun(0);
		}
	      nb_joueur = car_container.size();
	      boost = std::chrono::steady_clock::now();
	      count_down = std::chrono::steady_clock::now();
	      CountDownForRun(0);
	    }
	}
    }
  update_scene();
  _lib->getGuienv()->clear();
  _lib->getSmgr()->clear();
  this->context->setState(MENU);
  this->context->setContinue(false);
}
