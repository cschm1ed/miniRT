/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_to_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:03:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/22 09:03:27 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	angles_to_vector(double ayx, double az)
{
	t_vector	out;

	out.x = sin(ayx * M_PI / 180);
	out.y = cos(ayx * M_PI / 180);
	out.z = sin(az * M_PI / 180);
	return (out);
}

t_vector	_rotate(t_vector vec, double xy_degree, double xz_degree)
{
	t_vector	result;
	double		xy_rad;
	double		xz_rad;
	double		tmp_x;

	xy_rad = xy_degree * DEG_TO_RAD;
	xz_rad = xz_degree * DEG_TO_RAD;
	result.x = vec.x * cos(xz_rad) - vec.z * sin(xz_rad);
	result.z = vec.x * sin(xz_rad) + vec.z * cos(xz_rad);
	result.y = vec.y;
	tmp_x = result.x;
	result.x = tmp_x * cos(xy_rad) - result.y * sin(xy_rad);
	result.y = tmp_x * sin(xy_rad) + result.y * cos(xy_rad);
	return (result);
}
