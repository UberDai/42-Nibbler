/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 00:24:33 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/22 00:58:21 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Graphics.hpp"
#include "Snake.hpp"

void	Graphics::update(const Snake & snake)
{
	(void)snake;
	std::cout << "OK" << std::endl;
}

IGraphics *	glib_instantiate()
{
	return new Graphics;
}
