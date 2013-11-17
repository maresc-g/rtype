//
// SFConnect.hh for  in /home/jourda_c/Documents/C++/RType/Sources
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Wed Nov  6 01:59:32 2013 cyril jourdain
// Last update Fri Nov 15 19:50:01 2013 cyril jourdain
//

#ifndef 		__SFCONNECT_HH__
# define 		__SFCONNECT_HH__

#include		<list>
#include		<functional>
#include		<SFML/Graphics.hpp>
#include		"Utility/Singleton.hpp"
#include		"Graphic/SFGraphics/Widgets/SFWidget.hh"

class			SFConnect : public Singleton<SFConnect>
{
  friend class Singleton<SFConnect>;

public:
  struct EventCallback
  {
  public:
    std::function<void (void *const)>		_function;
    void					*_param;
  };
private:
  struct s_ObjConnect
  {
  public:
	  s_ObjConnect() : _callbackList(new std::map<sf::Event::EventType, EventCallback *>){}
  private:
    std::map<sf::Event::EventType, EventCallback *>	*_callbackList;
    SFWidget			*_caller;
  public:
    SFWidget			*getCaller() {return _caller;};
    bool			operator==(s_ObjConnect &other) const
    {
      if (other.getCaller() && other.getCaller() == _caller)
	return true;
      return false;
    }
    bool			operator==(SFWidget *other) const
    {
      if (other && _caller == other)
    	return true;
      return false;
    }
    template<class T>
    void			addCallback(sf::Event::EventType type,
					    void (T::*func)(void *const),
					    void *param,
					    T* target)
    {
      (*_callbackList)[type] = new EventCallback();
      (*_callbackList)[type]->_function = std::bind(func, target, std::placeholders::_1);
      (*_callbackList)[type]->_param = param;
    }
    void			setCaller(SFWidget *caller)
    {
      _caller = caller;
    }
    void			call(sf::Event::EventType type)
    {
      if (_callbackList->find(type) != _callbackList->end())
	(*_callbackList)[type]->_function((*_callbackList)[type]->_param);
    }
  };

private:
  std::list<s_ObjConnect>	_functionList;

private:
  SFConnect(){};
  virtual ~SFConnect(){};

public:
  template <class T>
  void				makeConnect(sf::Event::EventType type,
					    SFWidget *caller,
					    void (T::*f)(void *const),
					    void *param,
					    T *target)
  {
    s_ObjConnect		obj;

    obj.setCaller(caller);
    obj.addCallback(type, f, param, target);
    _functionList.push_back(obj);
  }
  void				callCallback(sf::Event *const event, SFWidget *focus)
  {
    if (focus)
      {
	auto obj = find(_functionList.begin(), _functionList.end(), focus);
	if (obj != _functionList.end())
	  obj->call(event->type);
      }
  }
};

#endif
