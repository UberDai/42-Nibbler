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

Snake::Snake(unsigned w, unsigned h) :
	_width(w),
	_height(h),
	width(_width),
	height(_height)
{}

void	Snake::setWidth(unsigned width)
{
	_width = width;
}

void	Snake::setHeight(unsigned height)
{
	_height = height;
}