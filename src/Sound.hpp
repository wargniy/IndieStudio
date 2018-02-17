//
// Sound.hpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio/irrKlang-1.5.0/examples/01.HelloWorld
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon May 22 18:15:10 2017 Eloi Brehin
// Last update Sun Jun 18 19:00:27 2017 Eloi Brehin
//

#ifndef SOUND_HPP_
# define SOUND_HPP_

#include <irrKlang.h>
#include <string>
#include <map>
#include <ctime>
#include <thread>
#include "conio.h"
#include "SAppContext.hpp"

# define MENU_P_SIZE	(5)
# define MENU_G_SIZE	(1)
//#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

class								Sound
{
  irrklang::ISoundEngine					*engine;
  std::map<std::string, irrklang::ISoundSource *>		playlist;

public:
  Sound();
  ~Sound();
  irrklang::ISoundEngine	*getEngine();
  void				start(const std::string &, bool);
  void				startPlaylistMenu(SAppContext *);
  void				startPlaylistGame(SAppContext *);
  void				stop();
};

#endif // !SOUND_HPP_
