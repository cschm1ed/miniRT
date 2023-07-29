/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:46:57 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/19 17:46:57 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_light_source(t_light_source *new_light, char **str)
{
	if (count_elements(str) != 4)
	{
		ft_printf("ERROR\nWrong number of elements in light_source, there are %d elements in side\n", 1, count_elements(str));
		return (FAILURE);
	}
	if (get_center(str[1], &new_light->center) == FAILURE
		|| get_single_double(str[2], &new_light->light_ratio) == FAILURE
		|| get_trgb(str[3], &new_light->colour) == FAILURE)
	{
		free(new_light);
		ft_printf("ERROR\ninvalid input lightsource\n");
		return (FAILURE);
	}
	return (TRUE);
}

int	check_camera(t_camera *new_camera, char **str)
{
	if (count_elements(str) != 4)
	{
		ft_printf("ERROR\nWrong number of elements in camera, there are %d elements in side\n", 1, count_elements(str));
		free(new_camera);
		return (FAILURE);
	}
	else
	{
		if (get_center(str[1], &new_camera->center) == FAILURE
			|| get_center(str[2], &new_camera->vector) == FAILURE
			|| get_single_double(str[3], &new_camera->degrees) == FAILURE)
		{
			ft_printf("ERORR\ninvalid input camera\n");
			free(new_camera);
			return (FAILURE);
		}
	}
	return (TRUE);
}

int check_ambient_light(t_ambient_light *new_ambient_light, char **str)
{
	if (count_elements(str) != 3)
	{
		ft_printf("ERROR\nWrong number of elements in ambient light, there are %d elements in side\n", 1, count_elements(str));
		return (FAILURE);
	}
	else
	{
		if (get_single_double(str[1], &new_ambient_light->light_ratio) == FAILURE
			|| get_trgb(str[2], &new_ambient_light->colour) == FAILURE)
		{
		ft_printf("ERROR\ninvalid input ambient light\n");
		free(new_ambient_light);
		return (FAILURE);
		}
	}
	return (TRUE);
}

int check_plane(t_plane *new_plane, t_list *new_element, char **str)
{
	if (count_elements(str) != 4)
	{
		if (count_elements(str) == 7)
		{
			if (set_DSR(new_element, str, 4) == FAILURE)
				return (FAILURE);
		}
		else
			return (ft_printf("ERROR\nWrong number of elements in plane, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
	}
	if (get_center(str[1], &new_plane->base) == FAILURE
		|| get_center(str[2], &new_plane->v1) == FAILURE
		|| get_trgb(str[3], &new_plane->colour) == FAILURE)
	{
		ft_printf("ERROR\ninvalid input plane\n");
		free(new_plane);
		return (FAILURE);
	}
	return (TRUE);
}

int	check_sphere(t_sphere *new_sphere, t_list *new_element, char **str)
{
	if (count_elements(str) != 4)
	{
		if (count_elements(str) == 7)
		{
			if (set_DSR(new_element, str, 4) == FAILURE)
				return (FAILURE);
		}
		else
			return (ft_printf("ERROR\nWrong number of elements in sphere, there are %d elements in side\n", 1, count_elements(str)), FAILURE);
	}
	if (get_center(str[1], &new_sphere->center) == FAILURE
		|| get_single_double(str[2], &new_sphere->diameter) == FAILURE
		|| get_trgb(str[3], &new_sphere->colour) == FAILURE)
	{
		ft_printf("ERROR\ninvalid input sphere\n");
		free(new_sphere);
		return (FAILURE);
	}
	return (TRUE);
}
