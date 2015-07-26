
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
	unsigned		y;
	unsigned		x;

	_height = 0;

	while (std::getline(file, line))
		_height++;

	file.clear();
	file.seekg(0);

	_width = UINT_MAX;

	map = new unsigned*[_height];

	y = 0;
	while (std::getline(file, line))
	{
		if (_width == UINT_MAX)
			_width = line.size();
		else
		{
			if (_width == 0 || _width != line.size())
				throw Level::BadMapException();
		}

		map[y] = new unsigned[_width];

		x = 0;
		while (x < line.size())
		{
			map[y][x] = line[x] - '0';

			if (map[y][x] == BLOCK_SPAWN)
			{
				_spawn.first = x;
				_spawn.second = y;
				map[y][x] = BLOCK_NONE;
			}
			x++;
		}

		y++;
	}
}

unsigned	Level::getBlock(t_block block) const
{
	if (block.first >= width || block.second >= height)
		return (BLOCK_OUT);

	return map[block.second][block.first];
}

void		Level::setBlock(const t_block block, unsigned value)
{
	if (getBlock(block) == BLOCK_OUT)
		return ;

	map[block.second][block.first] = value;
}

void	Level::setWidth(unsigned width)
{
	_width = width;
}

void	Level::setHeight(unsigned height)
{
	_height = height;
}

const char *	Level::BadMapException::what() const throw()
{
	return "Bad input map.";
}
