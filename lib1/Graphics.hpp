/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graphics.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 00:21:02 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/22 00:58:20 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

# include "IGraphics.hpp"
# include "Level.hpp"

class Graphics : public IGraphics
{
public:
	void	update(const Snake &);
};

IGraphics *	glib_instantiate();

#endif
