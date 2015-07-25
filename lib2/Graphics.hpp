//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Graphics.hpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-23 23:56:40
// :ddddddddddhyyddddddddddd: Modified: 2015-07-25 05:35:34
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
	Graphics(const Snake &);
	~Graphics(void);

	void	update(void);

private:
	const Snake &		_snake;
	sf::RenderWindow *	_window;
	unsigned int		_winWidth;
	unsigned int		_winHeight;
	unsigned int		_width;
	unsigned int		_height;
	unsigned int		_scaleWidth;
	unsigned int		_scaleHeight;
	unsigned int		_drawScale;

	Graphics(void);
	Graphics(Graphics const &);
	Graphics &	operator=(Graphics const &);

	void				getLevelInfo();
	void				draw();
};

extern "C" IGraphics *	glib_instantiate(const Snake &);
extern "C" void			glib_uninstantiate(IGraphics *);

#endif
