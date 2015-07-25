//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SDrawer.cpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-25 05:21:46
// :ddddddddddhyyddddddddddd: Modified: 2015-07-26 00:35:17
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

void		SDrawer::drawFull(sf::RenderWindow * renderer, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
	sf::ConvexShape quad1;
	quad1.setPointCount(4);
	quad1.setPoint(0, sf::Vector2f(-size.x, 0));
	quad1.setPoint(1, sf::Vector2f(0, size.y / 2));
	quad1.setPoint(2, sf::Vector2f(0, size.y));
	quad1.setPoint(3, sf::Vector2f(-size.x, size.y / 2));
	quad1.setPosition(position);
	quad1.setFillColor(color);
	quad1.setOutlineColor(sf::Color::Black);
	quad1.setOutlineThickness(0.5);
	renderer->draw(quad1);

	sf::ConvexShape quad2;
	quad2.setPointCount(4);
	quad2.setPoint(0, sf::Vector2f(size.x, 0));
	quad2.setPoint(1, sf::Vector2f(size.x, size.y / 2));
	quad2.setPoint(2, sf::Vector2f(0, size.y));
	quad2.setPoint(3, sf::Vector2f(0, size.y / 2));
	quad2.setPosition(position);
	quad2.setOutlineThickness(0.5);
	quad2.setFillColor(color);
	quad2.setOutlineColor(sf::Color::Black);
	renderer->draw(quad2);

	sf::ConvexShape quad3;
	quad3.setPointCount(4);
	quad3.setPoint(0, sf::Vector2f(0, 0));
	quad3.setPoint(1, sf::Vector2f(size.x, size.y / 2));
	quad3.setPoint(2, sf::Vector2f(0, size.y));
	quad3.setPoint(3, sf::Vector2f(-size.x, size.y / 2));
	quad3.setPosition(position.x, position.y - size.y / 2);
	quad3.setOutlineThickness(0.5);
	quad3.setFillColor(color);
	quad3.setOutlineColor(sf::Color::Black);
	renderer->draw(quad3);
}
