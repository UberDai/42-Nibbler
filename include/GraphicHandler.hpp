/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GraphicHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 23:20:30 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/21 23:46:54 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICHANDLER_HPP
# define GRAPHICHANDLER_HPP

# include <string>
# include <exception>
# include "Snake.hpp"

class GraphicHandler
{
public:
	class LibraryNotFoundException : std::exception
	{
	public:
		virtual const char *	what() const throw();
	};

	class BadLibraryException : std::exception
	{
	public:
		virtual const char *	what() const throw();
	};

	static t_action *	action_sym;

	static void			loadLibrary(std::string);
};

#endif
