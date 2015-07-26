/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 16:14:48 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/26 20:44:58 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Snake.hpp"
#include "GraphicsHandler.hpp"
#include "Util.hpp"

#define OPTION_WIDTH	0
#define OPTION_HEIGHT	1
#define OPTION_LEVEL	2
#define OPTION_LIB		3

static void	processOptions(unsigned ac, const char * const * av, char ** options)
{
	for (unsigned i = 1; i < ac - 1; i++)
	{
		if (strcmp(av[i], "-level") == 0 && av[i + 1][0] != '-')
			options[OPTION_LEVEL] = strdup(av[++i]);
		else if (strcmp(av[i], "-lib") == 0 && av[i + 1][0] != '-')
			options[OPTION_LIB] = strdup(av[++i]);
		else if (strcmp(av[i], "-w") == 0 && av[i + 1][0] != '-')
			options[OPTION_WIDTH] = strdup(av[++i]);
		else if (strcmp(av[i], "-h") == 0 && av[i + 1][0] != '-')
			options[OPTION_HEIGHT] = strdup(av[++i]);
		else
		{
			std::cout << "Invalid option name or value: " << av[i] << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}

static void	checkOptions(const char * const * options)
{
	if (options[OPTION_LIB] == NULL)
		Util::die("-lib needs to be specified.");
	else if (options[OPTION_LEVEL] == NULL &&
		(options[OPTION_WIDTH] == NULL || options[OPTION_HEIGHT] == NULL))
		Util::die("-level or -w and -h need to be specified.");
}

int		main(int ac, char ** av)
{
	char *			options[4] = { NULL };
	Snake			snake;

	processOptions(ac, av, options);
	checkOptions(options);

	snake.loadLibrary(options[OPTION_LIB]);

	if (options[OPTION_LEVEL] != NULL)
		snake.loadLevel(options[OPTION_LEVEL]);
	else
		snake.loadLevel(atoi(options[OPTION_WIDTH]), atoi(options[OPTION_HEIGHT]));

	snake.launch();

	return (EXIT_SUCCESS);
}
