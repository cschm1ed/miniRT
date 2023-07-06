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
	data.scene_filename = "./scenes/test.rt";


	if (init_data(argc, argv, &data) == FAILURE)
		return (1);
	printf("test segfault 1 \n");
	parsing(&data);
	printf("test segfault 2 \n");
	t_list *light_element = data.scene->light_lst;
	while (light_element != NULL)
	{

		t_light_source *light_source = (t_light_source *)light_element->content;

		printf("Center coordinates: (%f, %f, %f)\n", light_source->center.x, light_source->center.y, light_source->center.z);
		printf("Light ratio: %f\n", light_source->light_ratio);
		light_element = light_element->next;
	}
	loop_mlx(&data);
	return (0);
}

/*void	draw_image(t_mlx_data *ui, t_data *data)
{
	int 	x;
	int 	y;
	int 	color;
	t_line	camera;
	double 	a1;
	double 	a2;

	x = 0;
	y = 0;
	while (x < ui->width)
	{
		while (y < ui->height)
		{
			a1 = ((double)90 / ui->width * x) - 45;
			a2 = ((double)90 / ui->height * y) - 45;
			camera.base = ((t_camera*)(data->scene->camera))->center;
			camera.direction = angles_to_vector(a1, a2);
			color = trace_ray(data, camera, 0);
			if (color != 0)
				put_pixel(x, ui->height - y, color, data);
			color = 0;
			y ++;
		}
		y = 0;
		x ++;
	}
}*/

void	loop_mlx(t_data *data)
{
	t_mlx_data *ui;

	ui = &data->mlx_data;
	ui->height = HEIGHT;
	ui->width = WIDTH;
	//data->redraw = TRUE;
	printf("data->redraw before:%d\n", data->redraw);
    data->redraw = 0;
	printf("test segfault 3 \n");
	draw_image(ui, data);
	printf("test segfault 4 \n");
	mlx_put_image_to_window(ui->mlx, ui->win, ui->img, 0, 0);
	mlx_hook(ui->win, 17, 0, &free_stuff, data);
	mlx_key_hook(ui->win, &handle_keypress, data);
//	mlx_loop_hook(ui->mlx, &no_event, ui);
	mlx_loop(ui->mlx);
}
