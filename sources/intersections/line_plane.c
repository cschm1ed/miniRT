/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:23:31 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/26 23:39:24 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static inline t_vector	get_normal(t_plane *pl, t_vector line);

inline int	intersection_line_plane(void *object, \
					t_line line, t_intersect *inter)
{
	t_vector	n;
	double		t;
	t_plane		*plane;

	plane = (t_plane *)object;
	n = plane->v1;
	line.dir = _divide(line.dir, _len(line.dir));
	if (fabs(_dot(n, line.dir)) < EPSILON)
		return (FALSE);
	t = (_dot(_subtract(plane->base, line.base), n)
			/ _dot(line.dir, n));
	if (t < 0)
		return (FALSE);
	inter->point = _multiply(line.dir, t);
	inter->point = _add(inter->point, line.base);
	inter->normal = get_normal(plane, inter->ray.dir);
	return (TRUE);
}

inline static t_vector	get_normal(t_plane *pl, t_vector line)
{
	if (_dot(pl->v1, line) > 0)
		return (_multiply(pl->v1, -1));
	return (pl->v1);
}
