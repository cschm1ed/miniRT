/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:08:34 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/29 12:08:34 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector pow_vector(t_vector vector)
{
	t_vector out;

	out.x = pow(vector.x, 2);
	out.y = pow(vector.y, 2);
	out.z = pow(vector.z, 2);
	return (out);
}
