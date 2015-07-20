/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 17:56:26 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/19 00:50:44 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <string>
# include "Level.hpp"
# include "Player.hpp"

# define DEFAULT_SPEED	1000000
# define SPEED_INC		1000
# define MAX_SPEED		1000

typedef enum		e_action
{
	TURN_LEFT,
	TURN_RIGHT,
	PAUSE,
	QUIT
}					t_action;

class Snake
{
public:
	static Snake *	instance;
	Level *			level;
	Player			player;
	int				speed;
	bool			paused;

	Snake();
	~Snake();

	void			loadLevel(const std::string);
	void			startLevel();
	void			gameOver() const;
	void			launch();
	void			update();
	void			dump(bool = false) const;
};

#endif
