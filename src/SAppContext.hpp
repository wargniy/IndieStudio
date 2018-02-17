//
// SAppContext.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Tue May 16 13:35:22 2017 Simon RAGUIN
// Last update Fri Jun 16 14:08:19 2017 Eloi Brehin
//

#ifndef SAPPCONTEXT_HPP_
# define SAPPCONTEXT_HPP_

#include "AContext.hpp"

class						SAppContext : public AContext
{
private:
  GUI::IGUIEditBox				*newProfile;
  Profile					profile;
  std::map<std::string, GUI::IGUIListBox *>	list_box;
  std::map<std::string, GUI::IGUIStaticText *>	Text;
  std::map<std::string, GUI::IGUIImage *>	images;
  std::map<std::string, GUI::IGUITab *>		tabs;
  GUI::IGUITabControl				*tabCtrl;
  GUI::IGUIScrollBar				*scroll;
  GUI::IGUIComboBox				*res;
  SCENE::ICameraSceneNode			*cam;
  std::map<std::string, SCENE::IAnimatedMeshSceneNode	*>	choice;

public:
  SAppContext();
  ~SAppContext();

  void	update();
  void	runTimerAction(const TimerAction&);
  void	addListBox(GUI::IGUIListBox *, std::string);
  void	addText(GUI::IGUIStaticText *, std::string);
  void	addTab(GUI::IGUITab *, std::string);
  void	setTabCtrl(GUI::IGUITabControl *);
  void	setScrollBar(GUI::IGUIScrollBar *);
  void	addMesh(SCENE::IAnimatedMeshSceneNode *, std::string);
  void	addImage(GUI::IGUIImage *, std::string);
  //setter
  void	setProfile(const Profile &);
  void	setNewName(GUI::IGUIEditBox *);
  void	setCam(SCENE::ICameraSceneNode *);
  void	reinitText();

  //getter
  GUI::IGUIStaticText			*getText(const std::string);
  GUI::IGUIListBox			*getListBox(const std::string);
  Profile				getProfile();
  GUI::IGUIEditBox			*getNewName();
  GUI::IGUIImage			*getImage(const std::string);
  GUI::IGUISpinBox			*getSpinBox() const;
  GUI::IGUITabControl			*getTabCtrl();
  GUI::IGUITab				*getTab(const std::string);
  GUI::IGUIScrollBar			*getScrollBar();
  GUI::IGUIComboBox			*getComboBox();
  SCENE::IAnimatedMeshSceneNode		*getMesh(const std::string);
  SCENE::ICameraSceneNode		*getCam();
  std::string				getCar();
};

#endif // !SAPPCONTEXT_HPP_
