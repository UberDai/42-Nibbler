/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 16:14:48 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/22 00:39:08 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"
#include "GraphicHandler.hpp"
#include <iostream>

int		main()
{
	Snake			snake;
	GraphicHandler	ghandler;

	try
	{
		ghandler.loadLibrary("lib1/lib1.so");
	}
	catch (GraphicHandler::LibraryNotFoundException & e)
	{
		std::cout << "Library error: " << e.what() << std::endl;
	}
	catch (GraphicHandler::BadLibraryException & e)
	{
		std::cout << "Library error: " << e.what() << std::endl;
	}

	// try
	// {
	// 	snake.loadLevel("levels/level00");
	// }
	// catch (Level::BadMapException & e)
	// {
	// 	std::cout << "Error while loading the map: " << e.what() << std::endl;
	// 	return (EXIT_FAILURE);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << "An unexpected error has occured." << std::endl;
	// 	return (EXIT_FAILURE);
	// }

	// snake.launch();

	return (EXIT_SUCCESS);
}
