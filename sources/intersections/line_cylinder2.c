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

t_vector normal_tube_cylinder(t_vector point, t_cylindner cylindner)
{
	t_plane	pl;
	t_line 	ln;
	t_vector q;
	t_vector n;
	double 		t;

	pl.base = point;
	pl.v1 = cylindner.axis_direction;
	ln.base = cylindner.center;
	ln.direction  = cylindner.axis_direction;

	t = (_dot(_subtract(pl.base, ln.base), pl.v1)
		 / _dot(ln.direction, pl.v1));

	q = _add(cylindner.center, _multiply(ln.direction, t));
	n = _subtract(point, q);
	return (_divide(n, _len(n)));
}

//int line_cylindner(void *object, t_line line, t_intersect *inter)
//{
//
//	t_vector apex;
//	t_vector cap_center;
//	t_cylindner cylindner;
//	t_vector cap_normal;
//	t_vector point;
//	double t;
//
//	t_vector h_normal;
//	t_vector h;
//	t_vector w;
//	t_vector v;
//
//	double root_term;
//	double check;
//	double t1;
//	double t2;
//	double a;
//	double b;
//	double c;
//	double check2;
//
//	cylindner = *((t_cylindner*)object);
//	apex = _add(cylindner.center, _multiply(cylindner.axis_direction, cylindner.height));
//	check2 = 1;
//
//	if (_len(_subtract(apex, line.base)) < _len(_subtract(cylindner.center, line.base)))
//	{
//		cap_center = apex;
//		cap_normal = cylindner.axis_direction;
//	}
//	else
//	{
//		cap_center = cylindner.center;
//		cap_normal = _multiply(cylindner.axis_direction, -1);
//	}
//	t = _dot(_subtract(cap_center, line.base), cap_normal) / _dot(line.direction, cap_normal);
//	if (t != 0)
//	{
//		point = _add(line.base, _multiply(line.direction, t));
//		if (_len(_subtract(point, cap_center)) <= cylindner.diameter / 2)
//		{
//			check2 = 0;
//			inter->point = point;
//			inter->normal = cap_normal;
//			return (TRUE);
//		}
//	}
//	if (check2 == 1)
//	{
//		h = _multiply(_subtract(apex, cylindner.center), 2);
//		h_normal = _divide(h, _len(h));
//		w = _subtract(line.base, cylindner.center);
//		v = _divide(line.direction, _len(line.direction));
//
//		a = _dot(v, v) - pow(_dot(v, h_normal), 2);
//		b = 2 * (_dot(v, w) - _dot(v, h_normal) * _dot(w, h_normal));
//		c = _dot(w, w) - pow(_dot(w, h_normal), 2) - pow(cylindner.diameter / 2, 2);
//
//		root_term = pow(b, 2) - (4 * a * c);
//		if (root_term > 0)
//		{
//			t1 = (-b + sqrt(root_term)) / (2 * a);
//			t2 = (-b - sqrt(root_term)) / (2 * a);
//			if (t1 < 0 && t2 < 0)
//				return (FALSE);
//			if (t1 < t2 && t1 > 0)
//				t = t1;
//			else
//				t = t2;
//			point = _add(line.base, _multiply(v, t));
//			check = _dot(_subtract(point, cylindner.center), h);
//
//			if (0 <= check && check <= _len(h))
//			{
//				inter->point = point;
//				inter->normal = normal_tube_cylinder(inter->point, cylindner);
//				return (TRUE);
//			}
//		}
//	}
//	return (FALSE);
//}

double cylinder_side_intersect(t_cylindner *cy, t_intersect *inter);
void	get_proj_len(t_cylindner *cy, t_intersect *inter, double d1, double d2, double *pl1, double *pl2);
int get_distance(t_cylindner *cy, t_intersect *inter, double *d1, double *d2);
t_vector get_cap_inters(t_cylindner *cy, t_intersect *inter, int is_top);


double cylinder_side_intersect(t_cylindner *cy, t_intersect *inter)
{
	double d1;
	double d2;
	double pl1;
	double pl2;
	double h;
	double t;

	if (get_distance(cy, inter, &d1, &d2) == FALSE)
		return (FALSE);
	h = fabs(cy->height / 2);
	get_proj_len(cy, inter, d1, d2, &pl1, &pl2);
	if (pl1 < -h || pl1 > h)
		d1 = INFINITY;
	if (pl2 < -h || pl2 > h)
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
	t_vector normal;
	double 	 dot1;
	double	 dot2;
	t_vector abc;
	t_vector w;
	t_vector v;
	double 	 discr;
	double	 r;

	r = cy->diameter / 2;
	normal = _divide(cy->axis_direction, _len(cy->axis_direction));
	w = _subtract(inter->ray.base, cy->center);
	v = _divide(inter->ray.direction, _len(inter->ray.direction));
	dot1 = _dot(w, normal);
	dot2 = _dot(v, normal);
	abc.x = _dot(v, v) - (dot2 * dot2);
	abc.y = 2 * (_dot(v, w) - (dot2 * dot1));
	abc.z = _dot(w, w) - (dot1 * dot1) - (r * r);
	discr = (abc.y * abc.y) - (4 * abc.x * abc.z);
	if (discr < 0)
		return (FALSE);
	discr = sqrt(discr);
	*d1 = (-abc.y + discr) / (2 * abc.x);
	*d2 = (-abc.y - discr) / (2 * abc.x);
	if (isnan(*d1) || isnan(*d2))
		return (FALSE);
	return (TRUE);
}

<<<<<<< HEAD
	cylindner = *((t_cylindner*)object);
	apex = _add(cylindner.center, _multiply(cylindner.axis_direction, cylindner.height));
//	printf("apex: %f %f %f \n", apex.x, apex.y, apex.z);
	check2 = 1;
=======
int line_cylindner(void *object, t_line line, t_intersect *inter)
{
	(void)line;
	t_vector cap_inters;
	t_cylindner *cy;
	double		t;
>>>>>>> ba8a734a4379bc3550f7e446d20d5df303f0315c

	cy = ((t_cylindner*)object);
	t = cylinder_side_intersect(cy, inter);
	if (t == FALSE)
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
<<<<<<< HEAD
		h = _subtract(apex, cylindner.center);
		h_normal = _divide(h, _len(h));
		w = _subtract(line.base, cylindner.center);
		v = _divide(line.direction, _len(line.direction));

		a = _dot(v, v) - pow(_dot(v, h_normal), 2);
		b = 2 * (_dot(v, w) - _dot(v, h_normal) * _dot(w, h_normal));
		c = _dot(w, w) - pow(_dot(w, h_normal), 2) - pow(cylindner.diameter / 2, 2);

		root_term = pow(b, 2) - (4 * a * c);
		if (root_term > 0)
		{
			t1 = (-b + sqrt(root_term)) / (2 * a);
			t2 = (-b - sqrt(root_term)) / (2 * a);
			if (t1 < 0 && t2 < 0)
				return (FALSE);
			if (t1 < t2 && t1 > 0)
				t = t1;
			else
				t = t2;
			point = _add(line.base, _multiply(v, t));
			check = _dot(_subtract(point, cylindner.center), h);

			if (0 <= check && check <= cylindner.height)
			{
				inter->point = point;
				inter->normal = normal_tube_cylinder(inter->point, cylindner);
				return (TRUE);
			}
		}
=======
		cap.base = _add(cy->center, _multiply(normal, cy->height * -0.5));
		cap.v1 = _multiply(normal, -1);
>>>>>>> ba8a734a4379bc3550f7e446d20d5df303f0315c
	}
	inters.ray = inter->ray;
	if (intersection_line_plane(&cap, inters.ray, &inters) == FALSE)
		return ((t_vector){.x = INFINITY, .y = INFINITY, .z = INFINITY});
	inters.normal = cap.v1;
	if (_len(_subtract(inters.point, cap.base)) < cy->diameter / 2)
		return (inters.point);
	return ((t_vector){.x = INFINITY, .y = INFINITY, .z = INFINITY});
}
