/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:55 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/19 16:54:55 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_map(t_data *data)
{
	t_camera *camera;
	t_ambient_light *ambient_light;
	t_list *light_source;

	camera = data->scene->camera;
	ambient_light = data->scene->ambient_light;
	light_source = data->scene->light_lst;

	if (camera == NULL)
	{
		printf("error no camera\n");
		free_stuff(data);
		return (FAILURE);
	}
	if (ambient_light == NULL && light_source == NULL)
	{
		printf("error no ambient light or lightsource \n");
		free_stuff(data);
		return (FAILURE);
	}
	return (TRUE);
}
