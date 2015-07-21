/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:23:17 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/21 23:46:58 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlfcn.h>
#include "GraphicHandler.hpp"

void			GraphicHandler::loadLibrary(std::string name)
{
	void *			handler;
	const char *	dlsym_error;

	handler = dlopen(name.c_str(), RTLD_NOW);

	if (handler == NULL)
		throw LibraryNotFoundException();

	dlerror();
	action_sym = static_cast<t_action *>(dlsym(handler, "action"));
	dlsym_error = dlerror();

	if (dlsym_error)
		throw BadLibraryException();
}

const char *	GraphicHandler::LibraryNotFoundException::what() const throw()
{
	return "Library not found.";
}

const char *	GraphicHandler::BadLibraryException::what() const throw()
{
	return "Bad graphic library.";
}