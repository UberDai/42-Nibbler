/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 00:24:33 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/29 12:09:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Graphics.hpp"
#include "Snake.hpp"

extern "C" {
	#include <curses.h>
}

Graphics::Graphics(const Snake & s) : _snake(s)
{
	initscr();
	cbreak()
	keypad(stdscr, TRUE);
	noecho();
}

Graphics::~Graphics()
{
	endwin();
}

void	Graphics::update(void)
{
	clear();
	unsigned	x;
	unsigned	y;

	if (_snake.clockCountdown > 0)
		return ;

	printw("\n"); // << std::endl;
	printw("---------------\n"); // << "---------------" << std::endl;
	printw("Size: %d\n", _snake.player.size); // << "Size: " << _snake.player.size << std::endl;
	printw("Pending nom: \n", _snake.player.pendingNom); // << "Pending nom: " << _snake.player.pendingNom << std::endl;
	printw("\n"); // << std::endl;

	y = 0;
	while (y < _snake.level->height)
	{
		printw("   "); // << "   ";
		x = 0;
		while (x < _snake.level->width)
		{
			switch (_snake.level->map[y][x])
			{
				case BLOCK_NONE:
					printw(" "); // << ' ';
					break;
				case BLOCK_WALL:
					printw("/"); // << "\u25AF";
					break;
				case BLOCK_NOM:
					printw("x"); // << "x";
					break;
				case BLOCK_HEAD:
					printw("O"); // << 'O';
					break;
				default:
					printw("o"); // << 'o';
			}
			printw(" "); // << ' ';
			x++;
		}

		printw("\n"); // << std::endl;
		y++;
	}

	printw("---------------\n"); // << "---------------" << std::endl;
	printw("\n"); // << std::endl;
	int ch = getch();
	printw("%d\n", ch);
	refresh();
}

IGraphics *	glib_instantiate(const Snake & s)
{
	return new Graphics(s);
}

void		glib_uninstantiate(IGraphics * g)
{
	delete g;
}
