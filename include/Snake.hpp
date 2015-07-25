/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 17:56:26 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/25 23:27:44 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <string>
# include "Level.hpp"
# include "Player.hpp"

# define DEFAULT_SPEED	1.0f
# define SPEED_INC		0.01f
# define MAX_SPEED		0.2f

typedef enum		e_action
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	PAUSE,
	QUIT
}					t_action;

class Snake
{
protected:

public:
	static Snake *	instance;
	Level *			level;
	Player			player;
	float			speed;
	bool			paused;
	float			clockCountdown;

	Snake();
	~Snake();

	void			loadLevel(const std::string);
	void			startLevel();
	void			gameOver() const;
	void			generateNom();
	void			launch();
	bool			update();
	void			dump(bool = false) const;
};

#endif
