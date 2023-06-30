/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_x_intensitiy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:58:35 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/27 11:58:35 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int multiply_intensity(float max, float col, float intensity);

int colour_x_intensity(int colour, t_vector intensity)
{
	float 		max;
	t_vector	rgb;

	rgb = colour_to_vector(colour);
	max = fmax(fmax(rgb.x, rgb.y), rgb.z);
	rgb.z = multiply_intensity(max, rgb.z, intensity.z);
	rgb.y = multiply_intensity(max, rgb.y, intensity.y);
	rgb.x = multiply_intensity(max, rgb.x, intensity.x);
	return (trgb(0, rgb.x, rgb.y, rgb.z));
}

static int multiply_intensity(float max, float col, float intensity)
{
	col = (int)((col / max) * intensity);
	if (col > 255 || col < 0)
		col = 255;
	return (col);
}
