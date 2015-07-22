/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:20:30 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/22 01:59:02 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICHANDLER_HPP
# define GRAPHICHANDLER_HPP

# include <string>
# include <exception>
# include "Snake.hpp"
# include "IGraphics.hpp"

typedef IGraphics *	(*t_sym_instantiate)();

class GraphicHandler
{
public:
	class LibraryNotFoundException : public std::exception
	{
	public:
		virtual const char *	what() const throw();
	};

	class BadLibraryException : public std::exception
	{
	public:
		virtual const char *	what() const throw();
	};

	static IGraphics *	instance;

	static void			loadLibrary(std::string);
	static void *		loadSymbol(void *, std::string);
};

#endif
