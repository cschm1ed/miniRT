/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:49:59 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/21 09:49:59 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "minirt.h"

void		get_proj_len(t_cylindner *cy, t_intersect *inter, t_proj_len p, \
					t_vector dist);
int			get_distance(t_cylindner *cy, t_intersect *inter, double *d1, \
					double *d2);
t_vector	get_cap_inters(t_cylindner *cy, t_intersect *inter, int is_top);
int			intersection_line_sphere(void *object, t_line line, \
					t_intersect *result);
int			intersection_line_plane(void *object, t_line line, \
					t_intersect *inter);
int			line_cylindner(void *object, t_line line, t_intersect *inter);
int			intersection_line_triangle(void *object, t_line line, \
					t_intersect *result);

#endif
