/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 21:55:03 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/15 21:58:16 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"

Snake::Snake(void) :
	_level(NULL)
{}

Snake::~Snake(void)
{
	if (_level != NULL)
		delete _level;
}

void	Snake::loadLevel(const std::string pathname)
{
	unsigned	x;
	unsigned	y;

	if (_level != NULL)
		delete _level;

	level = new Level(pathname);
	_playerSize = 0;
	_pendingFood = 0;

	x = level->spawn.first;
	y = level->spawn.second;

	level->map[y][x] = HEAD;
	level->map[y][x + 1] = (int)HEAD + 1;
	level->map[y][x + 2] = (int)HEAD + 2;
}

void	Snake::update(void)
{

	
}