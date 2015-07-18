
#include "Level.hpp"
#include <fstream>
#include <limits.h>
#include <cstdlib>

Level::Level(const std::string pathname) :
	width(_width),
	height(_height),
	spawn(_spawn)
{
	_load(pathname);
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
	std::ifstream	file(filename.c_str());
	std::string		line;
	unsigned		i;
	unsigned		j;

	_height = 0;

	while (std::getline(file, line))
		_height++;

	file.clear();
	file.seekg(0);

	_width = UINT_MAX;

	map = new unsigned*[_height];

	i = 0;
	while (std::getline(file, line))
	{
		if (_width == UINT_MAX)
			_width = line.size();
		else
		{
			if (_width == 0 || _width != line.size())
				throw; // TODO: bad line width
		}

		map[i] = new unsigned[_width];

		j = 0;
		while (j < line.size())
		{
			if (line[j] == ' ')
				map[i][j] = 0;
			else
				map[i][j] = line[j] - '0';

			if (map[i][j] == BLOCK_SPAWN)
			{
				_spawn.first = i;
				_spawn.second = j;
			}
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
