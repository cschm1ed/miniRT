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
	if (init_data(argc, argv, &data) == FAILURE)
		return (1);
	if (parsing(&data) == FAILURE)
		return (1);
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

void	loop_mlx(t_data *data)
{
	t_mlx_data *ui;

	ui = &data->mlx_data;
	ui->height = HEIGHT;
	ui->width = WIDTH;
    data->redraw = 0;
    draw_image(data);
    ui->win = mlx_new_window(ui->mlx, WIDTH, HEIGHT, "miniRT");
    if (ui->win == NULL)
        free_stuff(data);
	mlx_put_image_to_window(ui->mlx, ui->win, ui->img, 0, 0);
	mlx_hook(ui->win, 17, 0, &free_stuff, data);
    mlx_hook(ui->win, 2, 0, &free_stuff, data);
    mlx_loop_hook(ui->mlx, &no_event, data);
	mlx_key_hook(ui->win, &handle_keypress, data);
	mlx_loop(ui->mlx);
}

void	print_vector(t_vector vec)
{
	printf("x: %f, y: %f, z %f\n", vec.x, vec.y, vec.z);
}
