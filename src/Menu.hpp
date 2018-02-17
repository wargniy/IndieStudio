//
// Menu.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon May 29 10:53:30 2017 Eloi Brehin
// Last update Sun Jun 18 20:40:48 2017 Eloi Brehin
//

#ifndef MENU_HPP_

# define MENU_HPP_

# include <exception>
# include <string>
# include <fstream>
# include <thread>
# include "LibContainer.hpp"
# include "MenuEventListener.hpp"
# include "SAppContext.hpp"
# include "Profile.hpp"

class		Menu
{
  LibContainer	*lib;
  SAppContext	*context;
  std::string	username;
  int		nbCourse;
  int		nbPlayers;

public:
  Menu(LibContainer *, SAppContext *);
  ~Menu();

  void		startMenu(MenuEventListener *);
  void		setLib(LibContainer *);
  void		setContext(SAppContext *);
  void		setNbPlayers(int);
  void		initMainEnv(AEventListener *);
  void		initButtons();
  void		initCredits();
  void		initListBox();
  void		initTabs();
  void		initChoice();
  void		makeChoice();
};

#endif // !MENU_HPP_
