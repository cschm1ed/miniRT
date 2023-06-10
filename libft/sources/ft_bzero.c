/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:14:59 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:28 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_bzero() function writes n zeroed bytes to the string s.
//If n is zero, ft_bzero() does nothing.

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*a;

	a = (char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
	return ;
}
