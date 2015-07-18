/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:54:56 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/18 20:32:10 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Snake.hpp"
#include <iostream>

Player::Player()
{}

void	Player::spawn()
{
	unsigned	x;
	unsigned	y;
	t_block		block;
	Level *		level;

	orientation = WEST;
	size = 3;
	pendingFood = 0;

	level = Snake::instance->level;

	x = level->spawn.first;
	y = level->spawn.second;

	level->map[y][x] = BLOCK_HEAD;
	level->map[y][x + 1] = BLOCK_HEAD + 1;
	level->map[y][x + 2] = BLOCK_HEAD + 2;
}

void	Player::move()
{

}