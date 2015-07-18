/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 21:55:03 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/19 00:50:42 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"
#include <iostream>
#include <unistd.h>

Snake *	Snake::instance = NULL;

Snake::Snake(void) :
	level(NULL),
	speed(DEFAULT_SPEED)
{
	instance = this;
}

Snake::~Snake()
{
	if (level != NULL)
		delete level;
}

void	Snake::loadLevel(const std::string pathname)
{
	if (level != NULL)
		delete level;

	level = new Level(pathname);

	player.spawn();
}

void	Snake::launch()
{
	update();
}

void	Snake::update()
{
	dump2();
	usleep(speed);

	if (player.move() == false)
	{
		gameOver();
		return ;
	}

	speed = std::max<int>(speed - SPEED_INC, MAX_SPEED);
	std::cout << speed << std::endl;
	update();
}

void	Snake::gameOver() const
{
	std::cout << "LOST!" << std::endl;
}

void	Snake::dump() const
{
	unsigned	x;
	unsigned	y;

	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "Size: " << player.size << std::endl;
	std::cout << "Pending food: " << player.pendingFood << std::endl;
	std::cout << std::endl;

	y = 0;
	while (y < level->height)
	{
		x = 0;
		while (x < level->width)
		{
			std::cout << level->map[y][x] << ' ';
			x++;
		}

		std::cout << std::endl;
		y++;
	}

	std::cout << "---------------" << std::endl;
	std::cout << std::endl;
}

void	Snake::dump2() const
{
	unsigned	x;
	unsigned	y;

	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "   Size: " << player.size << std::endl;
	std::cout << "   Pending food: " << player.pendingFood << std::endl;
	std::cout << std::endl;

	y = 0;
	while (y < level->height)
	{
		std::cout << "   ";
		x = 0;
		while (x < level->width)
		{
			switch (level->map[y][x])
			{
				case BLOCK_NONE:
					std::cout << ' ';
					break;
				case BLOCK_WALL:
					std::cout << "\u25AF";
					break;
				case BLOCK_HEAD:
					std::cout << 'O';
					break;
				default:
					std::cout << 'o';
			}
			std::cout << ' ';
			x++;
		}

		std::cout << std::endl;
		y++;
	}

	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << std::endl;
}