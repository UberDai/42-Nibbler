/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 17:56:26 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/15 22:13:36 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <string>
# include "Level.hpp"

typedef enum		e_action

	TURN_LEFT,
	TURN_RIGHT,
	PAUSE,
	QUIT
}					t_action;

typedef enum		e_block
{
	WALL = 1,
	SPAWN,
	HEAD = 10
}					t_block;

class Snake
{
protected:
	Level *			_level;

public:
	Snake(void);
	
	void			loadLevel(const std::string);
};

#endif
