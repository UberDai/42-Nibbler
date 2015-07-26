/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsHandler.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:20:30 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/26 20:55:37 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICSHANDLER_HPP
# define GRAPHICSHANDLER_HPP

# include <string>
# include <exception>
# include "Snake.hpp"
# include "IGraphics.hpp"

typedef IGraphics *	(*t_sym_instantiate)(const Snake &);

class GraphicsHandler
{
protected:
	const Snake &		_snake;
	void *				_handler;

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

	GraphicsHandler(const Snake &);
	~GraphicsHandler();

	static IGraphics *	instance;

	void				loadLibrary(std::string);
	void *				loadSymbol(const std::string);
};

#endif
