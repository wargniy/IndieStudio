//
// main.cpp for  in /home/ziri.belabbas/rendu/cpp/cpp_indie_studio/build
//
// Made by Ziri Belabbas
// Login   <ziri.belabbas@epitech.net>
//
// Started on  Tue May  9 18:05:45 2017 Ziri Belabbas
// Last update Wed May 31 08:38:19 2017 Eloi Brehin
//

#include "Distrib.hpp"

#ifdef _IRR_WINDOWS_
# pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

int		main()
{
  try
    {
      Distrib	distrib;

      distrib.startGame();
    }
  catch (...)
    {
      std::cerr << "An error occured..." << std::endl;
    }
  return EXIT_SUCCESS;
}
