/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 21:55:03 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/18 20:35:33 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"
#include <iostream>

Snake::Snake(void) :
	level(NULL)
{}

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
	dump();
}

void	Snake::update()
{

}

void	Snake::dump()
{
	unsigned	x;
	unsigned	y;

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

	std::cout << std::endl;
}
