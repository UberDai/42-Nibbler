/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsHandler.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:23:17 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/24 01:12:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <iostream>
#include "GraphicsHandler.hpp"

IGraphics *		GraphicsHandler::instance = NULL;

void			GraphicsHandler::loadLibrary(std::string name)
{
	void *				handler;
	t_sym_instantiate	instantiate;

	handler = dlopen(name.c_str(), RTLD_NOW);

	if (handler == NULL)
	{
		std::cout << dlerror() << std::endl;
		throw LibraryNotFoundException();
	}

	instantiate = reinterpret_cast<t_sym_instantiate>(loadSymbol(handler, "glib_instantiate"));

	instance = instantiate();
}

void *		GraphicsHandler::loadSymbol(void * handler, std::string name)
{
	const char *	dlsym_error;
	void *			symbol;

	dlerror();
	symbol = dlsym(handler, name.c_str());
	dlsym_error = dlerror();

	if (dlsym_error)
		throw BadLibraryException();

	return symbol;
}

const char *	GraphicsHandler::LibraryNotFoundException::what() const throw()
{
	return "Library not found.";
}

const char *	GraphicsHandler::BadLibraryException::what() const throw()
{
	return "Bad graphic library.";
}
