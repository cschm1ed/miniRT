/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:23:31 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/23 11:23:31 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_vector	get_normal(t_plane *pl, t_vector line);

int	intersection_line_plane(void *object, t_line line, t_intersect *inter)
{
	t_vector	n;
	double		t;
	t_plane		*plane;

	plane = (t_plane *)object;
	n = plane->v1;
	line.direction = _divide(line.direction, _len(line.direction));
	if (fabs(_dot(n, line.direction)) < EPSILON)
		return (FALSE);
	t = (_dot(_subtract(plane->base, line.base), n)
			/ _dot(line.direction, n));
	if (t < 0)
		return (FALSE);
	inter->point = _multiply(line.direction, t);
	inter->point = _add(inter->point, line.base);
	inter->normal = get_normal(plane, inter->ray.base);
	return (TRUE);
}

static t_vector	get_normal(t_plane *pl, t_vector line)
{
	if (pl->v1.x < 0 && line.x < 0)
		pl->v1.x *= -1;
	if (pl->v1.y < 0 && line.x < 0)
		pl->v1.y *= -1;
	if (pl->v1.z < 0 && line.z < 0)
		pl->v1.z *= -1;
	return (pl->v1);
}
