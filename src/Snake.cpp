/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 21:55:03 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/21 23:15:02 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"
#include <iostream>
#include <unistd.h>

Snake *	Snake::instance = NULL;

Snake::Snake(void) :
	level(NULL),
	speed(DEFAULT_SPEED),
	paused(true)
{
	instance = this;
	srand(time(NULL));
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

void	Snake::generateNom()
{
	unsigned	random;
	unsigned	i;
	t_block		block;

	random = rand() % (level->height * level->width);
	i = 0;

	while (1)
	{
		block = { 0, 0 };
		while (block.second < level->height)
		{
			block.first = 0;
			while (block.first < level->width)
			{
				if (level->getBlock(block) == BLOCK_NONE)
				{
					if (i == random)
					{
						level->setBlock(block, BLOCK_NOM);
						return ;
					}
					i++;
				}
				block.first++;
			}
			block.second++;
		}
	}
}

void	Snake::launch()
{
	update();
}

void	Snake::update()
{
	dump(true);
	usleep(speed);

	if (player.move() == false)
	{
		gameOver();
		return ;
	}

	speed = std::max<int>(speed - SPEED_INC, MAX_SPEED);
	update();
}

void	Snake::gameOver() const
{
	std::cout << "LOST!" << std::endl;
}

void	Snake::dump(bool humanize) const
{
	unsigned	x;
	unsigned	y;

	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "Size: " << player.size << std::endl;
	std::cout << "Pending nom: " << player.pendingNom << std::endl;
	std::cout << std::endl;

	if (humanize)
	{
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
					case BLOCK_NOM:
						std::cout << "x";
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
	}
	else
	{
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
	}

	std::cout << "---------------" << std::endl;
	std::cout << std::endl;
}
