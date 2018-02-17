//
// Intro.cpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Mon May 15 11:04:25 2017 Simon RAGUIN
// Last update Sun Jun 18 20:46:47 2017 Eloi Brehin
//

#include <fstream>
#include <iostream>
#include "Intro.hpp"
#include "Sound.hpp"

Intro::Intro(LibContainer *lib) :
  lib(lib)
{
  this->loadSaves();
  std::thread	logo(&Intro::loadLogoPath, this);
  std::thread	gsplash(&Intro::loadGSplashPath, this);

  logo.join();
  gsplash.join();
}

Intro::~Intro()
{
}

void				Intro::loadSaves()
{
  std::string			buff;
  int				idx;
  std::vector<std::string>	tmp;
  int				pos;
  std::ifstream			flux("../saves/save1");

  if (flux)
    while (getline(flux, buff))
      tmp.push_back(buff);
  if (tmp.size() == 0)
    tmp.push_back("nosave");
  idx = 0;
  if (tmp[0] == "nosave")
    this->createSaveFile();
  else
    {
      while (idx != tmp.size())
	{
	  pos = tmp[idx].find(" ");
	  buff = tmp[idx].substr(0, pos);
	  tmp[idx] = tmp[idx].substr(pos + 1);
	  Profile	*current = new Profile(buff);
	  current->setCourse(stoi(tmp[idx]));
	  saves.push_back(current);
	  idx = idx + 1;
	}
    }
}

void				Intro::createSaveFile()
{
  std::ofstream			save("../saves/save1");
  save.close();
}

std::vector<Profile *>	Intro::getSaves() const
{
  return (this->saves);
}

LibContainer		*Intro::getLib() const
{
  return (this->lib);
}

void			Intro::setSaves(std::vector<Profile *> elem)
{
  this->saves = elem;
}

void			Intro::initMainEnv()
{
  GUI::IGUIButton	*new_profile;
  GUI::IGUIButton	*select_profile;
  GUI::IGUIButton	*quit;
  GUI::IGUIButton	*back;
  GUI::IGUIButton	*next;
  GUI::IGUIButton	*next_new;
  GUI::IGUIListBox	*list_profile;
  GUI::IGUIListBox	*selected_profile;
  GUI::IGUIEditBox	*profile;

  //background
  this->lib->getGuienv()->getSkin()->setColor(GUI::EGDC_BUTTON_TEXT,
  					      VIDEO::SColor(255, 35, 16, 209));
  this->lib->getGuienv()->getSkin()->setColor(GUI::EGDC_HIGH_LIGHT_TEXT,
  					      VIDEO::SColor(255, 255,255,255));
  this->lib->getGuienv()->addImage(this->lib->getVDriver()->getTexture("../resources/fonts/forza_backgroung.jpeg"),
  				   CORE::position2d<int>(0,0));
  this->lib->getGuienv()->addImage(this->lib->getVDriver()->getTexture("../resources/fonts/title.png"),
				   CORE::position2d<int>((WIN_WIDTH / 2) - 500, 200));
  //button
  new_profile = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 650, XEND_B, 700),
						  0, -1, L"New Profile");
  select_profile = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 720, XEND_B, 770),
						     0, -1, L"Select Save");
  quit = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 790, XEND_B, 840),
					   0, -1, L"Quit");
  back = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 790, XEND_B, 840),
					   0, -1, L"Back");
  back->setVisible(false);
  next = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 720, XEND_B, 770),
					   0, -1, L"Next");
  next->setVisible(false);
  next_new = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 720, XEND_B, 770),
					       0, -1, L"Next");
  next_new->setVisible(false);
  //editBox
  profile = this->lib->getGuienv()->addEditBox(L"Choose Name",
					       CORE::rect<irr::s32>(XSTART_B, 650, XEND_B, 700));
  profile->setVisible(false);
  //
  //list

  // const core::rect<irr::s32> rect1(550, 400, 1000, 450);
  // this->lib->getGuienv()->addStaticText(L"Wololo ceci est un test de box", rect1, true, true);
  // selected_profile = this->lib->getGuienv()->addListBox(CORE::rect1);
  selected_profile = this->lib->getGuienv()->addListBox(CORE::rect<irr::s32>(XSTART_B, 400, XEND_B, 450));
  selected_profile->setVisible(false);
  selected_profile->setDrawBackground(true);
  list_profile = this->lib->getGuienv()->addListBox(CORE::rect<irr::s32>(XSTART_B, 500, XEND_B, 600));
  list_profile->setVisible(false);
  list_profile->setDrawBackground(true);
  initListProfile(list_profile, selected_profile);
  //
  context->setNewName(profile);
  context->addButton(new_profile, "new_profile");
  context->addButton(select_profile, "select_profile");
  context->addButton(quit, "quit");
  context->addButton(back, "Back");
  context->addButton(next, "Next");
  context->addButton(next_new, "next_new");
  context->addListBox(list_profile, "list_profile");
  context->addListBox(selected_profile, "selected_profile");
  context->setButtonBackground("../resources/fonts/button/button.png");
}

void			Intro::initListProfile(GUI::IGUIListBox *list_profile,
					       GUI::IGUIListBox *selected_profile)
{
  std::wstring		str;
  std::string		test;
  int			i = 0;

  while (i != this->saves.size())
    {
      test = this->saves[i]->getName();
      test += " " + std::to_string(this->saves[i]->getCourse());
      str = std::wstring(test.begin(), test.end());
      list_profile->addItem(str.c_str());// static_cast<const wchar_t*>(
      i = i + 1;
    }
  test = "Select profile";
  str = std::wstring(test.begin(), test.end());
  selected_profile->addItem(str.c_str());
}

void			Intro::startIntro(AEventListener *event)
{
  GUI::IGUISkin		*skin;
  GUI::IGUIFont		*font = this->lib->getGuienv()->getFont("../resources/fonts/button/Button.xml");
  GUI::IGUIStaticText	*title;

  skin = this->lib->getGuienv()->getSkin();
  if (font)
    skin->setFont(font);
  skin->setFont(this->lib->getGuienv()->getBuiltInFont(), GUI::EGDF_TOOLTIP);
  initMainEnv();
  while (lib->getDevice()->run()
	 && context->getContinue() == false
	 && context->getQuit() == false)
    {
      //mettre lintro avec la scenett
      irr::u32 realTimeNow = this->lib->getDevice()->getTimer()->getRealTime();
      context->update();
      lib->getVDriver()->beginScene(true, true, 0);
      lib->getSmgr()->drawAll();
      lib->getGuienv()->drawAll();
      lib->getVDriver()->endScene();
    }
  this->context->setContinue(false);
  this->context->setState(MENU);
}

void			Intro::loadVideo()
{
  while (lib->getDevice()->run()
	 && context->getContinue() == false
	 && this->logo.size() > 0)
    {
      //mettre lintro avec la scenett
      irr::u32 realTimeNow = this->lib->getDevice()->getTimer()->getRealTime();
      context->update();
      lib->getVDriver()->beginScene(true, true, 0);
      this->lib->getVDriver()->draw2DImage(this->lib->getVDriver()->getTexture(this->logo.front().c_str()),
					   CORE::position2d<int>(0,0));
      lib->getSmgr()->drawAll();
      lib->getGuienv()->drawAll();
      lib->getVDriver()->endScene();
      if (this->logo.size() % 80 == 0)
	this->lib->getVDriver()->removeAllTextures();
      this->logo.pop();
    }
  this->context->setContinue(false);
  this->context->setState(MENU);
  this->lib->getVDriver()->removeAllTextures();
}

void			Intro::loadGameSplash()
{
  int			nb = this->gsplash.size();
  while (lib->getDevice()->run()
	 && context->getContinue() == false
	 && this->gsplash.size() > 0)
    {
      //mettre lintro avec la scenett
      irr::u32 realTimeNow = this->lib->getDevice()->getTimer()->getRealTime();
      context->update();
      lib->getVDriver()->beginScene(true, true, 0);
      this->lib->getVDriver()->draw2DImage(this->lib->getVDriver()->getTexture(this->gsplash.front().c_str()),
					   CORE::position2d<int>(0,0));
      lib->getSmgr()->drawAll();
      lib->getGuienv()->drawAll();
      lib->getVDriver()->endScene();
      this->gsplash.pop();
      if (this->gsplash.size() % 100 == 0)
	this->lib->getVDriver()->removeAllTextures();
    }
  this->context->setContinue(false);
  this->context->setState(MENU);
  this->lib->getVDriver()->removeAllTextures();
}

void		Intro::loadLogoPath()
{
  int			idx = 1;
  std::string		path = "../resources/fonts/Intro/Intro ";
  std::string		number;
  std::string		res;

  for (int idx = 1; idx <= 320; idx++)
    {
      number = std::to_string(idx);
      if (idx < 10)
  	number = "00" + number;
      else if (idx < 100)
  	number = "0" + number;
      res = path + number + ".jpg";
      this->logo.push(res);
    }
}

void		Intro::loadGSplashPath()
{
  std::string		path = "../resources/fonts/GameIntro/";
  std::string		number;
  std::string		res;

  for (int idx = 0; idx <= 435; idx++)
    {
      number = std::to_string(idx);
      if (idx < 10)
	number = "00000" + number;
      else if (idx < 100)
	number = "0000" + number;
      else
	number = "000" + number;
      res = path + number + ".jpg";
      this->gsplash.push(res);
    }
}
