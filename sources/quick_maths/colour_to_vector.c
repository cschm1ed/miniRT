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

inline t_vector	colour_to_vector(int colour)
{
	return ((t_vector){colour >> 16 & 0xFF, colour >> 8 & 0xFF, colour & 0xFF});
}

inline int	vector_to_colour(t_vector colour)
{
	return (get_colour(0, colour.x, colour.y, colour.z));
}
