/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:31:45 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/24 15:35:13 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_scene	*init_scene(t_scene *scene)
{
	scene = malloc(sizeof(t_scene));
	if (scene == NULL)
		return (NULL);

	scene->camera = NULL;
	scene->light_lst = NULL;
	scene->ambient_light = NULL;
	scene->sphere_lst = NULL;
	scene->plane_lst = NULL;
	scene->cylindner_lst = NULL;
	scene->triangle_lst = NULL;
	scene->cone_lst = NULL;
	scene->all_objs = NULL;
	return (scene);
}

int	init_parsing(t_data *data)
{
	data->parsing = ft_calloc(sizeof(t_parsing), 8);
	if (data->parsing == NULL)
		return (perror("malloc"), FAILURE);
	data->parsing[0] = (t_parsing){"L", interpret_lightsource};
	data->parsing[1] = (t_parsing){"C", interpret_camera};
	data->parsing[2] = (t_parsing){"A", interpret_ambient_light};
	data->parsing[3] = (t_parsing){"pl", interpret_plane};
	data->parsing[4] = (t_parsing){"sp", interpret_sphere};
	data->parsing[5] = (t_parsing){"cy", interpret_cylindner};
    data->parsing[6] = (t_parsing){"tr", interpret_triangle};
	data->parsing[7] = (t_parsing){"co", interpret_cone};
	data->parsing[6] = (t_parsing){"tr", interpret_triangle};
//	data->parsing[7] = (t_parsing){"tr", interpret_cone};
	return (SUCCESS);
}

int	init_data(int argc, char **argv, t_data *data)
{
	t_mlx_data	*ui;

	ui = &data->mlx_data;
	if (argc != 2)
		return (ft_printf("Error\n", STDERR_FILENO), FAILURE);
	data->scene_filename = argv[1];
	ui->mlx = mlx_init();
	ui->img = mlx_new_image(ui->mlx, WIDTH, HEIGHT);
	ui->img_addr = mlx_get_data_addr(ui->img, &ui->bits_per_pixel,
			&ui->line_length, &ui->endian);
	if (init_parsing(data) == FAILURE)
		return (perror("malloc"), free(ui->mlx), FAILURE);
	return (SUCCESS);
}
