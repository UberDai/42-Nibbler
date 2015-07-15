/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 16:14:48 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/15 19:28:51 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test.hpp"
#include <dlfcn.h>
#include <iostream>

void	lol1(void)
{
	std::cout << "LOL 1" << std::endl;
}

void	lol2(void)
{
	std::cout << "LOL 2" << std::endl;
}

void	die(const char *message)
{
	std::cout << message << std::endl;
	exit(0);
}

int		main(void)
{
	t_lel		lel;
	void		*dl_handle;
	void		(*lib)(t_lel*);

	lel.lol1 = lol1;
	lel.lol2 = lol2;

	dl_handle = dlopen("libcpp.so", RTLD_LAZY | RTLD_LOCAL);

	if (dl_handle == NULL)
		die("Handle");

	dlerror();

	const char *dlsym_error = dlerror();
	lib = (void(*)(t_lel*))dlsym(dl_handle, "lib");

	if (dlsym_error)
		die(dlsym_error);

	lib(&lel);

	return (0);
}
