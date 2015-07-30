/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsHandler.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:23:17 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/30 05:10:33 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include <iostream>
#include "GraphicsHandler.hpp"

IGraphics *		GraphicsHandler::instance = NULL;

GraphicsHandler::GraphicsHandler(const Snake & s) :
	_snake(s)
{}

GraphicsHandler::~GraphicsHandler()
{
	_uninstantiate(instance);
	dlclose(_handler);
}

void			GraphicsHandler::loadLibrary(std::string name)
{
	t_sym_instantiate	instantiate;

	_handler = dlopen(name.c_str(), RTLD_NOW);

	if (_handler == NULL)
	{
		std::cout << dlerror() << std::endl;
		throw LibraryNotFoundException();
	}

	instantiate = reinterpret_cast<t_sym_instantiate>(loadSymbol("glib_instantiate"));
	_uninstantiate = reinterpret_cast<t_sym_uninstantiate>(loadSymbol("glib_uninstantiate"));
	instance = instantiate(_snake);
}

void *		GraphicsHandler::loadSymbol(const std::string name)
{
	const char *	dlsym_error;
	void *			symbol;

	dlerror();
	symbol = dlsym(_handler, name.c_str());
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
