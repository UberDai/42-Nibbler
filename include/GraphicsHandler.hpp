/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsHandler.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:20:30 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/30 05:09:57 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICSHANDLER_HPP
# define GRAPHICSHANDLER_HPP

# include <string>
# include <exception>
# include "Snake.hpp"
# include "IGraphics.hpp"

typedef IGraphics *	(*t_sym_instantiate)(const Snake &);
typedef void		(*t_sym_uninstantiate)(IGraphics *);

class GraphicsHandler
{
protected:
	const Snake &		_snake;
	void *				_handler;
	t_sym_uninstantiate	_uninstantiate;

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
