//
// Profile.hpp for  in /home/raguin_s/tek2/cpp_indie_studio/src
//
// Made by Simon RAGUIN
// Login   <raguin_s@epitech.net>
//
// Started on  Mon May 15 10:53:26 2017 Simon RAGUIN
// Last update Wed Jun 14 15:19:31 2017 Eloi Brehin
//

#ifndef PROFILE_HPP_
# define PROFILE_HPP_

#include <iostream>
#include <string>

class		Profile
{
private:
  std::string	name;
  int		course;
  std::string	choosenCar;

public:
  Profile(const std::string &);
  ~Profile();
  Profile	&operator=(const Profile &);
  Profile(const Profile &);
  std::string	getName() const;
  std::string	getChoosenCar() const;
  int		getCourse() const;
  void		setName(const std::string &);
  void		setCourse(int);
  void		setChoosenCar(std::string &);
};

#endif // !PROFILE_HPP_
