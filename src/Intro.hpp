//
// Intro.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Mon May 15 11:04:36 2017 Simon RAGUIN
// Last update Mon Jun  5 17:15:36 2017 Eloi Brehin
//

#include <vector>
#include <queue>
#include "MyEventListener.hpp"
#include "LibContainer.hpp"
#include "Menu.hpp"

class	Intro
{
private:
  std::vector<Profile *>	saves;
  LibContainer			*lib;
  SAppContext			*context;
  std::queue<std::string>	logo;
  std::queue<std::string>	gsplash;
public:
  Intro(LibContainer *);
  ~Intro();

  void				loadSaves();
  void				createSaveFile();
  std::vector<Profile *>	getSaves() const;
  LibContainer			*getLib() const;
  void				setSaves(std::vector<Profile *>);
  void				setContext(SAppContext *elem)
  {
    this->context = elem;
  }

  void				initMainEnv();
  void				initListProfile(GUI::IGUIListBox *,
						GUI::IGUIListBox *);
  void				startIntro(AEventListener *);
  void				loadVideo();
  void				loadGameSplash();
  void				setSkinColor();
  void				loadLogoPath();
  void				loadGSplashPath();
};
