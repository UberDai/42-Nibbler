/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 16:14:48 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/26 00:27:04 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"
#include "GraphicsHandler.hpp"
#include <iostream>

int		main()
{
	Snake			snake;
	GraphicsHandler	ghandler(snake);

	try
	{
		ghandler.loadLibrary("lib2/lib2.so");
	}
	catch (GraphicsHandler::LibraryNotFoundException & e)
	{
		std::cout << "Library error: " << e.what() << std::endl;
	}
	catch (GraphicsHandler::BadLibraryException & e)
	{
		std::cout << "Library error: " << e.what() << std::endl;
	}

	try
	{
		snake.loadLevel("levels/level00");
	}
	catch (Level::BadMapException & e)
	{
		std::cout << "Error while loading the map: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	catch (std::exception & e)
	{
		std::cout << "An unexpected error has occured." << std::endl;
		return (EXIT_FAILURE);
	}

	snake.launch();

	return (EXIT_SUCCESS);
}
