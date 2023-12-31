/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:18:06 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/29 13:07:46 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == KEYBOARD_ESCAPE)
		free_stuff(data);
	return (SUCCESS);
}

int	expose_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx_data.mlx,
		data->mlx_data.win, data->mlx_data.img, 0, 0);
	return (SUCCESS);
}
