/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:29:39 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/22 08:29:39 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	set_inter_vals(t_line *line, t_intersect *inter, t_sphere *sphere,
				t_var_dump *dump);

inline int	intersection_line_sphere(void *object, t_line line,
				t_intersect *inter)
{
	t_vector	oc;
	t_sphere	*sphere;
	t_var_dump	dump;

	sphere = (t_sphere *)object;
	line.dir = _divide(line.dir, _len(line.dir));
	oc = _subtract(line.base, sphere->center);
	dump.a = _dot(line.dir, line.dir);
	dump.b = 2 * _dot(oc, line.dir);
	dump.c = _dot(oc, oc) - pow(sphere->diameter / 2, 2);
	dump.discriminant = pow(dump.b, 2) - (4 * dump.a * dump.c);
	if (dump.discriminant >= 0)
	{
		dump.t1 = (-dump.b + sqrt(dump.discriminant)) / 2 * dump.a;
		dump.t2 = (-dump.b - sqrt(dump.discriminant)) / 2 * dump.a;
		if (dump.t1 < 0 && dump.t2 < 0)
			return (FALSE);
		if (dump.t1 < dump.t2 && dump.t1 > 0)
			dump.t = dump.t1;
		else
			dump.t = dump.t2;
		set_inter_vals(&line, inter, sphere, &dump);
		return (TRUE);
	}
	return (FALSE);
}

static void	set_inter_vals(t_line *line, t_intersect *inter,
			t_sphere *sphere, t_var_dump *dump)
{
	inter->point = _add(_multiply((*line).dir, (*dump).t), (*line).base);
	inter->normal = _subtract(inter->point, sphere->center);
	inter->normal = _divide(inter->normal, _len(inter->normal));
}
