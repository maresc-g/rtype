//
// Action.hh for  in /home/ansel_l/Documents/Rtype/work
// 
// Made by laurent ansel
// Login   <ansel_l@epitech.net>
// 
// Started on  Sat Nov  2 17:50:22 2013 laurent ansel
// Last update Mon Nov  4 13:15:24 2013 laurent ansel
//

#ifndef 			__ACTION_HH__
# define 			__ACTION_HH__

#include			<string>

class				Action
{
public:
  enum				eAction
    {
      UP	=	(1 << 0),
      DOWN	=	(1 << 1),
      LEFT	=	(1 << 2),
      RIGHT	=	(1 << 3),
      FIRE	=	(1 << 4),
      QUITGAME	=	(1 << 5),
      QUITALL	=	(1 << 6),
      GAMELIST	=	(1 << 7),
      JOIN	=	(1 << 8),
      CREATE	=	(1 << 9),
    };
private:
  int				_action;
  std::string			_param;
public:
  Action();
  virtual ~Action();
  bool				getUp() const;
  bool				getDown() const;
  bool				getRight() const;
  bool				getLeft() const;
  bool				getFire() const;
  bool				getQuitGame() const;
  bool				getQuitAll() const;
  bool				getGameList() const;
  bool				getJoin() const;
  bool				getCreate() const;
  std::string const		&getParam() const;
  void				setUp(bool const set);
  void				setDown(bool const set);
  void				setRight(bool const set);
  void				setLeft(bool const set);
  void				setFire(bool const set);
  void				setQuitGame(bool const set);
  void				setQuitAll(bool const set);
  void				setGameList(bool const set);
  void				setJoin(bool const set);
  void				setCreate(bool const set);
  void				setParam(std::string const &param);
  bool				empty() const;
};

#endif
