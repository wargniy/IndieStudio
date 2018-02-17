//
// MyEventListener.cpp for cpp_indie_studio in /home/brehin_e/rendu/cpp_indie_studio/irrlicht-1.8.4/examples/12.TerrainRendering
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon May 15 12:57:05 2017 Eloi Brehin
// Last update Sun Jun 18 20:49:10 2017 Eloi Brehin
//

#include "MyEventListener.hpp"

MyEventListener::MyEventListener() : AEventListener()
{
}

MyEventListener::~MyEventListener()
{
}

bool	MyEventListener::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_GUI_EVENT)
    {
      switch (event.GUIEvent.EventType)
	{
	case GUI::EGET_BUTTON_CLICKED:
	  {
	    buttonClicked(event);
	  }
	case GUI::EGET_LISTBOX_SELECTED_AGAIN:
	  {
	    listboxSelectedAgain(event);
	  }
	}
    }
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
    {
      return keyMapping(event);
    }
  return false;
}

bool	MyEventListener::keyMapping(const irr::SEvent &event)
{
  /*
    Le Mapping des touches est encore à définir
  */
  switch (event.KeyInput.Key)
    {
    case irr::KEY_ESCAPE:
      if (this->context->getState() == SPLASH_SCR)
	this->context->setContinue(true);
      else
	{
	  this->context->setQuit(true);
	  this->lib->setRun(false);
	}
      return false;
    default:
      break;
    }
}

void	MyEventListener::buttonClicked(const irr::SEvent &event)
{
  if (event.GUIEvent.Caller == context->getButton("quit"))
    {
      context->setQuit(true);
      lib->setRun(false);
    }
  if (event.GUIEvent.Caller == context->getButton("new_profile"))
    {
      context->getButton("next_new")->setVisible(true);
      context->getNewName()->setVisible(true);
      onLib();
    }
  if (event.GUIEvent.Caller == context->getButton("select_profile"))
    {
      context->getListBox("list_profile")->setVisible(true);
      context->getListBox("selected_profile")->setVisible(true);
      context->getButton("Next")->setVisible(true);
      onLib();
    }
  if (event.GUIEvent.Caller == context->getButton("next_new"))
    {
      int	i = 0;

      std::string tmp = CORE::stringc(context->getNewName()->getText()).c_str();
      if (tmp != "Choose Name")
	{
	  if (tmp.size() > USERNAME_LEN)
	    tmp = tmp.substr(0, USERNAME_LEN);
	  Profile	elem(tmp);
	  elem.setCourse(1);
	  context->setProfile(elem);
	  context->setContinue(true);
	}
    }
  if (event.GUIEvent.Caller == context->getButton("Next"))
    {
      std::string	tmp;

      tmp = context->getProfile().getName();
      if (tmp != "Choose Name")
	context->setContinue(true);
    }
  if (event.GUIEvent.Caller == context->getButton("Back"))
    offLib();
}

void	MyEventListener::listboxSelectedAgain(const irr::SEvent &event)
{
  if (event.GUIEvent.Caller == context->getListBox("list_profile"))
    {
      std::wstring	str;
      std::string	tmp;

      irr::s32 selected = context->getListBox("list_profile")->getSelected();
      context->setProfile(*getSave(selected));
      tmp = "Chosen Profile: ";
      tmp += context->getProfile().getName();
      tmp += " " + std::to_string(context->getProfile().getCourse());
      str = std::wstring(tmp.begin(), tmp.end());
      context->getListBox("selected_profile")->clear();
      context->getListBox("selected_profile")->addItem(str.c_str());
    }
}

void	MyEventListener::onLib()
{
  context->getButton("new_profile")->setVisible(false);
  context->getButton("select_profile")->setVisible(false);
  context->getButton("quit")->setVisible(false);
  context->getButton("Back")->setVisible(true);
}

void	MyEventListener::offLib()
{
  context->getNewName()->setVisible(false);
  context->getButton("new_profile")->setVisible(true);
  context->getButton("select_profile")->setVisible(true);
  context->getButton("quit")->setVisible(true);
  context->getButton("Back")->setVisible(false);
  context->getButton("Next")->setVisible(false);
  context->getButton("next_new")->setVisible(false);
  context->getListBox("list_profile")->setVisible(false);
  context->getListBox("selected_profile")->setVisible(false);
}

void	MyEventListener::setSaves(std::vector<Profile *> elem)
{
  this->saves = elem;
}

Profile	*MyEventListener::getSave(irr::s32 i)
{
  return (this->saves[i]);
}
