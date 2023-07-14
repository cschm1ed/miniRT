/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normal_plane.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:29:56 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/26 17:29:56 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector normal_plane(void *plane, t_line line, t_vector point)
{
	t_plane	*pl;

    (void)point;
    pl = ((t_list*)plane)->content;
    if (pl->v1.x < 0 && line.direction.x < 0)
        pl->v1.x *= -1;
    if (pl->v1.y < 0 && line.direction.x < 0)
        pl->v1.y *= -1;
    if (pl->v1.z < 0 && line.direction.z < 0)
        pl->v1.z *= -1;
	return (pl->v1);
}
