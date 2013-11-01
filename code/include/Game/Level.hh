//
// Level.hh for level in /home/maitre_c/work/local/rtype/code
// 
// Made by antoine maitre
// Login   <maitre_c@epitech.net>
// 
// Started on  Tue Oct 29 16:17:37 2013 antoine maitre
// Last update Fri Nov  1 10:56:08 2013 arthur rucquois
//

#ifndef	__LEVEL_HH__
#define __LEVEL_HH__

class	Level
{
private:
  int		adv;

public:
  const int	getAdv() const;
  void		incAdv();

public:
  Level();
  ~Level();
};

#endif
