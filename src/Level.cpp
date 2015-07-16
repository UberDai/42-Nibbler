
#include "Level.hpp"
#include <fstream>
#include <limits.h>
#include <cstdlib>

Level::Level(const std::string pathname)
{
	_loadLevel(pathname);
}

Level::~Level(void)
{
	unsigned	i;

	i = 0;
	while (i < _height)
	{
		delete map[i];
		i++;
	}

	delete map;
}

void	Level::_load(const std::string filename)
{
	std::ifstream	file(filename);
	std::string		line;
	unsigned		i;
	unsigned		j;

	_height = 0;

	while (std::getline(file, line))
		_height++;

	file.clear();
	file.seekg(0);

	_width = UINT_MAX;

	map = new (unsigned*)[_height];

	i = 0;
	while (std::getline(file, line))
	{
		if (_width == UINT_MAX)
			_width = line.size();
		else
		{
			if (_width == 0 || _width != line.size())
				throw; // bad line width
		}

		map[i] = new int[_width];

		j = 0;
		while (j < line.size())
		{
			map[i][j] = atoi(line[j]);
			j++;
		}

		i++;
	}
}

void	Level::setWidth(unsigned width)
{
	_width = width;
}

void	Level::setHeight(unsigned height)
{
	_height = height;
}
