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

int	handle_keypress(int keysym, t_data *data) {
	int events_movement[] = {XK_w, XK_a, XK_s, XK_d, XK_e, XK_r, XK_q, XK_y, XK_x, 0};
	int i;

	i = 0;
	while (events_movement[i])
	{
		if (keysym == events_movement[i++])
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
			//handle_movement(keysym, data);
			printf("moving\n");
			return (SUCCESS);
		}
	}

	if (keysym == XK_Escape)
		free_stuff(data);
	return (SUCCESS);
}

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
