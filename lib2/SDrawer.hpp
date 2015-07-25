//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  SDrawer.hpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-25 05:17:42
// :ddddddddddhyyddddddddddd: Modified: 2015-07-26 00:33:53
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef SDRAWER_HPP
# define SDRAWER_HPP

# include <SFML/Graphics.hpp>

class SDrawer {
public:
	static void		drawCell(sf::RenderWindow * renderer, sf::Vector2f position, sf::Vector2f size);
	static void		drawFull(sf::RenderWindow * renderer, sf::Vector2f position, sf::Vector2f size, sf::Color color);
private:
	SDrawer(void);
	SDrawer(SDrawer const &);
	~SDrawer(void);

	SDrawer &	operator=(SDrawer const &);
};

#endif
