//
// ACare.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Tue May 30 16:39:09 2017 Simon RAGUIN
// Last update Sun Jun 18 20:50:28 2017 Eloi Brehin
//

#ifndef ACAR_HPP
# define ACAR_HPP

#include <irrlicht.h>
#include "LibContainer.hpp"

class		Car
{
  //weapon ??
public:
  enum eState
    {
      Invincible,
      Idle
    };
private:
  int		on_run;
  std::string	_name;
  LibContainer	*lib;
  float		_up;
  float		_down;
  float		_left;
  float		_right;
  float		_defaultSpeed;
  float		_fSpeed;
  float		_fAccelerate;
  float		_fDrift;
  SCENE::IAnimatedMeshSceneNode* _node;
  eState	_curState;
public:
  Car(irr::IrrlichtDevice *device, LibContainer *lib, const char *meshPath, float speed,
      float accel, float drift, std::string name) :
    _up(0.), _down(0.), _right(0.), _left(0.), _name(name), on_run(0)
  {
    this->lib = lib;
    _node = lib->getSmgr()->addAnimatedMeshSceneNode(lib->getSmgr()->getMesh(meshPath));
    _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _fSpeed = speed;
    _defaultSpeed = speed;
    _fAccelerate = accel;
    _fDrift = drift;
    _curState = Car::eState::Idle;
    _node->setJointMode(irr::scene::EJUOR_CONTROL);
    _node->setTransitionTime(0.5);
  }
  ~Car(void)
  {
    _node->remove();
  }
  void		setUp(float up)
  {
    _up = up;
  }
  void		setBack(float down)
  {
    _down = down;
  }
  void		setRight(float right)
  {
    _right = right;
  }
  void		setLeft(float left)
  {
    _left = left;
  }
  void		setSpeed(float newspeed)
  {
    _fSpeed = newspeed;
  }
  void		setPosition(irr::core::vector3df newPos)
  {
    _node->setPosition(newPos);
  }
  void		setRotate(irr::core::vector3df rotate)
  {
    //test avancé
    _node->setRotation(rotate);
  }
  void		setState(eState newState)
  {
    _curState = newState;
  }
  void		setLib(LibContainer *newLib)
  {
    lib = newLib;
  }
  void		setDrift(float drift)
  {
    _fDrift = drift;
  }
  void		setRun(int i)
  {
    _fSpeed = _defaultSpeed;
    on_run = i;
  }

  LibContainer		*getLib() const
  {
    return (lib);
  }
  irr::core::vector3df	getPosition() const
  {
    return (_node->getPosition());
  }
  irr::core::vector3df	getRotate() const
  {
    return (_node->getRotation());
  }
  eState		getState() const
  {
    return (_curState);
  }
  SCENE::IAnimatedMeshSceneNode	*getNode() const
  {
    return (_node);
  }
  float			getSpeed() const
  {
    return (_fSpeed);
  }
  float			getDrift() const
  {
    return (_fDrift);
  }
  int			getRun() const
  {
    return (on_run);
  }
  void			idle()
  {
    //fonction pour remettre la mesh a neutre
    //test avancé
  }
  void			invincible()
  {
    //fonction pour mettre la mesh en clignotant
    //test avancé
  }

  void			resetSpeed()
  {
    this->on_run = 0;
  }
  irr::core::vector3df	faceTarget()
  {
  float degree;

  if (_left != 0)
    degree = _left * 2 * _fDrift;
  if (_right != 0)
    degree = _right * -2 * _fDrift;
  else if (_right == 0 && _left == 0)
    degree = 0;
  return (irr::core::vector3df(0, degree, 0));
  }
  void			moveTo(irr::scene::ISceneNode *node,
			       irr::core::vector3df vel)
  {
    irr::core::matrix4 m;
    m.setRotationDegrees(node->getRotation());
    m.transformVect(vel);
    node->setPosition(node->getPosition() + vel);
    node->updateAbsolutePosition();
  }
  void			move(irr::core::vector3df pos)
  {
    if (_up != 0 || _down != 0 || _left != 0 || _right != 0)
      {
	_node->setRotation(_node->getRotation() + faceTarget());
	if (_up != 0)
	  moveTo(_node, irr::core::vector3df(0, 0, -_fSpeed * _up));
        else if (_down != 0)
	  moveTo(_node, irr::core::vector3df(0, 0, _fSpeed * _down));
      }
  }
  void			update()
  {
    if (_node != nullptr)
      {
	irr::core::vector3df pos = _node->getPosition();
	pos.X += _fAccelerate * _left;
	pos.X -= _fAccelerate * _right;
	move(pos);
      }
  }
  void			remove()
  {
    _node->remove();
  }
};

#endif
