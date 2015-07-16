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
	if (_level != NULL)
		delete _level;

	level = new Level(pathname);
}