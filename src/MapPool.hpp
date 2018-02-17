//
// MapPool.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Fri Jun 16 19:11:44 2017 Simon RAGUIN
// Last update Sun Jun 18 20:20:36 2017 Simon RAGUIN
//

#ifndef MAPPOOL_HPP
# define MAPPOOL_HPP

#include <irrlicht.h>
#include "CarFactory.hpp"
#include "Profile.hpp"
#include "Event_Game.hpp"
#include "Mustang.hpp"
#include "SAppContext.hpp"

class	MapPool
{
private:
  SCENE::IAnimatedMesh		*_mesh;
  SCENE::ISceneNode		*_skybox;
  SCENE::IMeshSceneNode		*_node;
  LibContainer			*_lib;
  std::vector<std::string>	mapData;
public:
  MapPool()
  {
    mapData.push_back("../resources/map/ovalemap.obj");
    mapData.push_back("../resources/map/firstmap.obj");
  }
  ~MapPool() {}
public:
  void			init_map(int i);
public:
  void			setMesh(SCENE::IAnimatedMesh *mesh)
  {
    _mesh = mesh;
  }
  void			setSky(SCENE::ISceneNode *sky)
  {
    _skybox = sky;
  }
  void			setNode(SCENE::IMeshSceneNode *node)
  {
    _node = node;
  }
  void			setLib(LibContainer *lib)
  {
    _lib = lib;
  }
  SCENE::IAnimatedMesh	*getMesh() const
  {
    return _mesh;
  }
  SCENE::ISceneNode	*getSky() const
  {
    return _skybox;
  }
  SCENE::IMeshSceneNode	*getNode() const
  {
    return _node;
  }
  LibContainer		*getLib() const
  {
    return _lib;
  }
  std::vector<std::string>	getMapdata() const
  {
    return mapData;
  }
};

#endif
