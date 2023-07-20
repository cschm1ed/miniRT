/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:15:15 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/20 13:38:05 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	no_event(t_data *data)
{
	expose_image(data);
	return (SUCCESS);
}
