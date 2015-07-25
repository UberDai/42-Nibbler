/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 17:42:08 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/25 22:46:46 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP

# include <queue>
# include "Snake.hpp"

class IGraphics
{
public:
	t_action		glib_action;

	virtual			~IGraphics(void) = default;
	virtual void	update(void) = 0;
};

#endif

