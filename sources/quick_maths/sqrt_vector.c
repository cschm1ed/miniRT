/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:08 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/29 12:00:08 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector sqrt_vector(t_vector vector)
{
	t_vector out;

	out.x = sqrtf(vector.x);
	out.y = sqrtf(vector.y);
	out.z = sqrtf(vector.z);
	return (out);
}
