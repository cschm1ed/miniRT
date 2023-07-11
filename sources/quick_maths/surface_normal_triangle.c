/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface_normal_triangle.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:03:55 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/11 11:03:55 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector normal_triangle(void *triangle, t_line line, t_vector point)
{
    t_triangle    *tr;
    t_vector      n;

    tr = ((t_list*)triangle)->content;
    n = _cross(_subtract(tr->B, tr->A), _subtract(tr->C, tr->A));
    (void)line;
    (void)point;
    return (n);
}
