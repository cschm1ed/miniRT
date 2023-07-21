/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:23:10 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/20 13:29:25 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	put_pixel(int x, int y, int color, t_data *data)
{
	char	*index;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		index = data->mlx_data.img_addr + (y * data->mlx_data.line_length \
			+ x * data->mlx_data.bits_per_pixel / 8);
		*(int *)index = color;
	}
}
