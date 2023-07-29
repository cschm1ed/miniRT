/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_cylinder2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:15:45 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/16 18:15:45 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

inline void	get_proj_len(t_cylindner *cy, t_intersect *inter, \
				t_proj_len p, t_vector dist)
{
	t_vector	p1;
	t_vector	p2;
	t_vector	normal;

	normal = _divide(cy->axis_dir, _len(cy->axis_dir));
	inter->ray.dir = _divide(inter->ray.dir, \
			_len(inter->ray.dir));
	p1 = _add(inter->ray.base, _multiply(inter->ray.dir, dist.x));
	p2 = _add(inter->ray.base, _multiply(inter->ray.dir, dist.y));
	*p.pl1 = _dot(_subtract(p1, cy->center), normal);
	*p.pl2 = _dot(_subtract(p2, cy->center), normal);
}

int	get_distance(t_cylindner *cy, t_intersect *inter, double *d1, double *d2)
{
	double	discr;
	double	r;
	t_c		c;

	r = cy->diameter / 2;
	c.normal = _divide(cy->axis_dir, _len(cy->axis_dir));
	c.w = _subtract(inter->ray.base, cy->center);
	c.v = _divide(inter->ray.dir, _len(inter->ray.dir));
	c.dot1 = _dot(c.w, c.normal);
	c.dot2 = _dot(c.v, c.normal);
	c.a = _dot(c.v, c.v) - (c.dot2 * c.dot2);
	c.b = 2 * (_dot(c.v, c.w) - (c.dot2 * c.dot1));
	c.c = _dot(c.w, c.w) - (c.dot1 * c.dot1) - (r * r);
	discr = (c.b * c.b) - (4 * c.a * c.c);
	if (discr < 0)
		return (FALSE);
	discr = sqrt(discr);
	*d1 = (-c.b + discr) / (2 * c.a);
	*d2 = (-c.b - discr) / (2 * c.a);
	if (isnan(*d1) || isnan(*d2))
		return (FALSE);
	return (TRUE);
}

t_vector	get_cap_inters(t_cylindner *cy, t_intersect *inter, int is_top)
{
	t_plane		cap;
	t_intersect	inters;
	t_vector	normal;

	normal = _divide(cy->axis_dir, _len(cy->axis_dir));
	if (is_top)
	{
		cap.base = _add(cy->center, _multiply(normal, cy->height * 0.5));
		cap.v1 = normal;
	}
	else
	{
		cap.base = _add(cy->center, _multiply(normal, cy->height * -0.5));
		cap.v1 = _multiply(normal, -1);
	}
	inters.ray = inter->ray;
	if (intersection_line_plane(&cap, inters.ray, &inters) == FALSE)
		return ((t_vector){.x = INFINITY, .y = INFINITY, .z = INFINITY});
	inters.normal = cap.v1;
	if (_len(_subtract(inters.point, cap.base)) < cy->diameter / 2)
		return (inters.point);
	return ((t_vector){.x = INFINITY, .y = INFINITY, .z = INFINITY});
}
