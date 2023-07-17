/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_vector_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:30:28 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/16 15:30:34 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int _parallel(t_vector v1, t_vector v2)
{
	v1 = _divide(v1, _len(v1));
	v2 = _divide(v2, _len(v2));

	if (_dot(v1, v2) > 0.95)
		return (TRUE);
	return (FALSE);
}

int _opposite(t_vector v1, t_vector v2)
{
	v1 = _divide(v1, _len(v1));
	v2 = _divide(v2, _len(v2));

	if (_dot(v1, v2) < -0.95)
		return (TRUE);
	return (FALSE);
}