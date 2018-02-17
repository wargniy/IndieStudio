//
// SAppContext.cpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Tue May 16 14:01:10 2017 Simon RAGUIN
// Last update Fri Jun 16 14:08:22 2017 Eloi Brehin
//

#include "SAppContext.hpp"

SAppContext::SAppContext() : AContext(SPLASH_SCR), profile("Choose Name")
{
}

SAppContext::~SAppContext()
{
}

void	SAppContext::update()
{
  if (!Device)
    return ;
  irr::u32 timeNow = Device->getTimer()->getTime();
  for (irr::u32 i = 0; i < TimerActions.size(); ++i)
    {
      if (timeNow >= TimerActions[i].TargetTime)
	{
	  runTimerAction(TimerActions[i]);
	  TimerActions.erase(i);
	}
      else
	++i;
    }
}

void	SAppContext::runTimerAction(const TimerAction &action)
{
  std::map<std::string, GUI::IGUIButton *>::iterator	i;

  i = Button.begin();
  if (ETA_MOUSE_VISIBLE == action.Action)
    {
      this->Device->getCursorControl()->setVisible(true);
      while (i != this->Button.end())
	{
	  (*i).second->setEnabled(true);
	  ++i;
	}
    }
  else if (ETA_MOUSE_INVISIBLE == action.Action)
    {
      this->Device->getCursorControl()->setVisible(false);
      while (i != this->Button.end())
	{
	  (*i).second->setEnabled(true);
	  ++i;
	}
    }
}

void	SAppContext::addText(GUI::IGUIStaticText *text, std::string name)
{
  this->Text[name] = text;
}

void	SAppContext::addListBox(GUI::IGUIListBox *list, std::string str)
{
  this->list_box[str] = list;
}

void	SAppContext::setProfile(const Profile &elem)
{
  this->profile = elem;
}

void	SAppContext::addTab(GUI::IGUITab *tab, std::string str)
{
  this->tabs[str] = tab;
}

void	SAppContext::addMesh(SCENE::IAnimatedMeshSceneNode *mesh, std::string str)
{
  this->choice[str] = mesh;
}

void	SAppContext::addImage(GUI::IGUIImage *image, std::string str)
{
  this->images[str] = image;
}

void	SAppContext::reinitText()
{
  this->Text.clear();
}

GUI::IGUITabControl	*SAppContext::getTabCtrl()
{
  return (this->tabCtrl);
}

void	SAppContext::setTabCtrl(GUI::IGUITabControl *tabCtrl)
{
  this->tabCtrl = tabCtrl;
}

void	SAppContext::setNewName(GUI::IGUIEditBox *elem)
{
  this->newProfile = elem;
}

void	SAppContext::setScrollBar(GUI::IGUIScrollBar *scroll)
{
  this->scroll = scroll;
}

void	SAppContext::setCam(SCENE::ICameraSceneNode *cam)
{
  this->cam = cam;
}

GUI::IGUIStaticText	*SAppContext::getText(const std::string str)
{
  return (this->Text[str]);
}

GUI::IGUIListBox	*SAppContext::getListBox(const std::string str)
{
  return (this->list_box[str]);
}

Profile			SAppContext::getProfile()
{
  return (this->profile);
}

GUI::IGUIEditBox	*SAppContext::getNewName()
{
  return (this->newProfile);
}

GUI::IGUIImage		*SAppContext::getImage(const std::string str)
{
  return (this->images[str]);
}

GUI::IGUITab		*SAppContext::getTab(const std::string str)
{
  return (this->tabs[str]);
}

GUI::IGUIScrollBar	*SAppContext::getScrollBar()
{
  return (this->scroll);
}

SCENE::IAnimatedMeshSceneNode	*SAppContext::getMesh(const std::string str)
{
  return (this->choice[str]);
}

SCENE::ICameraSceneNode		*SAppContext::getCam()
{
  return this->cam;
}

std::string			SAppContext::getCar()
{
  for (auto e : this->choice)
    {
      if (e.second->isVisible() == true)
	return e.first;
    }
}
