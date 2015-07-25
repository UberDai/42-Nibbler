//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  42-Nibbler:SDrawer
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-25 05:17:42
// :ddddddddddhyyddddddddddd: Modified: 2015-07-25 05:25:54
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
private:
	SDrawer(void);
	SDrawer(SDrawer const &);
	~SDrawer(void);

	SDrawer &	operator=(SDrawer const &);
};

#endif
