/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:12:03 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:33 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memset() function writes len bytes of value c (converted to an 
// unsigned char) to the string b.

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i ++;
	}
	return (b);
}
