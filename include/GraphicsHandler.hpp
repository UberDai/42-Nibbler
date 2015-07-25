/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicsHandler.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:20:30 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/25 22:44:03 by amaurer          ###   ########.fr       */
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
public:
	GraphicsHandler(const Snake &);

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

	void			loadLibrary(std::string);
	void *			loadSymbol(void *, std::string);
private:
	const Snake &		_snake;
};

#endif
