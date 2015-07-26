/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 00:20:46 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/26 20:19:29 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/time.h>
#include "Util.hpp"

double	Util::getTime()
{
	static time_t	beginning;
	struct timeval	tod;
	double			ret;

	gettimeofday(&tod, NULL);
	if (beginning == 0)
		beginning = tod.tv_sec;
	ret = static_cast<double>(tod.tv_sec - beginning);
	ret += static_cast<double>(tod.tv_usec) / 1000000;
	return (ret);
}

int		Util::die(std::string message)
{
	std::cout << message << std::endl;
	exit(EXIT_FAILURE);
}
