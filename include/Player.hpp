/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:49:11 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/18 20:29:17 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <vector>
# include "Level.hpp"

typedef enum	e_orient
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}				t_orient;

class Player
{
public:
	t_orient			orientation;
	unsigned			size;
	unsigned			pendingFood;

	Player();

	void		spawn();
	void		move();
};

#endif
