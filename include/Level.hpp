/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Level.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:05:12 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/18 19:23:03 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_HPP
# define LEVEL_HPP

# include <string>

# define BLOCK_WALL		1
# define BLOCK_SPAWN	2
# define BLOCK_HEAD		10

typedef std::pair<unsigned, unsigned>	t_block;

class Level
{
protected:
	unsigned			_width;
	unsigned			_height;
	t_block				_spawn;

	void				_load(const std::string);

public:
	const unsigned &	width;
	const unsigned &	height;
	const t_block &		spawn;
	unsigned **			map;

	Level(const std::string);
	~Level(void);

	void			setWidth(unsigned);
	void			setHeight(unsigned);
};

#endif
