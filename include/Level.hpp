
#ifndef LEVEL_HPP
# define LEVEL_HPP

# include <string>

class Level
{
protected:
	unsigned			_width;
	unsigned			_height;

	void				_load(const std::string);

public:
	const unsigned &	width;
	const unsigned &	height;
	unsigned **			map;

	Level(const std::string);
	~Level(void);

	void			setWidth(unsigned);
	void			setHeight(unsigned);
};

#endif