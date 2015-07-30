/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 00:24:33 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/30 05:06:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Graphics.hpp"
#include "Snake.hpp"

extern "C" {
	#include <curses.h>
	#include <unistd.h>
}

Graphics::Graphics(const Snake & s) : _snake(s)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	timeout(1);
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

	// if (_snake.clockCountdown > 0) {
	// 	return ;
	// }

		int ch;

		while ((ch = getch()) != -1)
		{
			if (ch == 112)
				glib_action = PAUSE;
			if (ch == 258)
				glib_action = DOWN;
			if (ch == 259)
				glib_action = UP;
			if (ch == 260)
				glib_action = RIGHT;
			if (ch == 261)
				glib_action = LEFT;
			if (ch == 50)
				glib_action = LIB2;
			if (ch == 51)
				glib_action = LIB3;
			printw("%d\n", ch);
		}


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
	refresh();
	usleep(50000);
}

IGraphics *	glib_instantiate(const Snake & s)
{
	return new Graphics(s);
}

void		glib_uninstantiate(IGraphics * g)
{
	delete g;
}
