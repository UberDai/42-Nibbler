
#ifndef LEVEL_HPP
# define LEVEL_HPP

# include <string>

typedef std::pair<unsigned, unsigned>	t_spawn;

class Level
{
protected:
	unsigned			_width;
	unsigned			_height;
	t_spawn				_spawn;

	void				_load(const std::string);

public:
	const unsigned &	width;
	const unsigned &	height;
	const t_spawn &		spawn;
	t_block **			map;

	Level(const std::string);
	~Level(void);

	void			setWidth(unsigned);
	void			setHeight(unsigned);
};

#endif