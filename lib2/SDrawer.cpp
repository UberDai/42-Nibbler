//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  42-Nibbler:SDrawer
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-25 05:21:46
// :ddddddddddhyyddddddddddd: Modified: 2015-07-25 05:31:36
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include "SDrawer.hpp"

void		SDrawer::drawCell(sf::RenderWindow * renderer, sf::Vector2f position, sf::Vector2f size)
{
	sf::ConvexShape rect;

	rect.setPointCount(4);
	rect.setPoint(0, sf::Vector2f(0, 0));
	rect.setPoint(1, sf::Vector2f(size.x, size.y / 2));
	rect.setPoint(2, sf::Vector2f(0, size.y));
	rect.setPoint(3, sf::Vector2f(-size.x, size.y / 2));
	rect.setPosition(position);
	rect.setOutlineColor(sf::Color(150, 150, 150));
	rect.setOutlineThickness(0.5);
	renderer->draw(rect);
}
