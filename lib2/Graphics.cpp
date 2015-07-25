//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Graphics.cpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-23 23:54:14
// :ddddddddddhyyddddddddddd: Modified: 2015-07-25 05:37:33
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
{}

void		Graphics::update(void)
{
	std::cout << "update: "<< _snake.level->width << std::endl;

	sf::Event event;

	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window->close();
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
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

	if (_scaleWidth < _scaleHeight)
		_drawScale = _scaleWidth / 2;
	else
		_drawScale = _scaleHeight / 2;

	std::cout << _drawScale << std::endl;
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
		for(j = 0; j < _snake.level->height; j++)
		{
			SDrawer::drawCell(_window, sf::Vector2f(x, y), sf::Vector2f(_drawScale, _drawScale));
			x += 20;
			y += 20;
		}
		x = middle - ((20 * i));
		y = ((20 * i));
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
