/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 00:24:33 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/25 02:05:06 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Graphics.hpp"
#include "Snake.hpp"

Graphics::Graphics(const Snake & s) : _snake(s)
{}

Graphics::~Graphics()
{}

void	Graphics::update(void)
{
	unsigned	x;
	unsigned	y;

	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "Size: " << _snake.player.size << std::endl;
	std::cout << "Pending nom: " << _snake.player.pendingNom << std::endl;
	std::cout << std::endl;

	y = 0;
	while (y < _snake.level->height)
	{
		std::cout << "   ";
		x = 0;
		while (x < _snake.level->width)
		{
			switch (_snake.level->map[y][x])
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

IGraphics *	glib_instantiate(const Snake & s)
{
	return new Graphics(s);
}
