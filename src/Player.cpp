/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 18:54:56 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/21 22:54:45 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Snake.hpp"
#include <iostream>
#include <climits>

Player::Player()
{}

t_block	Player::_findNextBlock(const t_block block) const
{
	t_block		coord;
	unsigned	wantedBlock;
	Level *		level;

	level = Snake::instance->level;
	wantedBlock = level->getBlock(block) + 1;
	coord = block;

	coord.first += 1;
	if (level->getBlock(coord) == wantedBlock)
		return (coord);

	coord.first -= 2;
	if (level->getBlock(coord) == wantedBlock)
		return (coord);

	coord.first = block.first;
	coord.second += 1;
	if (level->getBlock(coord) == wantedBlock)
		return (coord);

	coord.second -= 2;
	if (level->getBlock(coord) == wantedBlock)
		return (coord);

	coord.first = UINT_MAX;

	return (coord);
}

void	Player::_moveBlock(t_block & block, t_orient orient) const
{
	switch (orient)
	{
		case NORTH:
			block.second -= 1;
			break;
		case EAST:
			block.first += 1;
			break;
		case SOUTH:
			block.second += 1;
			break;
		case WEST:
			block.first -= 1;
	}
}

void	Player::spawn()
{
	unsigned	x;
	unsigned	y;
	unsigned	i;
	Level *		level;

	orientation = WEST;
	size = PLAYER_DEFAULT_SIZE;
	pendingNom = 0;

	level = Snake::instance->level;

	x = level->spawn.first;
	y = level->spawn.second;

	level->map[y][x] = BLOCK_HEAD;
	head.first = x;
	head.second = y;

	i = 1;
	while (i < size)
	{
		level->map[y][x + i] = BLOCK_HEAD + i;
		i++;
	}

	Snake::instance->generateNom();
}

void	Player::eat()
{
	pendingNom++;
	size++;
	Snake::instance->generateNom();
	std::cout << "nom" << std::endl;
}

bool	Player::move()
{
	t_block		prevBlock;
	t_block		nextBlock;
	unsigned	i;
	Level *		level;

	level = Snake::instance->level;
	prevBlock = head;

	_moveBlock(head, orientation);

	switch (level->getBlock(head))
	{
		case BLOCK_NONE:
			break;
		case BLOCK_NOM:
			eat();
			break;
		default:
			return false;
	}

	level->setBlock(head, BLOCK_HEAD);

	nextBlock = _findNextBlock(prevBlock);

	i = BLOCK_HEAD;
	while (level->getBlock(nextBlock) > i)
	{
		level->setBlock(prevBlock, level->getBlock(nextBlock));
		prevBlock = nextBlock;
		nextBlock = _findNextBlock(prevBlock);
		i++;
	}

	if (pendingNom > 0)
	{
		pendingNom--;
		level->setBlock(prevBlock, i + 1);
	}
	else
		level->setBlock(prevBlock, BLOCK_NONE);

	return true;
}

void	Player::turnRight()
{
	orientation = static_cast<t_orient>((orientation + 1) % 4);
}

void	Player::turnLeft()
{
	orientation = static_cast<t_orient>((orientation - 1 + 4) % 4);
}
