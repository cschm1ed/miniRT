/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrtf_vector.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:00:08 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/29 12:00:08 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

inline t_vector	sqrtf_vector(t_vector vector)
{
	t_vector	out;

	out.x = sqrt(vector.x);
	out.y = sqrt(vector.y);
	out.z = sqrt(vector.z);
	return (out);
}
