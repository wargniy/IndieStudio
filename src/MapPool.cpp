//
// MapPool.cpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Fri Jun 16 19:34:51 2017 Simon RAGUIN
// Last update Sun Jun 18 20:21:07 2017 Simon RAGUIN
//

#include "MapPool.hpp"

void	MapPool::init_map(int i)
{
  _skybox = _lib->getSmgr()->addSkyBoxSceneNode(_lib->getVDriver()->getTexture("../resources/fonts/irrlicht2_up.jpg"),
						_lib->getVDriver()->getTexture("../resources/fonts/irrlicht2_up.jpg"),
						_lib->getVDriver()->getTexture("../resources/fonts/irrlicht2_rt.jpg"),
						_lib->getVDriver()->getTexture("../resources/fonts/irrlicht2_lf.jpg"),
						_lib->getVDriver()->getTexture("../resources/fonts/irrlicht2_ft.jpg"),
						_lib->getVDriver()->getTexture("../resources/fonts/irrlicht2_bk.jpg"));
  _mesh = _lib->getSmgr()->getMesh(mapData[i].c_str());
  if (_node && i != 0)
    _node->remove();
  _node = _lib->getSmgr()->addMeshSceneNode(_mesh->getMesh(0));
  _node->setScale(CORE::vector3df(1.7)); //attention ça dépend de la map
  _node->setPosition(CORE::vector3df(0, 100, -100)); //attention ça dépend de la map
  _node->setRotation(CORE::vector3df(180, 0, 0)); //attention ça dépend de la map
  //  _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  //  _node->setMaterialTexture(0, _lib->getVDriver()->getTexture("../resources/map/road3.jpg"));
  _mesh->drop();
}
