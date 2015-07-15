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

typedef enum	e_action
{
	TURN_LEFT,
	TURN_RIGHT,
	PAUSE,
	QUIT
}				t_action;

class Snake
{
protected:
	double			_clock;
	unsigned		_width;
	unsigned		_height;

public:
	const unsigned	&width;
	const unsigned	&height;

	Snake(unsigned w, unsigned h);

	void			setWidth(unsigned width);
	void			setHeight(unsigned height);
};

#endif
