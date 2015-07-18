/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:49:11 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/19 00:39:37 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <vector>
# include "Level.hpp"

# define PLAYER_DEFAULT_SIZE	3

typedef enum	e_orient
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}				t_orient;

class Player
{
protected:
	t_block				_findNextBlock(const t_block) const;
	void				_moveBlock(t_block &, t_orient) const;

public:
	t_block				head;
	t_orient			orientation;
	unsigned			size;
	unsigned			pendingFood;

	Player();

	void		spawn();
	bool		move();
	void		eat();
};

#endif
