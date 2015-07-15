/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGraphics.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 17:42:08 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/15 21:46:06 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP

# include <queue>
# include "Snake.hpp"

class IGraphics
{
public:
	std::queue<t_action>	actions;
};

#endif
