/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_scene_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:25:18 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/19 18:25:18 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int interpret_cylindner(char **str, t_data *data)
{
	t_list *new_element;
	t_cylindner *new_cylindner;

	new_cylindner = malloc(sizeof(t_cylindner));
	new_element = ft_lstnew(new_cylindner);
	new_element->diffuse = DIFFUSE + REFLECTIVENES;
	new_element->specular = SPECULAR + REFLECTIVENES;
	new_element->reflective = REFLECTIVENES;
	if (check_cylinder(new_cylindner, new_element, str) == FAILURE)
		return (FAILURE);
	new_cylindner->axis_direction = _add(new_cylindner->axis_direction, (t_vector){EPSILON, EPSILON, EPSILON});
	new_cylindner->axis_direction = _divide(new_cylindner->axis_direction, _len(new_cylindner->axis_direction));
	new_element->intersection = line_cylindner;
	new_element->get_colour = get_colour_cylindner;
	ft_lstadd_back(&data->scene->cylindner_lst, new_element);
	printf("center: ");
	print_vector(new_cylindner->center);
	printf("axis: ");
	print_vector(new_cylindner->axis_direction);
	return (SUCCESS);
}

int interpret_triangle(char **str, t_data *data)
{
	t_list *new_element;
	t_triangle *new_triangle;

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

//int interpret_cone(char **str, t_data *data)
//{
//	t_list *new_element;
//	t_cone *new_cone;
//
//	new_cone = malloc(sizeof(t_cone));
//	new_element = ft_lstnew(new_cone);
//	new_element->diffuse = DIFFUSE;
//	new_element->specular = SPECULAR;
//	new_element->reflective = REFLECTIVENES;
//	if (count_elements(str) != 5)
//	{
//		if (count_elements(str) == 8)
//		{
//			if (set_DSR(new_element, str, 6) == FAILURE)
//				return (FAILURE);
//		}
//		else
//			return (ft_printf("Wrong number of elements in cone, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
//	}
//	if (get_center(str[1], &new_cone->apex) == FAILURE
//		|| get_center(str[2], &new_cone->axis_direction) == FAILURE
//		|| get_single_double(str[3], &new_cone->opening_angle) == FAILURE
//		|| get_trgb(str[4], &new_cone->colour) == FAILURE)
//	{
//		ft_printf("invalid input\n");
//		return (free(new_cone), FAILURE);
//	}
//	new_element->intersection = line_cone;
//	new_element->get_colour = get_colour_cone;
//	ft_lstadd_back(&data->scene->cone_lst, new_element);
//	printf("parsing cone ---> apex %f,%f,%f axis_direction: %f,%f,%f angle: %f colour: %d\n", new_cone->apex.x, new_cone->apex.y, new_cone->apex.z, new_cone->axis_direction.x,
//		   new_cone->axis_direction.y, new_cone->axis_direction.z, new_cone->opening_angle, new_cone->colour);
//	return (SUCCESS);
//}

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