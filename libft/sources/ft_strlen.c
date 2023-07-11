/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:10:08 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/14 17:13:36 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_strlen() returns the size of string 's'.

#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
    if (!s)
        return (0);
	while (s[i])
		i++;
	return (i);
}
