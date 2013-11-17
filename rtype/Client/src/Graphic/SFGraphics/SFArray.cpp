//
// SFArray.cpp for  in /home/jourda_c/Documents/C++/Rtype_GIT/rtype/rtype
// 
// Made by cyril jourdain
// Login   <jourda_c@epitech.net>
// 
// Started on  Fri Nov  8 15:38:07 2013 cyril jourdain
// Last update Thu Nov 14 17:25:20 2013 cyril jourdain
//

#include		"Graphic/SFGraphics/Widgets/SFArray.hh"
#include		"Graphic/SFGraphics/Ressources/SFRessourcesManager.hh"
#include		"Graphic/Global.hh"

SFArray::SFArray() :
  SFWidget()
{
  _customView = new sf::View(sf::FloatRect(0,0,WIN_X,WIN_Y));
  _customView->setViewport(sf::FloatRect(0,0,0.5,0.5));
  _nbColumn = 0;
  _bounds->left = 0;
  _bounds->top = 0;
  _bounds->width = WIN_X * _customView->getViewport().width;
  _bounds->height = WIN_Y * _customView->getViewport().height;
  _selected = NULL;
}

SFArray::~SFArray()
{
}


void			SFArray::init()
{
  std::cout << _renderTarget << std::endl;
  _background = new SFImageBox();
  _background->init();
  _background->setSize(WIN_X, WIN_Y);
  _lineArray = new std::vector<SFArrayLine *>;
}

void			SFArray::create(std::list<std::string> const list)
{
  _nbColumn = (list.size() > 0 ? list.size() : 1);
  _titleLine = new SFArrayLine(std::list<std::string>(list),
			       sf::Vector2f(0,0),
   			       sf::Vector2f(_background->getBound().width, 80));
  for (auto it = list.begin(); it != list.end(); it++)
    (*_titleLine)[*it].setText(*it);
}

void			SFArray::setSize(float const x, float const y)
{
  //_background->setSize(x, y);
  _bounds->width = x;
  _bounds->height = y;
  _customView->setViewport(sf::FloatRect(_bounds->left / WIN_X,
				   _bounds->top / WIN_Y,
				   _bounds->width / WIN_X,
				   _bounds->height / WIN_Y));  
}

void			SFArray::setPosition(float const x, float const y)
{
  SFWidget::setPosition(sf::Vector2f(x, y));
  // _background->setPosition(x, y);
  _bounds->left = x;
  _bounds->top = y;
  _customView->setViewport(sf::FloatRect(_bounds->left / WIN_X,
				   _bounds->top / WIN_Y,
				   _bounds->width / WIN_X,
				   _bounds->height / WIN_Y));  
}

void			SFArray::setBackgroundTexture(sf::Texture *const texture)
{
  _background->setTexture(texture);
}

void			SFArray::addLine()
{
  _lineArray->push_back(new SFArrayLine(*_titleLine->getFieldList(),
					sf::Vector2f(0,80 * (_lineArray->size() + 1)),
  					sf::Vector2f(_background->getBound().width,
  						     80)));
}

SFArrayLine		&SFArray::operator[](unsigned int index)
{
  return *(*_lineArray)[index];
}

void			SFArray::clear()
{
  if (_lineArray)
    {
      for (auto it = _lineArray->begin(); it != _lineArray->end(); it++)
	delete *it;
      _lineArray->clear();
      _selected = NULL;
    }
}

sf::FloatRect		&SFArray::getBound() const
{
  // need to fix left and top
  // _bounds->left = WIN_X * _customView->getViewport().left;
  // _bounds->top = WIN_Y * _customView->getViewport().top;
  _bounds->width = WIN_X * _customView->getViewport().width;
  _bounds->height = WIN_Y * _customView->getViewport().height;
  return *_bounds;
}

void			SFArray::onClick(void *const param)
{
  sf::Vector2i	mousePos;
  sf::Vector2f	mouseViewPos;

  mousePos.x = (static_cast<sf::Event*>(param))->mouseButton.x;
  mousePos.y = (static_cast<sf::Event*>(param))->mouseButton.y;
  mouseViewPos = _renderTarget->mapPixelToCoords(mousePos, *_customView);
  for (auto it = _lineArray->begin(); it != _lineArray->end(); ++it)
    {
      if ((*it)->mouseIn(mouseViewPos))
	{
	  if (_selected)
	    _selected->setSelected(false);
	  (*it)->setSelected(true);
	  _selected = *it;
	  std::cout << "Click : " << (*(*it))["ID"].getData() << std::endl;
	}
    }
}

void			SFArray::onMouseWheelMove(void *const param)
{
  static int		moved = 0;
  int			delta = static_cast<sf::Event*>(param)->mouseWheel.delta * -10;

  if (moved - delta <= 0 && _lineArray->size() > 8 && moved - delta >= (static_cast<int>((_lineArray->size()) - 8) * -80))
    {
      _customView->move(0,delta);
      _background->move(0,delta);
      moved -= delta;
    }
}

void			SFArray::draw(sf::RenderTarget &target, sf::RenderStates) const
{
  //states.transform *= getTransform();
  // if (_backgroundTexture)
  //   states.texture = _backgroundTexture;
  //target.draw(*_background, states);
  _titleLine->draw(target);
  for (auto it = _lineArray->begin(); it != _lineArray->end(); ++it)
    (*it)->draw(target);
}
