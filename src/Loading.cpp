//
// Loading.cpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon Jun  5 10:01:18 2017 Eloi Brehin
// Last update Sun Jun 18 21:23:51 2017 Eloi Brehin
//

#include "Loading.hpp"

Loading::Loading(LibContainer *lib) : lib(lib)
{
}

Loading::~Loading()
{

}

void		Loading::start()
{
  std::string	path = "../resources/fonts/loading/loading ";
  int		idx = 0;
  std::string	res;
  std::string	nb;
  int		turn = 0;
  std::vector<std::string>	load;

  while (idx < NB_FRAME)
    {
      nb = std::to_string(idx);
      if (idx < 10)
  	res = path + "00" + nb + ".jpg";
      else if (idx < 100)
  	res = path + "0" + nb + ".jpg";
      load.push_back(res);
      idx++;
    }
  idx = 0;
  while (this->lib->getDevice()->run() && turn < NB_TURN)
    {
      this->lib->getVDriver()->beginScene(true, true, 0);
      this->lib->getVDriver()->draw2DImage(this->lib->getVDriver()->getTexture(load[idx].c_str()),
					 CORE::position2d<irr::s32>(0, 0));
      this->lib->getGuienv()->drawAll();
      this->lib->getVDriver()->endScene();
      if (idx == NB_FRAME)
  	{
  	  idx = 0;
  	  turn++;
	  this->lib->getVDriver()->removeAllTextures();
  	}
      idx++;
    }
  this->lib->getVDriver()->removeAllTextures();
}
