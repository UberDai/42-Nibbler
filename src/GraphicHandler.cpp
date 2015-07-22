/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:23:17 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/22 02:01:38 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include "GraphicHandler.hpp"

IGraphics *		GraphicHandler::instance = NULL;

void			GraphicHandler::loadLibrary(std::string name)
{
	void *				handler;
	t_sym_instantiate	instantiate;

	handler = dlopen(name.c_str(), RTLD_NOW);

	if (handler == NULL)
		throw LibraryNotFoundException();

	instantiate = reinterpret_cast<t_sym_instantiate>(loadSymbol(handler, "glib_instantiate"));

	instance = instantiate();
}

void *		GraphicHandler::loadSymbol(void * handler, std::string name)
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

const char *	GraphicHandler::LibraryNotFoundException::what() const throw()
{
	return "Library not found.";
}

const char *	GraphicHandler::BadLibraryException::what() const throw()
{
	return "Bad graphic library.";
}
