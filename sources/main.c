/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:23:17 by nristorc          #+#    #+#             */
/*   Updated: 2023/06/18 19:57:58 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.scene = init_scene(data.scene);
//	if (scene == NULL)
//		return (1);
	data.scene_filename = "./scenes/test.rt";


	if (init_data(argc, argv, &data) == FAILURE)
		return (1);/*
	parsing(&data);
	t_list *light_element = data.scene->light_lst;
	while (light_element != NULL)
	{

		t_light_source *light_source = (t_light_source *)light_element->content;

		printf("Center coordinates: (%f, %f, %f)\n", light_source->center.x, light_source->center.y, light_source->center.z);
		printf("Light ratio: %f\n", light_source->light_ratio);
		light_element = light_element->next;
	}*/
	loop_mlx(&data);
	return (0);
}

void	draw_image(t_mlx_data *ui, t_data *data)
{
	int x;
	int y;
	float a1;
	float a2;
	t_line		line;
	t_sphere	sphere;
	t_plane		plane;
	t_vector 	tmp;

	line.base = (t_vector){0, 0, 0};
	plane.base = (t_vector){0, 5, 0};
	plane.v1 = (t_vector){1, 0, 0};
	plane.v2 = (t_vector){1, 0, 1};
	sphere.center = (t_vector){0, -3, -1};
	sphere.diameter = 1;
	x = 0;
	y = 0;
	while (x < ui->width)
	{
		while (y < ui->height)
		{
			a1 = ((float)90 / ui->width * x) - 45;
			a2 = ((float)90 / ui->height * y) - 45;
			line.direction = angles_to_vector(a1, a2);
			if (intersection_line_sphere(sphere, line, &tmp))
				put_pixel(x, y, trgb(0, 100, 20, 200), data);
			else if (interesction_line_plane(plane, line, &tmp))
				put_pixel(x, y, trgb(0, 20, 150 , 50), data);
			y ++;
		}
		y = 0;
		x ++;
	}
}

void	loop_mlx(t_data *data)
{
	t_mlx_data *ui;

	ui = &data->mlx_data;
	ui->height = 1000;
	ui->width = 1000;
	draw_image(ui, data);
	mlx_put_image_to_window(ui->mlx, ui->win, ui->img, 0, 0);
	mlx_hook(ui->win, 17, 0, &free_stuff, data);
	mlx_loop(ui->mlx);
}
