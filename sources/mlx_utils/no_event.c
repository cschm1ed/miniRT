/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:15:15 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/01 22:15:15 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	no_event(t_data *data)
{
	t_mlx_data *ui;

    ui = &data->mlx_data;
    expose_image(data);
	return (SUCCESS);
}
