/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:31:45 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:48:27 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	init_parsing(t_data *data)
{
	data->parsing = ft_calloc(sizeof(t_parsing), 7);
	if (data->parsing == NULL)
		return (perror("malloc"), FAILURE);
	data->parsing[0] = (t_parsing){"L", interpret_lightsource};
	return (SUCCESS);
}

int	init_data(int argc, char **argv, t_data *data)
{
	t_mlx_data *ui;

	ui = &data->mlx_data;
	if (argc != 2)
		return (ft_printf("Error\n", STDERR_FILENO), FAILURE);
	data->scene_filename = argv[1];
	ui->mlx = mlx_init();
	ui->win = mlx_new_window(ui->mlx, WIDTH, HEIGHT, "miniRT");
	if (ui->win == NULL)
		return (perror("malloc"), free(ui->mlx), FAILURE);
	ui->img = mlx_new_image(ui->mlx, WIDTH, HEIGHT);
	ui->img_addr = mlx_get_data_addr(ui->img, &ui->bits_per_pixel,
					&ui->line_length, &ui->endian);
	if (init_parsing(data) == FAILURE)
		return (perror("malloc"), free(ui->mlx), FAILURE);
	return (SUCCESS);
}
