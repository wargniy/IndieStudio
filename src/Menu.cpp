//
// Menu.cpp for cpp_indie_stdio in /home/brehin_e/rendu/cpp_indie_studio
//
// Made by Eloi Brehin
// Login   <brehin_e@epitech.net>
//
// Started on  Mon May 29 10:53:41 2017 Eloi Brehin
// Last update Sun Jun 18 21:44:26 2017 Eloi Brehin
//

#include "Menu.hpp"

Menu::Menu(LibContainer *lib, SAppContext *context)
{
  this->lib = lib;
  this->context = context;
  this->username = this->context->getProfile().getName();
  this->nbCourse = this->context->getProfile().getCourse();
}

Menu::~Menu()
{
}

void	Menu::setLib(LibContainer *lib)
{
  this->lib = lib;
}

void		Menu::setContext(SAppContext *context)
{
  this->context = context;
}

void		Menu::setNbPlayers(int nbPlayers)
{
  this->nbPlayers = nbPlayers;
}

void		Menu::initButtons()
{
  GUI::IGUIButton	*play;
  GUI::IGUIButton	*options;
  GUI::IGUIButton	*credits;
  GUI::IGUIButton	*quit;
  GUI::IGUIButton	*back;
  GUI::IGUIButton	*backSelect;
  GUI::IGUIButton	*addPlayer;
  GUI::IGUIButton	*delPlayer;
  GUI::IGUIButton	*next;
  GUI::IGUIButton	*nextGame;
  GUI::IGUIButton	*left;
  GUI::IGUIButton	*right;

  play = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 650, XEND_B, 700),
					   0, -1, L"Play");
  context->addButton(play, "play");
  options = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 720, XEND_B, 770),
					   0, -1, L"Options");
  context->addButton(options, "options");
  credits = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 790, XEND_B, 840),
					      0, -1, L"Credits");
  context->addButton(credits, "credits");
  quit = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B, 860, XEND_B, 910),
					      0, -1, L"Quit");
  context->addButton(quit, "quit");
  back = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(280, 860,
								680, 910),
					   0, -1, L"Back");
  back->setVisible(false);
  context->addButton(back, "back");
  backSelect = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(280, 860,
								      680, 910),
						 0, -1, L"Back");
  backSelect->setVisible(false);
  context->addButton(backSelect, "backSelect");
  next = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(1240, 860,
								1640, 910),
						0, -1, L"Next");
  next->setVisible(false);
  context->addButton(next, "next");
  nextGame = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(1240, 860,
								    1640, 910),
					       0, -1, L"Next");
  nextGame->setVisible(false);
  context->addButton(nextGame, "nextGame");
  addPlayer = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XSTART_B - 300, 220,
								     XSTART_B, 270),
						0, -1, L"+");
  addPlayer->setVisible(false);
  context->addButton(addPlayer, "addPlayer");
  delPlayer = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(XEND_B, 220,
								     XEND_B + 300, 270),
						0, -1, L"-");
  delPlayer->setVisible(false);
  context->addButton(delPlayer, "delPlayer");
  left = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(280, 660,
								680, 710),
					   0, -1, L"");
  left->setVisible(false);
  context->addButton(left, "left");
  right = this->lib->getGuienv()->addButton(CORE::rect<irr::s32>(1240, 660,
								 1640, 710),
					    0, -1, L"");
  right->setVisible(false);
  context->addButton(right, "right");
  context->setButtonBackground("../resources/fonts/button/button.png");
  context->getButton("left")->setImage(this->lib->getVDriver()
				       ->getTexture("../resources/fonts/arrow_left.png"));
  context->getButton("right")->setImage(this->lib->getVDriver()
					->getTexture("../resources/fonts/arrow_right.png"));
  context->getButton("left")->setPressedImage(this->lib->getVDriver()
					      ->getTexture("../resources/fonts/arrow_left.png"));
  context->getButton("right")->setPressedImage(this->lib->getVDriver()
					       ->getTexture("../resources/fonts/arrow_right.png"));
  context->getButton("left")->setUseAlphaChannel(true);
  context->getButton("right")->setUseAlphaChannel(true);
}

void		Menu::initCredits()
{
  std::ifstream	file;
  std::string	text;
  std::string	buf;

  file.open("../resources/Credits.txt");
  if (file.is_open())
    {
      while (std::getline(file, buf, '\n'))
	text += buf + "\n";
    }

  CORE::stringw	credit = CORE::stringw(text.c_str()).c_str();
  GUI::IGUIStaticText *credits = this->lib->getGuienv()
    ->addStaticText(credit.c_str(), CORE::rect<irr::s32>(XSTART_B, 200,
					    XSTART_B + 800, 1800));
  credits->setVisible(false);
  credits->setBackgroundColor(VIDEO::SColor(200, 112, 159, 255));
  this->context->addText(credits, "credits");
}

void		Menu::initMainEnv(AEventListener *event)
{
  this->lib->getDevice()->setEventReceiver(event);
  this->lib->getGuienv()->clear();
  context->reinitButtons();
  context->reinitText();

  GUI::IGUIImage	*title;
  GUI::IGUIImage	*background;
  GUI::IGUIImage	*garage;
  GUI::IGUIImage	*player1;
  GUI::IGUIImage	*player2;
  GUI::IGUIImage	*player3;
  GUI::IGUIImage	*player4;

  background = this->lib->getGuienv()->addImage(this->lib->getVDriver()->
						getTexture("../resources/fonts/forza_backgroung.jpeg"),
						CORE::position2d<int>(0,0));
  this->context->addImage(background, "background");
  title = this->lib->getGuienv()->addImage(this->lib->getVDriver()->
					   getTexture("../resources/fonts/title.png"),
					   CORE::position2d<int>((WIN_WIDTH / 2) - 500, 200));
  this->context->addImage(title, "title");
  garage = this->lib->getGuienv()->addImage(this->lib->getVDriver()->
					    getTexture("../resources/fonts/garage.jpeg"),
					    CORE::position2d<int>(0,0));
  garage->setVisible(false);
  this->context->addImage(garage, "garage");
  player1 = this->lib->getGuienv()->addImage(this->lib->getVDriver()->
					   getTexture("../resources/fonts/player1.png"),
					   CORE::position2d<int>((WIN_WIDTH / 2) - 500, 200));
  player1->setVisible(false);
  this->context->addImage(player1, "player1");
  player2 = this->lib->getGuienv()->addImage(this->lib->getVDriver()->
					   getTexture("../resources/fonts/player2.png"),
					   CORE::position2d<int>((WIN_WIDTH / 2) - 500, 200));
  player2->setVisible(false);
  this->context->addImage(player2, "player2");
  player3 = this->lib->getGuienv()->addImage(this->lib->getVDriver()->
					     getTexture("../resources/fonts/player3.png"),
					     CORE::position2d<int>((WIN_WIDTH / 2) - 500, 200));
  player3->setVisible(false);
  this->context->addImage(player3, "player3");
  player4 = this->lib->getGuienv()->addImage(this->lib->getVDriver()->
					     getTexture("../resources/fonts/player4.png"),
					     CORE::position2d<int>((WIN_WIDTH / 2) - 500, 200));
  player4->setVisible(false);
  this->context->addImage(player4, "player4");

  this->initButtons();
  this->initCredits();
  this->initListBox();
  this->initTabs();
  this->initChoice();
}

void		Menu::initTabs()
{
  GUI::IGUIStaticText	*volume = this->lib->getGuienv()
    ->addStaticText(L"Volume",
  		    CORE::rect<irr::s32>(20, 20, 150, 60), false, true,
  		    this->context->getTab("general"));
  GUI::IGUIScrollBar	*vol	= this->lib->getGuienv()
    ->addScrollBar(true, CORE::rect<irr::s32>(160, 30, 860, 50),
		   this->context->getTab("general"));
  vol->setMax(100);
  vol->setMin(0);
  vol->setPos(100);
  this->context->setScrollBar(vol);
}

void		Menu::initListBox()
{
  GUI::IGUITabControl	*opt = this->lib->getGuienv()
    ->addTabControl(CORE::rect<irr::s32>((WIN_WIDTH / 2) - 500, 300, (WIN_WIDTH / 2) + 500, 800));
  opt->setVisible(false);
  GUI::IGUIListBox	*nbPlayers = this->lib->getGuienv()
    ->addListBox(CORE::rect<irr::s32>((WIN_WIDTH / 2) - 500, 300, (WIN_WIDTH / 2) + 500, 800));
  GUI::IGUITab		*general = opt->addTab(L"General");
  general->setBackgroundColor(VIDEO::SColor(200, 112, 159, 255));
  general->setDrawBackground(true);

  nbPlayers->setVisible(false);
  this->context->setTabCtrl(opt);
  this->context->addListBox(nbPlayers, "nbPlayers");
  this->context->addTab(general, "general");
}

void		Menu::initChoice()
{
  SCENE::IAnimatedMesh* mesh = this->lib->getSmgr()->getMesh("../resources/PoliceCar.3DS");
  if (!mesh)
    throw std::runtime_error("Mesh not loaded");
  SCENE::IAnimatedMeshSceneNode* node = this->lib->getSmgr()->
    addAnimatedMeshSceneNode(mesh);

  if (node)
    {
      node->setMaterialFlag(VIDEO::EMF_LIGHTING, true);
      node->setScale(CORE::vector3df(0.009, 0.009, 0.009));
      node->setRotation(CORE::vector3df(40, 50, 30));
      node->setPosition(CORE::vector3df(5.f, -10.f, 0.f));
      node->setMD2Animation(SCENE::EMAT_STAND);
      node->setMaterialTexture(0, this->lib->getVDriver()
  			       ->getTexture("../resources/fonts/sferiff_red.png"));
    }
  node->setVisible(false);
  this->context->addMesh(node, "Mustang");
  this->context->setCam(this->lib->getSmgr()->
  			addCameraSceneNode(0, CORE::vector3df(0,30,-40), CORE::vector3df(0,5,0)));
  this->lib->getSmgr()->setAmbientLight(VIDEO::SColorf(0.6f, 0.6f, 0.6f));

  SCENE::IAnimatedMesh* mesh2 = this->lib->getSmgr()->
    getMesh("../resources/models/pickup/pcikup.obj");
  if (!mesh2)
    throw std::runtime_error("Mesh not loaded");
  SCENE::IAnimatedMeshSceneNode* node2 = this->lib->getSmgr()->
    addAnimatedMeshSceneNode(mesh2);

  if (node2)
    {
      node2->setMaterialFlag(VIDEO::EMF_LIGHTING, true);
      node2->setScale(CORE::vector3df(12.0, 12.0, 12.0));
      node2->setRotation(CORE::vector3df(40, 50, 30));
      node2->setPosition(CORE::vector3df(5.f, -20.f, 0.f));
      node2->setMD2Animation(SCENE::EMAT_STAND);
      node2->setMaterialTexture(0, this->lib->getVDriver()
      			       ->getTexture("../resources/fonts/car01_red.png"));
    }
  node2->setVisible(false);
  this->context->addMesh(node2, "Pickup");
  this->context->setCam(this->lib->getSmgr()->
  			addCameraSceneNode(0, CORE::vector3df(0,30,-40), CORE::vector3df(0,5,0)));
  this->lib->getSmgr()->setAmbientLight(VIDEO::SColorf(2.f, 2.f, 2.f));
}

void		Menu::startMenu(MenuEventListener *event)
{
  initMainEnv(event);
  int		pos = WIN_HEIGHT;

  if (this->context->getState() == CREDITS)
    {
      event->showCredits();
      this->context->getButton("back")->setVisible(false);
    }
  while (this->lib->getDevice()->run()
	 && context->getQuit() == false
	 && context->getContinue() == false)
    {
      irr::u32 realTimeNow = this->lib->getDevice()->getTimer()->getRealTime();
      context->update();
      lib->getVDriver()->beginScene(true, true, 0);
      if (this->context->getState() == CREDITS)
	{
	  this->context->getText("credits")->
	    setRelativePosition(CORE::position2di(XSTART_B, pos));
	  pos--;
	  if (pos + 1600 < 0
	      && this->context->getButton("back")->isVisible() == false)
	    {
	      this->context->setQuit(true);
	    }
	}
      else if (this->context->getState() == MENU)
	pos = WIN_HEIGHT;
      lib->getGuienv()->drawAll();
      lib->getSmgr()->drawAll();
      lib->getVDriver()->endScene();
    }
}
