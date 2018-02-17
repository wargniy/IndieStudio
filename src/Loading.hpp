//
// Loading.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon Jun  5 09:59:35 2017 Eloi Brehin
// Last update Sun Jun 18 21:24:06 2017 Eloi Brehin
//

#ifndef LOADING_HPP_
# define LOADING_HPP_

#define NB_FRAME	(104)
#define NB_TURN		(2)

#include "LibContainer.hpp"

class	Loading
{
  LibContainer		*lib;
  GUI::IGUIImageList	*list;

public:
  Loading(LibContainer *lib);
  ~Loading();

  void	start();
};

#endif // !LOADING_HPP_
