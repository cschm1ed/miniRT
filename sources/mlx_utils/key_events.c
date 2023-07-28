/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:18:06 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/28 19:23:23 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	handle_keypress(int keysym, t_data *data)
{
	printf("moin i bins\n");
	// (void)data;
	// keysym = 1;
	if (keysym == KEYBOARD_Escape)
		free_stuff(data);
	return (SUCCESS);
}

int	expose_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx_data.mlx,
		data->mlx_data.win, data->mlx_data.img, 0, 0);
	return (SUCCESS);
}
