//
// MenuEventListener.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Wed May 31 08:43:03 2017 Eloi Brehin
// Last update Sun Jun 18 18:54:37 2017 Eloi Brehin
//

#ifndef MENUEVENTLISTENER_HPP_
# define MENUEVENTLISTENER_HPP_

#include "AEventListener.hpp"
#include "Sound.hpp"

class		MenuEventListener : public AEventListener
{
  std::vector<Profile *>	players;
  int				len;
  int				size;
  Sound				*music;
  int				nbPlayers;

public:
  MenuEventListener(Sound *);
  ~MenuEventListener();

  bool	OnEvent(const irr::SEvent &);
  bool	keyMapping(const irr::SEvent &);
  void	buttonClicked(const irr::SEvent &);
  void	handleScroll(const irr::SEvent &);
  void	showCredits();
  void	selectPlayers();
  void	getBack();
  void	addPlayer();
  void	delPlayer();
  void	setChoice();
  void	backSelect();
  void	options();
  void	changeCar();
  void	setChoiceforPlayer(int);
  void	reset();

  std::vector<Profile *>	getPlayers();
};

#endif // !MENUEVENTLISTENER_HPP_
