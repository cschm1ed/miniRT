/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:35:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/20 13:15:34 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	free_stuff(t_data *data)
{
	mlx_destroy_image(data->mlx_data.mlx, data->mlx_data.img);
	free(data->mlx_data.mlx);
	if (data->scene->all_objs)
		ft_lstclear(&data->scene->all_objs, free);
	if (data->scene->light_lst)
		ft_lstclear(&data->scene->light_lst, free);
	if (data->scene->ambient_light)
		free(data->scene->ambient_light);
	if (data->scene->camera)
		free(data->scene->camera);
	if (data->scene)
		free(data->scene);
	exit(0);
	return (SUCCESS);
}
