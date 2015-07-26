/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 17:56:26 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/26 21:01:30 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP

# include <string>
# include "Level.hpp"
# include "Player.hpp"

# define DEFAULT_SPEED	1.0f
# define SPEED_INC		30.0f
# define MAX_SPEED		0.10f
# define MULTINOM_RATE	10

class GraphicsHandler;

typedef enum		e_action
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	PAUSE,
	QUIT,
	LIB1,
	LIB2
}					t_action;

class Snake
{
public:
	static Snake *		instance;
	Level *				level;
	Player				player;
	float				speed;
	bool				paused;
	float				clockCountdown;
	bool				stop;
	GraphicsHandler *	ghandler;

	Snake();
	~Snake();

	void				loadLevel(unsigned, unsigned);
	void				loadLevel(const std::string);
	void				loadLibrary(const std::string);
	void				startLevel();
	void				gameOver();
	void				generateNom();
	void				generateNom(unsigned);
	void				removeNoms();
	void				launch();
	void				update();
	void				handleAction();
	void				dump(bool = false) const;
};

#endif
