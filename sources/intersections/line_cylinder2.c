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

double		cylinder_side_intersect(t_cylindner *cy, t_intersect *inter);
void		get_proj_len(t_cylindner *cy, t_intersect *inter, double d1, double d2, double *pl1, double *pl2);
int			get_distance(t_cylindner *cy, t_intersect *inter, double *d1, double *d2);
t_vector	get_cap_inters(t_cylindner *cy, t_intersect *inter, int is_top);

t_vector normal_tube_cylinder(t_vector point, t_cylindner cylindner)
{
	t_plane		pl;
	t_line		ln;
	t_vector	q;
	double		t;

	pl.base = point;
	pl.v1 = cylindner.axis_direction;
	ln.base = cylindner.center;
	ln.direction  = cylindner.axis_direction;
	t = (_dot(_subtract(pl.base, ln.base), pl.v1)
		 / _dot(ln.direction, pl.v1));
	q = _add(cylindner.center, _multiply(ln.direction, t));
	return (_divide(_subtract(point, q), _len(_subtract(point, q))));
}

double cylinder_side_intersect(t_cylindner *cy, t_intersect *inter)
{
	t_vector dist;
	double pl1;
	double pl2;
	double t;

	if (get_distance(cy, inter, &d1, &d2) == FALSE)
		return (FALSE);
	get_proj_len(cy, inter, d1, d2, &pl1, &pl2);
	if (pl1 < -cy->height / 2 || pl1 > cy->height / 2)
		d1 = INFINITY;
	if (pl2 < -cy->height / 2 || pl2 > cy->height / 2)
		d2 = INFINITY;
	t = d2;
	if (d1 < d2)
		t = d1;
	if (t < 0)
	{
		if (d1 > d2)
			t = d1;
		else
			t = d2;
	}
	return (t);
}

inline void	get_proj_len(t_cylindner *cy, t_intersect *inter, double d1, double d2, double *pl1, double *pl2)
{
	t_vector p1;
	t_vector p2;
	t_vector normal;

	normal = _divide(cy->axis_direction, _len(cy->axis_direction));
	inter->ray.direction = _divide(inter->ray.direction, _len(inter->ray.direction));
	p1 = _add(inter->ray.base, _multiply(inter->ray.direction, d1));
	p2 = _add(inter->ray.base, _multiply(inter->ray.direction, d2));
	*pl1 = _dot(_subtract(p1, cy->center), normal);
	*pl2 = _dot(_subtract(p2, cy->center), normal);
}

int get_distance(t_cylindner *cy, t_intersect *inter, double *d1, double *d2)
{
	double 	 discr;
	double	 r;
	t_c 	 c;
	
	r = cy->diameter / 2;
	c.normal = _divide(cy->axis_direction, _len(cy->axis_direction));
	c.w = _subtract(inter->ray.base, cy->center);
	c.v = _divide(inter->ray.direction, _len(inter->ray.direction));
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

int line_cylindner(void *object, t_line line, t_intersect *inter)
{
	(void)line;
	t_vector cap_inters;
	t_cylindner *cy;
	double		t;

	cy = ((t_cylindner*)object);
	t = cylinder_side_intersect(cy, inter);
	if (t == FALSE || t == INFINITY)
		return (FALSE);
	if (_len(_subtract(_add(cy->center, cy->axis_direction), inter->ray.base)) <
		_len(_subtract(_add(cy->center, _multiply(cy->axis_direction, -1)), inter->ray.base)))
		cap_inters = get_cap_inters(cy, inter, 1);
	else
		cap_inters = get_cap_inters(cy, inter, 0);
	if ((cap_inters.x != INFINITY || cap_inters.y != INFINITY || cap_inters.z != INFINITY) && _len(_subtract(cap_inters, inter->ray.base)) < t)
	{
		inter->point = cap_inters;
		inter->normal = _multiply(_divide(cy->axis_direction, _len(cy->axis_direction)), -1);
		return (TRUE);
	}
	if (t < 0)
		return (FALSE);
	inter->ray.direction = _divide(inter->ray.direction, _len(inter->ray.direction));
	inter->point = _add(inter->ray.base, _multiply(inter->ray.direction, t));
	inter->normal = normal_tube_cylinder(inter->point, *cy);
	return (TRUE);
}

t_vector get_cap_inters(t_cylindner *cy, t_intersect *inter, int is_top)
{
	t_plane cap;
	t_intersect inters;
	t_vector normal;

	normal = _divide(cy->axis_direction, _len(cy->axis_direction));
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
