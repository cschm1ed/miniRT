/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:18:06 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/23 19:18:06 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	handle_keypress(int keysym, t_data *data)
{
	t_camera *cam;
	t_mlx_data *ui;

	ui = &data->mlx_data;
	ui->height = HEIGHT;
	ui->width = WIDTH;

	cam = data->scene->camera;
	if (keysym == KEYBOARD_W)
		cam->center.y += MOVE_RATE;
	else if (keysym == KEYBOARD_S)
		cam->center.y -= MOVE_RATE;
	else if (keysym == KEYBOARD_D)
		cam->center.x -= MOVE_RATE;
	else if (keysym == KEYBOARD_A)
		cam->center.x += MOVE_RATE;
	else if (keysym == KEYBOARD_1)
		cam->center.z += MOVE_RATE;
	else if (keysym == KEYBOARD_2)
		cam->center.z -= MOVE_RATE;

	else if (keysym == XK_Escape)
		free_stuff(data);
    draw_image(data);
	mlx_put_image_to_window(data->mlx_data.mlx, data->mlx_data.win, data->mlx_data.img, 0, 0);
	return (SUCCESS);
}

int expose_image(t_data *data)
{
    mlx_put_image_to_window(data->mlx_data.mlx,
        data->mlx_data.win, data->mlx_data.img, 0, 0);
    return (SUCCESS);
}
