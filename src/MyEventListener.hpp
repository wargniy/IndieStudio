//
// MyEventListener.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio/irrlicht-1.8.4/examples/12.TerrainRendering
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon May 15 12:49:20 2017 Eloi Brehin
// Last update Fri Jun 16 11:42:34 2017 Simon RAGUIN
//

#ifndef MYEVENTLISTENER_HPP__
# define MYEVENTLISTENER_HPP__

#include "AEventListener.hpp"
#include "Profile.hpp"

#define USERNAME_LEN	(24)

/*
** Cette classe regroupera tous les Events pour l'Intro et agira en fonction des inputs.
*/
class		MyEventListener : public AEventListener
{
  std::vector<Profile *> saves;
public:
  MyEventListener(); // Argument à repréciser en fct des besoins
  ~MyEventListener();

  bool	OnEvent(const irr::SEvent &);
  bool	keyMapping(const irr::SEvent &);

  void	onLib();
  void	offLib();
  void	buttonClicked(const irr::SEvent &);
  void	listboxSelectedAgain(const irr::SEvent &);
  void	setSaves(std::vector<Profile *>);

  Profile	*getSave(irr::s32);
};

#endif // !MYEVENTLISTENER_HPP__
