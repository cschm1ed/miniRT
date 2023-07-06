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

/*static void handle_movement(int keysym, t_data *data);*/

//void	draw_image_2(t_mlx_data *ui, t_data *data)
//{
//	int 	x;
//	int 	y;
//	int 	color;
//	t_line	camera;
//	t_plane	vp;
//
//	x = 0;
//	y = 0;
//	create_vision_plane(data, &vp);
//	camera.base = data->scene->camera->center;
//	printf("center.y in draw input = %f\n", data->scene->camera->center.y);
//	while (x < ui->width)
//	{
//		while (y < ui->height)
//		{
//			camera.direction = get_direction(data, vp, x, y);
//			color = trace_ray(data, camera, 0);
//
//			if (color != 0)
//			{
//				put_pixel(x, y, COLOR_BLUE, data);
//			}
//			color = 0;
//			y++;
//		}
//		y = 0;
//		x ++;
//	}
//	printf("neu gezeichnet\n");
//}

void	ft_reset_image(t_mlx_data *ui)
{
	int		i;
	int		j;
	char	*index;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			index = ui->img_addr + (j * ui->line_length
									   + i * ui->bits_per_pixel / 8);
			if (*(int *)index)
				*(int *)index = 0;
			j++;
		}
		i++;
	}
}

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
	draw_image(&data->mlx_data, data);
	mlx_put_image_to_window(data->mlx_data.mlx, data->mlx_data.win, data->mlx_data.img, 0, 0);
	return (SUCCESS);
}

//int	handle_keypress(int keysym, t_data *data) {
//	int events_movement[] = {XK_w, XK_a, XK_s, XK_d, XK_e, XK_r, XK_q, XK_y, XK_x, 0};
//	int i;
//
//	i = 0;
//	while (events_movement[i])
//	{
//		if (keysym == events_movement[i++])
//		{
//			t_camera *cam;
//
//			cam = data->scene->camera;
//			if (keysym == KEYBOARD_W)
//			{
//				cam->center.y += MOVE_RATE;
//				printf("test taste w\n");
//			}
//			else if (keysym == XK_s)
//				cam->center.x -= MOVE_RATE;
//			else if (keysym == XK_a)
//				cam->center.y -= MOVE_RATE;
//			else if (keysym == XK_d)
//				cam->center.y += MOVE_RATE;
//			data->redraw = TRUE;
//			//handle_movement(keysym, data);
//			printf("moving\n");
//			return (SUCCESS);
//		}
//	}
//
//	if (keysym == XK_Escape)
//		free_stuff(data);
//	return (SUCCESS);
//}

/*
static void handle_movement(int keysym, t_data *data)
{
	t_camera *cam;

	cam = data->scene->camera;
	if (keysym == XK_w)
		cam->center.y += MOVE_RATE;
	else if (keysym == XK_s)
		cam->center.x -= MOVE_RATE;
	else if (keysym == XK_a)
		cam->center.y -= MOVE_RATE;
	else if (keysym == XK_d)
		cam->center.y += MOVE_RATE;
	data->redraw = TRUE;
}
*/
