/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:11:14 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/28 17:11:14 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector colour_to_vector(int colour)
{
	return ((t_vector){colour >> 16 & 0xFF, colour >> 8 & 0xFF, colour & 0xFF});
}

int 	vector_to_colour(t_vector colour)
{
	return (trgb(0, colour.x, colour.y, colour.z));
}

int 	colour_add(int c1, int c2)
{
	t_vector 	out;

	out = vector_add(colour_to_vector(c2), colour_to_vector(c1));
	out.x = fmin(out.x, 255);
	out.y = fmin(out.y, 255);
	out.z = fmin(out.z, 255);
	return (vector_to_colour(out));
}
