/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_line_sphere.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:51:42 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/20 16:54:13 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minirt.h"

int	intersection_line_sphere(t_sphere sphere, t_line line)
{
	float a;
	float b;
	float c;
	float result;

	a = pow(line.direction.x, 2) + pow(line.direction.y, 2) + pow(line.direction.z, 2);
	b = 2 * ((line.direction.x * line.base.x - sphere.center.x) +
			(line.direction.y * line.base.y - sphere.center.y) + (line.direction.z * (line.base.z - sphere.center.z)));
	c = pow(sphere.center.x, 2) + pow(sphere.center.y, 2) + pow(sphere.center.z, 2) +
			pow(line.base.x, 2) + pow(line.base.y, 2) + pow(line.base.z, 2)
			- 2 * (sphere.center.x * line.base.x + sphere.center.y * line.base.y + sphere.center.z * line.base .z) * pow(sphere.diameter, 2);
	result = b * b - 4 * a * c;
	if (result < 0)
		return (0);
	else if (result == 0)
		return (1);
	return (2);
}
