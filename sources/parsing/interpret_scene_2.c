/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_scene_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:25:18 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/27 17:56:24 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	interpret_cylindner(char **str, t_data *data)
{
	t_list		*new_element;
	t_cylindner	*new_cy;

	new_cy = malloc(sizeof(t_cylindner));
	new_element = ft_lstnew(new_cy);
	new_element->diffuse = DIFFUSE + REFLECTIVENES;
	new_element->specular = SPECULAR + REFLECTIVENES;
	new_element->reflective = REFLECTIVENES;
	if (check_cylinder(new_cy, new_element, str) == FAILURE)
		return (FAILURE);
	new_cy->axis_dir = \
		_add(new_cy->axis_dir, (t_vector){EPSILON, EPSILON, EPSILON});
	new_cy->axis_dir = \
		_divide(new_cy->axis_dir, _len(new_cy->axis_dir));
	new_element->intersection = line_cylindner;
	new_element->get_colour = get_colour_cylindner;
	ft_lstadd_back(&data->scene->all_objs, new_element);
	return (SUCCESS);
}

int	interpret_triangle(char **str, t_data *data)
{
	t_list		*new_element;
	t_triangle	*new_triangle;

	new_triangle = malloc(sizeof(t_triangle));
	new_element = ft_lstnew(new_triangle);
	new_element->diffuse = DIFFUSE;
	new_element->specular = SPECULAR;
	new_element->reflective = REFLECTIVENES;
	if (check_triangle(new_triangle, new_element, str) == FAILURE)
		return (FAILURE);
	new_element->intersection = intersection_line_triangle;
	new_element->get_colour = get_colour_triangle;
	ft_lstadd_back(&data->scene->all_objs, new_element);
	return (SUCCESS);
}

int	set_dsr(t_list *obj, char **str, int i)
{
	if (get_single_double(str[i], &obj->diffuse) == FAILURE
		|| get_single_double(str[i + 1], &obj->specular) == FAILURE
		|| get_single_double(str[i + 2], &obj->reflective) == FAILURE)
		return (FAILURE);
	obj->diffuse = ft_atod(str[i]);
	obj->specular = ft_atod(str[i + 1]);
	obj->reflective = ft_atod(str[i + 2]);
	return (SUCCESS);
}
