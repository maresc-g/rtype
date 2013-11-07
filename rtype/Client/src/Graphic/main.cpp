//
// main.cpp for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Tue Oct 22 13:58:44 2013 cyril jourdain
// Last update Wed Nov  6 14:12:31 2013 cyril jourdain
//

#include	"Graphic/ClientMain.hh"

int		main(int, char **)
{
  ClientMain	*cMain = new ClientMain();

  cMain->init();
  cMain->launch();
  return 0;
}
