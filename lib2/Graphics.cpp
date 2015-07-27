//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Graphics.cpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-23 23:54:14
// :ddddddddddhyyddddddddddd: Modified: 2015-07-27 02:07:50
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

# include <iostream>
#include "Graphics.hpp"
#include "SDrawer.hpp"

Graphics::Graphics(const Snake & s) : _snake(s)
{
	sf::ContextSettings		settings;
	settings.antialiasingLevel = 8;

	_winWidth = 800;
	_winHeight = 600;
	_window = new sf::RenderWindow(sf::VideoMode(_winWidth, _winHeight), "Da SFML Snake");
}

Graphics::~Graphics(void)
{
	_window->close();
	glib_action = QUIT;
}

void		Graphics::update(void)
{
	sf::Event event;

	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_window->close();
			glib_action = QUIT;
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				glib_action = QUIT;
			if (event.key.code == sf::Keyboard::P)
				glib_action = PAUSE;
			if (event.key.code == sf::Keyboard::Up)
				glib_action = UP;
			if (event.key.code == sf::Keyboard::Down)
				glib_action = DOWN;
			if (event.key.code == sf::Keyboard::Left)
				glib_action = LEFT;
			if (event.key.code == sf::Keyboard::Right)
				glib_action = RIGHT;
		}
	}
	draw();
}

void		Graphics::getLevelInfo()
{
	_width = _snake.level->width;
	_height = _snake.level->height;
	_scaleWidth = _winWidth / _width;
	_scaleHeight = _winHeight / _height;

	std::cout << "DEBUG: " <<
	"_width: " << _width <<
	"_height: " << _height <<
	"_scaleWidth: " << _scaleWidth <<
	"_scaleHeight: " << _scaleHeight << std::endl;

	_drawScale = _scaleHeight / 2;
}

void		Graphics::_switch(sf::Vector2<int> index, sf::RenderWindow * _window, sf::Vector2<int> position, sf::Vector2<int> size)
{
	switch (_snake.level->map[index.y][index.x])
	{
		case BLOCK_NONE:
			SDrawer::drawCell(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y));
			break;
		case BLOCK_WALL:
			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(200, 200, 200));
			break;
		case BLOCK_NOM:
			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(242, 43, 0));
			break;
		case BLOCK_HEAD:
			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(76, 153, 0));
			break;
		default:
			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(204, 102, 0));
	}
}

void		Graphics::draw(void)
{
	unsigned int	middle = _winWidth / 2;
	getLevelInfo();
	_window->clear();

	unsigned int x = middle;
	unsigned int y = 0;
	unsigned int i;
	unsigned int j;
	for (i = 0; i < _snake.level->width; i++)
	{
		x = middle - (_drawScale * i);
		y = _drawScale * i;

		for(j = 0; j < _snake.level->height; j++)
		{
			_switch(sf::Vector2<int>(i, j), _window, sf::Vector2<int>(x, y), sf::Vector2<int>(_drawScale, _drawScale));
			x += _drawScale;
			y += _drawScale;
		}
	}

	_window->display();
}

IGraphics *	glib_instantiate(const Snake & s)
{
	return new Graphics(s);
}

void		glib_uninstantiate(IGraphics * g)
{
	delete g;
}
