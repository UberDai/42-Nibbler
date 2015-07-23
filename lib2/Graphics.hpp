//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Graphics.hpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-23 23:56:40
// :ddddddddddhyyddddddddddd: Modified: 2015-07-24 01:07:15
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

# include <SFML/Graphics.hpp>
# include "IGraphics.hpp"

class Graphics : public IGraphics
{
public:
	Graphics(void);
	~Graphics(void);

	void	update(const Snake &);

private:
	Graphics(Graphics const &);
	Graphics &	operator=(Graphics const &);

};

extern "C" IGraphics *	glib_instantiate();

#endif
