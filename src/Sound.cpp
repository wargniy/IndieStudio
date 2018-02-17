//
// Sound.cpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio/irrKlang-1.5.0/examples/01.HelloWorld
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon May 22 18:19:49 2017 Eloi Brehin
// Last update Fri Jun 16 18:39:07 2017 Eloi Brehin
//

#include "Sound.hpp"

Sound::Sound()
{
  this->engine = irrklang::createIrrKlangDevice();
  std::srand(std::time(0));
  this->playlist["splash"] = this->engine->
    addSoundSourceFromFile("../resources/media/splashcreen.wav",
			   irrklang::ESM_AUTO_DETECT, true);
  this->playlist["gsplash"] = this->engine->
    addSoundSourceFromFile("../resources/media/gsplashacc.wav",
			   irrklang::ESM_AUTO_DETECT, true);
  this->playlist["intro1"] = this->engine
    ->addSoundSourceFromFile("../resources/media/Red.wav",
			     irrklang::ESM_AUTO_DETECT, true);
  this->playlist["intro2"] = this->engine->
    addSoundSourceFromFile("../resources/media/Stopwatch.wav",
			   irrklang::ESM_AUTO_DETECT, true);
  this->playlist["intro3"] = this->engine->
    addSoundSourceFromFile("../resources/media/IntroMenu.wav",
			   irrklang::ESM_AUTO_DETECT, true);
  this->playlist["intro4"] = this->engine->
    addSoundSourceFromFile("../resources/media/Pits.wav",
			   irrklang::ESM_AUTO_DETECT, true);
  this->playlist["intro5"] = this->engine->
    addSoundSourceFromFile("../resources/media/Scuderia.wav",
			   irrklang::ESM_AUTO_DETECT, true);
  this->playlist["game1"] = this->engine->
    addSoundSourceFromFile("../resources/media/music_course1.wav",
			   irrklang::ESM_AUTO_DETECT, true);
  this->playlist["countdown"] = this->engine->
    addSoundSourceFromFile("../resources/media/countdown.wav",
			   irrklang::ESM_AUTO_DETECT, true);
}

Sound::~Sound()
{
  if (this->engine)
    this->engine->drop();
}

void	Sound::start(const std::string &sound, bool loop)
{
  if (this->engine)
    {
      if (this->playlist[sound])
	this->engine->play2D(this->playlist[sound], loop, false, false, false);
    }
}

void	Sound::stop()
{
  if (this->engine)
    this->engine->stopAllSounds();
}

void		Sound::startPlaylistMenu(SAppContext *context)
{
  int		i = std::rand() % MENU_P_SIZE;
  std::string	song = "intro";
  std::string	res;

  res = song + std::to_string(i);
  this->start(res, false);
  while (context->getState() != GAME && context->getQuit() == false)
    {
      if (this->engine->isCurrentlyPlaying(this->playlist[res]) == false)
	{
	  i++;
	  if (i > MENU_P_SIZE)
	    i = 1;
	  this->engine->stopAllSounds();
	  res = song + std::to_string(i);
	  this->start(res, false);
	}
    }
}

void		Sound::startPlaylistGame(SAppContext *context)
{
  int		i = std::rand() % MENU_G_SIZE;
  std::string	song = "game";
  std::string	res;

  res = song + std::to_string(i);
  this->start(res, false);
  while (context->getState() == GAME
	 && context->getQuit() == false)
    {
      if (this->engine->isCurrentlyPlaying(this->playlist[res]) == false)
	{
	  i++;
	  if (i > MENU_G_SIZE)
	    i = 1;
	  this->engine->stopAllSounds();
	  res = song + std::to_string(i);
	  this->start(res, false);
	}
    }
}

irrklang::ISoundEngine	*Sound::getEngine()
{
  return (this->engine);
}
