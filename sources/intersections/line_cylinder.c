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

static double	cylinder_side_intersect(t_cylindner *cy, t_intersect *inter);
static t_vector	normal_tube_cylinder(t_vector point, t_cylindner cylindner);
void			assign_inter_values(t_intersect *i, t_cylindner *c, double t);

int	line_cylindner(void *object, t_line line, t_intersect *inter)
{
	t_vector	c_inter;
	t_cylindner	*cy;
	double		t;

	(void)line;
	cy = ((t_cylindner *)object);
	t = cylinder_side_intersect(cy, inter);
	if (t == FALSE || t == INFINITY)
		return (FALSE);
	if (_len(_subtract(_add(cy->center, cy->axis_dir), inter->ray.base)) \
		< _len(_subtract(_add(cy->center, _multiply(cy->axis_dir, -1)), \
		inter->ray.base)))
		c_inter = get_cap_inters(cy, inter, 1);
	else
		c_inter = get_cap_inters(cy, inter, 0);
	if ((c_inter.x != INFINITY || c_inter.y != INFINITY || c_inter.z != \
		INFINITY) && _len(_subtract(c_inter, inter->ray.base)) < t)
		return (inter->point = c_inter, inter->normal
			= _multiply(_divide(cy->axis_dir, _len(cy->axis_dir)), -1), TRUE);
	if (t < 0)
		return (FALSE);
	assign_inter_values(inter, cy, t);
	return (TRUE);
}

void	assign_inter_values(t_intersect *inter, t_cylindner *cy, double t)
{
	inter->ray.dir = _divide(inter->ray.dir, _len(inter->ray.dir));
	inter->point = _add(inter->ray.base, _multiply(inter->ray.dir, t));
	inter->normal = normal_tube_cylinder(inter->point, *cy);
}

static t_vector	normal_tube_cylinder(t_vector point, t_cylindner cylindner)
{
	t_plane		pl;
	t_line		ln;
	t_vector	q;
	double		t;

	pl.base = point;
	pl.v1 = cylindner.axis_dir;
	ln.base = cylindner.center;
	ln.dir = cylindner.axis_dir;
	t = (_dot(_subtract(pl.base, ln.base), pl.v1) \
		/ _dot(ln.dir, pl.v1));
	q = _add(cylindner.center, _multiply(ln.dir, t));
	return (_divide(_subtract(point, q), _len(_subtract(point, q))));
}

static double	cylinder_side_intersect(t_cylindner *cy, t_intersect *inter)
{
	t_vector	dist;
	double		pl1;
	double		pl2;
	double		t;

	if (get_distance(cy, inter, &dist.x, &dist.y) == FALSE)
		return (FALSE);
	get_proj_len(cy, inter, (t_proj_len){&pl1, &pl2}, dist);
	if (pl1 < -cy->height / 2 || pl1 > cy->height / 2)
		dist.x = INFINITY;
	if (pl2 < -cy->height / 2 || pl2 > cy->height / 2)
		dist.y = INFINITY;
	t = dist.y;
	if (dist.x < dist.y)
		t = dist.x;
	if (t < 0)
	{
		if (dist.x > dist.y)
			t = dist.x;
		else
			t = dist.y;
	}
	return (t);
}
