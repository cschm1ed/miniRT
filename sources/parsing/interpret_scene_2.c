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
	new_cy->axis_direction = \
		_add(new_cy->axis_direction, (t_vector){EPSILON, EPSILON, EPSILON});
	new_cy->axis_direction = \
		_divide(new_cy->axis_direction, _len(new_cy->axis_direction));
	new_element->intersection = line_cylindner;
	new_element->get_colour = get_colour_cylindner;
	ft_lstadd_back(&data->scene->cylindner_lst, new_element);
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
	ft_lstadd_back(&data->scene->triangle_lst, new_element);
	return (SUCCESS);
}

int interpret_cone(char **str, t_data *data)
{
	t_list *new_element;
	t_cone *new_cone;

	new_cone = malloc(sizeof(t_cone));
	new_element = ft_lstnew(new_cone);
	new_element->diffuse = DIFFUSE;
	new_element->specular = SPECULAR;
	new_element->reflective = REFLECTIVENES;
	if (count_elements(str) != 6)
	{
		if (count_elements(str) == 8)
		{
			if (set_DSR(new_element, str, 6) == FAILURE)
				return (FAILURE);
		}
		else
			return (ft_printf("Wrong number of elements in cone, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
	}
	if (get_center(str[1], &new_cone->apex) == FAILURE
		|| get_center(str[2], &new_cone->axis_direction) == FAILURE
		|| get_single_double(str[3], &new_cone->opening_angle) == FAILURE
		|| get_single_double(str[4], &new_cone->height) == FAILURE
		|| get_trgb(str[5], &new_cone->colour) == FAILURE)
	{
		ft_printf("invalid input\n");
		return (free(new_cone), FAILURE);
	}
	new_element->intersection = line_cone;
	new_element->get_colour = get_colour_cone;
	ft_lstadd_back(&data->scene->cone_lst, new_element);
	printf("parsing cone ---> apex %f,%f,%f axis_direction: %f,%f,%f angle: %f height: %f colour: %d\n", new_cone->apex.x, new_cone->apex.y, new_cone->apex.z, new_cone->axis_direction.x,
		   new_cone->axis_direction.y, new_cone->axis_direction.z, new_cone->opening_angle, new_cone->height, new_cone->colour);
	new_cone->center = _add(new_cone->apex, _multiply(_multiply(new_cone->axis_direction, -1), new_cone->height));
	new_cone->radius = new_cone->height * tan(new_cone->opening_angle * DEG_TO_RAD / 2);
	new_cone->cos_angle = cos(new_cone->opening_angle * DEG_TO_RAD / 2);
	printf("center: %f,%f,%f radius: %f cos_angle: %f\n", new_cone->center.x, new_cone->center.y, new_cone->center.z, new_cone->radius, new_cone->cos_angle);
	printf("height mit vector berechnet: %f height ohne: %f\n", _len(_subtract(new_cone->apex, new_cone->center)), new_cone->height);

	return (SUCCESS);
}

int set_DSR(t_list *obj, char **str, int i)
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
