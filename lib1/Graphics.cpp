/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 00:24:33 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/23 00:29:00 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Graphics.hpp"
#include "Snake.hpp"

void	Graphics::update(const Snake & snake)
{
	unsigned	x;
	unsigned	y;

	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "Size: " << snake.player.size << std::endl;
	std::cout << "Pending nom: " << snake.player.pendingNom << std::endl;
	std::cout << std::endl;

	y = 0;
	while (y < snake.level->height)
	{
		std::cout << "   ";
		x = 0;
		while (x < snake.level->width)
		{
			switch (snake.level->map[y][x])
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

	std::cout << "---------------" << std::endl;
	std::cout << std::endl;
}

IGraphics *	glib_instantiate()
{
	return new Graphics;
}
