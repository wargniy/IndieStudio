//
// MenuEventListener.cpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Wed May 31 08:49:42 2017 Eloi Brehin
// Last update Sun Jun 18 21:23:33 2017 Eloi Brehin
//

#include "MenuEventListener.hpp"

MenuEventListener::MenuEventListener(Sound *music) : AEventListener(),
						     len(1),
						     size(0)
{
  this->music = music;
}

MenuEventListener::~MenuEventListener()
{

}

bool	MenuEventListener::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_GUI_EVENT)
    {
      switch (event.GUIEvent.EventType)
	{
	case GUI::EGET_BUTTON_CLICKED:
	  buttonClicked(event);
	case GUI::EGET_SCROLL_BAR_CHANGED:
	  handleScroll(event);
	}
    }
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
    {
      return keyMapping(event);
    }
  return false;
}

bool	MenuEventListener::keyMapping(const irr::SEvent &event)
{
  switch (event.KeyInput.Key)
    {
    case irr::KEY_ESCAPE:
      if (this->context->getState() == SPLASH_SCR)
	this->context->setContinue(true);
      else
	{
	  this->context->setQuit(true);
	  this->context->setState(QUIT);
	  // this->lib->setRun(false);
	}
      return false;
    default:
      break;
    }
}

void	MenuEventListener::handleScroll(const irr::SEvent &event)
{
  if (event.GUIEvent.Caller == context->getScrollBar())
    {
      irr::s32	pos = context->getScrollBar()->getPos();
      irrklang::ik_f32	vol = pos / 100.0;
      this->music->getEngine()->setAllSoundsPaused(true);
      this->music->getEngine()->setSoundVolume(vol);
      this->music->getEngine()->setAllSoundsPaused(false);
    }
}

void	MenuEventListener::buttonClicked(const irr::SEvent &event)
{
  // CORE::s32	id = event.GUIEvent.Caller->getID();

  // switch (id)
  //   {

  //   }
  if (event.GUIEvent.Caller == context->getButton("quit"))
    {
      context->setQuit(true);
      lib->setRun(false);
    }
  if (event.GUIEvent.Caller == context->getButton("play"))
    this->selectPlayers();
  if (event.GUIEvent.Caller == context->getButton("options"))
    this->options();
  if (event.GUIEvent.Caller == context->getButton("credits"))
    this->showCredits();
  if (event.GUIEvent.Caller == context->getButton("backIntro"))
    {
      this->context->setState(INTRO);
      // this->context->setContinue(true);
    }
  if (event.GUIEvent.Caller == context->getButton("back"))
    this->getBack();
  if (event.GUIEvent.Caller == context->getButton("backSelect"))
    {
      if (this->len > 1)
	{
	  this->len -= 1;
	  this->setChoiceforPlayer(this->len);
	}
      else
	this->backSelect();
    }
  if (event.GUIEvent.Caller == context->getButton("next"))
    {
      if (this->len > 0)
	{
	  this->context->setState(CHOICE);
	  this->setChoice();
	}
    }
  if (event.GUIEvent.Caller == context->getButton("nextGame"))
    {
      if (this->players.size() > 0)
	{
	  if (this->len < this->size)
	    {
	      this->len += 1;
	      this->setChoiceforPlayer(this->len);
	    }
	  else
	    {
	      std::string	car = this->context->getCar();
	      this->players[this->len - 1]->setChoosenCar(car);
	      this->context->setState(GAME);
	      this->context->setContinue(true);
	    }
	}
    }
  if (event.GUIEvent.Caller == context->getButton("addPlayer"))
    this->addPlayer();
  if (event.GUIEvent.Caller == context->getButton("delPlayer"))
    this->delPlayer();
  if (event.GUIEvent.Caller == context->getButton("left"))
    this->changeCar();
  if (event.GUIEvent.Caller == context->getButton("right"))
    this->changeCar();
}

void	MenuEventListener::showCredits()
{
  this->context->getImage("title")->setVisible(false);
  this->context->getButton("play")->setVisible(false);
  this->context->getButton("options")->setVisible(false);
  this->context->getButton("credits")->setVisible(false);
  this->context->getButton("quit")->setVisible(false);
  this->context->getButton("back")->setVisible(true);
  this->context->getText("credits")->setVisible(true);
  this->context->setState(CREDITS);
  this->context->getText("credits")->
    setRelativePosition(CORE::position2di(XSTART_B, WIN_HEIGHT));
}

void	MenuEventListener::getBack()
{
  this->context->getImage("title")->setVisible(true);
  this->context->getButton("play")->setVisible(true);
  this->context->getButton("options")->setVisible(true);
  this->context->getButton("credits")->setVisible(true);
  this->context->getButton("quit")->setVisible(true);
  this->context->getButton("back")->setVisible(false);
  this->context->getButton("addPlayer")->setVisible(false);
  this->context->getButton("delPlayer")->setVisible(false);
  this->context->getListBox("nbPlayers")->setVisible(false);
  this->context->getButton("next")->setVisible(false);
  this->context->getTabCtrl()->setVisible(false);
  this->context->getText("credits")->setVisible(false);
  this->context->setState(MENU);
}

void	MenuEventListener::selectPlayers()
{
  this->context->getImage("title")->setVisible(false);
  this->context->getButton("back")->setVisible(true);
  this->context->getButton("play")->setVisible(false);
  this->context->getButton("options")->setVisible(false);
  this->context->getButton("credits")->setVisible(false);
  this->context->getButton("quit")->setVisible(false);
  this->context->getButton("addPlayer")->setVisible(true);
  this->context->getButton("delPlayer")->setVisible(true);
  this->context->getButton("next")->setVisible(true);
  this->context->getListBox("nbPlayers")->setVisible(true);
}

void	MenuEventListener::addPlayer()
{
  if (this->size < 4)
    {
      std::string	name = "Player " + std::to_string(this->size + 1);
      CORE::stringw	username = CORE::stringw(name.c_str()).c_str();
      this->context->getListBox("nbPlayers")->addItem(username.c_str());
      Profile		*newPlayer = new Profile(name);
      this->players.push_back(newPlayer);
      this->size += 1;
    }
}

void	MenuEventListener::delPlayer()
{
  if (this->size > 0)
    {
      this->context->getListBox("nbPlayers")->removeItem(this->size - 1);
      this->players.pop_back();
      this->size -= 1;
    }
}

std::vector<Profile *>	MenuEventListener::getPlayers()
{
  return (this->players);
}

void	MenuEventListener::options()
{
  this->context->getImage("title")->setVisible(false);
  this->context->getButton("back")->setVisible(true);
  this->context->getButton("play")->setVisible(false);
  this->context->getButton("options")->setVisible(false);
  this->context->getButton("credits")->setVisible(false);
  this->context->getButton("quit")->setVisible(false);
  this->context->getTabCtrl()->setVisible(true);
}

void	MenuEventListener::setChoice()
{
  this->context->getImage("title")->setVisible(false);
  this->context->getImage("background")->setVisible(false);
  this->context->getImage("garage")->setVisible(true);
  this->context->getImage("player1")->setVisible(true);
  this->context->getButton("back")->setVisible(false);
  this->context->getButton("addPlayer")->setVisible(false);
  this->context->getButton("delPlayer")->setVisible(false);
  this->context->getButton("next")->setVisible(false);
  this->context->getListBox("nbPlayers")->setVisible(false);
  this->context->getButton("backSelect")->setVisible(true);
  this->context->getButton("nextGame")->setVisible(true);
  this->context->getButton("left")->setVisible(true);
  this->context->getButton("right")->setVisible(true);
  this->context->getMesh("Mustang")->setVisible(true);
}

void	MenuEventListener::backSelect()
{
  this->context->getImage("background")->setVisible(true);
  this->context->getImage("garage")->setVisible(false);
  this->context->getButton("back")->setVisible(true);
  this->context->getButton("addPlayer")->setVisible(true);
  this->context->getButton("delPlayer")->setVisible(true);
  this->context->getButton("next")->setVisible(true);
  this->context->getListBox("nbPlayers")->setVisible(true);
  this->context->getButton("backSelect")->setVisible(false);
  this->context->getButton("nextGame")->setVisible(false);
  this->context->getButton("left")->setVisible(false);
  this->context->getButton("right")->setVisible(false);
  this->context->getMesh("Mustang")->setVisible(false);
  this->context->getMesh("Pickup")->setVisible(false);
  this->context->getImage("player1")->setVisible(false);
  this->context->getImage("player2")->setVisible(false);
  this->context->getImage("player3")->setVisible(false);
  this->context->getImage("player4")->setVisible(false);
}

void	MenuEventListener::changeCar()
{
  if (this->context->getMesh("Mustang")->isVisible() == true)
    {
      this->context->getMesh("Mustang")->setVisible(false);
      this->context->getMesh("Pickup")->setVisible(true);
    }
  else
    {
      this->context->getMesh("Mustang")->setVisible(true);
      this->context->getMesh("Pickup")->setVisible(false);
    }
}

void	MenuEventListener::setChoiceforPlayer(int nb)
{
  std::string	car = this->context->getCar();
  switch (nb)
    {
    case 4:
      this->context->getImage("player3")->setVisible(false);
      this->context->getImage("player4")->setVisible(true);
      this->players[2]->setChoosenCar(car);
      this->context->getMesh("Mustang")->
	setMaterialTexture(0, this->lib->getVDriver()->
			   getTexture("../resources/fonts/sferiff_yellow.png"));
      this->context->getMesh("Pickup")->
	setMaterialTexture(0, this->lib->getVDriver()->
			   getTexture("../resources/fonts/car01_yellow.png"));
      break;
    case 3:
      this->context->getImage("player4")->setVisible(false);
      this->context->getImage("player2")->setVisible(false);
      this->context->getImage("player3")->setVisible(true);
      this->context->getMesh("Mustang")->
	setMaterialTexture(0, this->lib->getVDriver()->
			   getTexture("../resources/fonts/sferiff_green.png"));
      this->context->getMesh("Pickup")->
	setMaterialTexture(0, this->lib->getVDriver()->
			   getTexture("../resources/fonts/car01_gren.png"));
      this->players[1]->setChoosenCar(car);
      break;
    case 2:
      this->context->getImage("player3")->setVisible(false);
      this->context->getImage("player1")->setVisible(false);
      this->context->getImage("player2")->setVisible(true);
      this->context->getMesh("Mustang")->
	setMaterialTexture(0, this->lib->getVDriver()->
			   getTexture("../resources/fonts/sferiff_blue.png"));
      this->context->getMesh("Pickup")->
	setMaterialTexture(0, this->lib->getVDriver()->
			   getTexture("../resources/fonts/car01_blue.png"));
      this->players[0]->setChoosenCar(car);
      break;
    case 1:
      this->context->getImage("player2")->setVisible(false);
      this->context->getImage("player1")->setVisible(true);
      this->context->getMesh("Mustang")->
	setMaterialTexture(0, this->lib->getVDriver()->
			   getTexture("../resources/fonts/sferiff_red.png"));
      this->context->getMesh("Pickup")->
	setMaterialTexture(0, this->lib->getVDriver()->
			   getTexture("../resources/fonts/car01_red.png"));
      break;
    }
}

void	MenuEventListener::reset()
{
  this->players.clear();
  this->len = 1;
  this->size = 0;
}
