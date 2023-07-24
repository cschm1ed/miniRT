/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_object_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:17:37 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/19 18:17:37 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_cylinder(t_cylindner *new_cylindner, t_list *new_element, char **str)
{
	if (count_elements(str) != 6)
	{
		if (count_elements(str) == 9)
		{
			if (set_DSR(new_element, str, 6) == FAILURE)
				return (FAILURE);
		}
		else
			return (ft_printf("ERROR\nWrong number of elements in cylindner, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
	}
	if (get_center(str[1], &new_cylindner->center) == FAILURE
		|| get_center(str[2], &new_cylindner->axis_direction) == FAILURE
		|| get_single_double(str[3], &new_cylindner->diameter) == FAILURE
		|| get_single_double(str[4], &new_cylindner->height) == FAILURE
		|| get_trgb(str[5], &new_cylindner->colour) == FAILURE)
	{
		ft_printf("ERROR\ninvalid input cylinder\n");
		free(new_cylindner);
		return (FAILURE);
	}
	return (TRUE);
}

int	 check_triangle(t_triangle *new_triangle, t_list *new_element, char **str)
{
	if (count_elements(str) != 5)
	{
		if (count_elements(str) == 8)
		{
			if (set_DSR(new_element, str, 5) == FAILURE)
				return (FAILURE);
		}
		else
			return (ft_printf("ERROR\nWrong number of elements in triangle, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
	}
	if (get_center(str[1], &new_triangle->A) == FAILURE
		|| get_center(str[2], &new_triangle->B) == FAILURE
		|| get_center(str[3], &new_triangle->C) == FAILURE
		|| get_trgb(str[4], &new_triangle->colour) == FAILURE)
	{
		ft_printf("ERROR\ninvalid input triangle\n");
		return (free(new_triangle), FAILURE);
	}
	return (TRUE);
}
