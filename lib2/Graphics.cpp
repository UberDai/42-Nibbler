//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Graphics.cpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-23 23:54:14
// :ddddddddddhyyddddddddddd: Modified: 2015-07-24 00:27:54
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include "Graphics.hpp"

Graphics::Graphics(void)
{}

Graphics::~Graphics(void)
{}

void		Graphics::update(const Snake & snake)
{
	(void)snake;
}

IGraphics *	glib_instantiate()
{
	return new Graphics;
}
